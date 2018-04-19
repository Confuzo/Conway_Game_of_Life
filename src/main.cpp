#include "../include/header.h"

int main(int *argv char**argv){

  Life obj = reader_file();
  obj.print();
  //obj.set_alive();
  char *arqentrada,*arqsaida;

  for(auto var = 0; argv[var] != NULL;++var){
  		*arqentrada = new argv[var];
  		strcpy(arqentrada, argv[var +1]);
  		++var;
  			
  		*arqsaida = new argv[var];
  		strcpy(arqsaida,argv[var+1]);
  }
  return 0;
}
