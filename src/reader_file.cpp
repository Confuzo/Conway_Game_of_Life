#include "../include/header.h"

Life reader_file(){

  int line, column;
  char type;
  std::ifstream file ("../data/cfg1.dat");

  char ** matriz;
  if(file.is_open()){
    file >> line;
    file >> column;
    file >> type;

    matriz = new char * [line];
    for(auto i(0); i < line; i++){
      matriz[i] = new char [column];
      for(auto j(0); j < column; j++){
        file >> matriz[i][j];
      }
    }
  }else if(file.is_open() == NULL){
    std::cout<< "Wrong syntaxe!";
  }

  Life obj {line,column};
  obj.set_alive(matriz);
  //esse stoi serve pra converter de string pra int
  //return Life(std::stoi(line),std::stoi(column));
  return obj;
}
