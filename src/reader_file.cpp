#include "../include/header.h"

char ** generate_grid(int line, int column, std::ifstream& file);

Life reader_file(char* filename, char * output){

  int line, column;
  char type;
  std::ifstream file (filename);
  char ** matrix;

  if(file.is_open()){
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

  return obj;
}

char ** generate_grid(int line, int column, std::ifstream& file){

  char ** matrix;
  matrix = new char * [line];
  for(auto i(0); i < line; i++){
    matrix[i] = new char [column];
    for(auto j(0); j < column; j++){
      file >> matrix[i][j];
    }
  }

  return matrix;
}
