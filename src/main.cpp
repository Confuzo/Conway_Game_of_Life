#include "../include/header.h"
/**
* @file main.cpp
* @details Na main teremos a execução do Conway Game of life,tal que teremos aplicação das regras do jogos
* utilizando dentro do laço e dos testes dentro dele.
* @param Como parâmetro temos dado baseado no que é dado na linha de comando
* @return Retorna a matriz contruida pelas funções a cada geração enquanto estiver de acordo com as regras do jogo
*/
int main(int *argc,char *argv[]){

  Life obj;
  char key;
  if(argv[2] != NULL){
    obj = reader_file(argv[1], argv[2]); 
  }else{
    obj = reader_file(argv[1],"../data/output.txt");
  }
  while(true){ 

      obj.print();
      std::cout << "Do you wish continue with the generation?\n (y,n)?\n";
      std::cin >> key;
      if(key != 'y' and key !='Y'){
        return -1;
      }
      obj.update();
      if(obj.extinct()){
          std::cout << "Extinct configuration, ending software...\n";
          obj.set_alive(obj.aux_matrix, argv[2]);
          std::exit(0);
      }
      if(obj.stable()){
        std::cout << "Stable configuration, ending software...\n";
        obj.set_alive(obj.aux_matrix, argv[2]);
        std::exit(0);
      }

      obj.set_alive(obj.aux_matrix, argv[2]);
  }


  return 0;
}
