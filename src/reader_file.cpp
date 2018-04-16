#include "../include/header.h"

Life reader_file(){

  int line, column;
  std::ifstream file ("../data/cfg1.dat");

  if(file.is_open()){
    file >> line;
    file >> column;
  }

  //esse stoi serve pra converter de string pra int
  //return Life(std::stoi(line),std::stoi(column));
  return Life(line,column);
}
