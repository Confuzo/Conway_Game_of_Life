#include "../include/header.h"

int main(int *argc,char *argv[]){

  Life obj = reader_file(argv[1]);
  obj.print();
  //obj.set_alive();
  //std::cout << argv[2] << std::endl;

  return 0;
}
