#include "../include/header.h"

char ** generate_grid(int line, int column, std::ifstream& file);

Life reader_file(char* filename, char * output){ // função leitora do arquivo que apresenta a matriz com as celulas

  int line, column;
  char type;
  std::ifstream file (filename);
  char ** matrix;

  if(file.is_open()){ // verificação de que o documento está certo e os parâmetros passados pela linha de comando também estão
    file >> line;
    file >> column;
    file >> type;

    matrix = generate_grid(line, column, file);

  }else{
    std::cout<< "Wrong syntaxe!\n";
    std::exit(0);
  }

  Life obj {line,column};
  obj.set_alive(matrix, output);
  obj.type = type;

  return obj;
}

char ** generate_grid(int line, int column, std::ifstream& file){ 

  char ** matrix;
  matrix = new char * [line+2];
  for(auto i(0); i < line+2; i++){
    matrix[i] = new char [column+2];
    for(auto j(0); j < column+2; j++){
      if(i==0 or i==line+1 or j==0 or j==column+1){
        matrix[i][j] = '/';
      }else{
        file >> matrix[i][j];
      }
    }
  }

  return matrix;
}
