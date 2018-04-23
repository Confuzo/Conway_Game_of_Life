#include "../include/header.h" /*<-- como parte da identação,temos o funcionamento das funções assinadas no "life.h"  -->*/

Life::Life(int Lin, int Col){ /*<-- variaveis que serviram para dar o tamanho das iterações -->*/

        nLin = Lin;
        nCol = Col;
}

Life::Life(){}

void Life::set_alive(char **  matrix, char * output){ 
      this->matrix = matrix;
      std::ofstream outfile (output, std::ios::app); /*<-- função geradora de celulas utilizando a ofstream e -->*/
      												/*<-- iterações nas colunas e linhas da matriz -->*/
      outfile << "\nThe "<< count <<"° conjecture of the life generation is: \n";
         for(auto i(1); i< nLin+1; i++){
           for(auto j(1); j < nCol+1; j++){
             outfile << matrix[i][j];
           }
           outfile << "\n";
      	}

        outfile.close();
}

void Life::update(){ /*<-- atualização de novas gerações -->*/

  int alive, survive;
  for (auto i(1); i < nLin + 1; i++){
    for (auto j(1); j < nCol + 1; j++){
      alive = 0;
      survive = 0;
      if(matrix[i][j] == '.'){ /*<-- a produção é baseada no que está envolta do "." ,  -->*/
        if(matrix[i-1][j-1] == type){ /*<--criando células vivas ou mortas dependendo das condições -->*/
          alive++;
        }
        if(matrix[i-1][j] == type){
          alive++;
        }
        if(matrix[i-1][j+1] == type){
          alive++;
        }
        if(matrix[i][j-1] == type){
          alive++;
        }
        if(matrix[i][j+1] == type){
          alive++;
        }
        if(matrix[i+1][j-1] == type){
          alive++;
        }
        if(matrix[i+1][j] == type){
          alive++;
        }
        if(matrix[i+1][j+1] == type){
          alive++;
        }

        if(alive == 3){
          aux_matrix[i][j] = type;
        }
      }else{

        if(matrix[i-1][j-1] == type){
          survive++;
        }
        if(matrix[i-1][j] == type){
          survive++;
        }
        if(matrix[i-1][j+1] == type){
          survive++;
        }
        if(matrix[i][j-1] == type){
          survive++;
        }
        if(matrix[i][j+1] == type){
          survive++;
        }
        if(matrix[i+1][j-1] == type){
          survive++;
        }
        if(matrix[i+1][j] == type){
          survive++;
        }
        if(matrix[i+1][j+1] == type){
          survive++;
        }

        if(survive != 3 and survive != 2){ /*<-- aqui ocorre a morte caso tenha mais de duas células vivas envolta -->*/
          aux_matrix[i][j] = '.';
        }
      }
    }
  }

  count++;

}

void Life::print(){ /*<-- imprensão da matrizes -->*/
    std::cout << "\nThe "<< count <<"° conjecture of the life generation is: \n";
       for(auto i(1); i< nLin+1; i++){
         for(auto j(1); j < nCol+1; j++){
           std::cout << matrix[i][j];
         }
         std::cout << "\n";
    	}
      copy();
}

void Life::copy(){
  aux_matrix = new char * [nLin + 2];
  for(auto i(0); i < nLin +2; i++){
    aux_matrix[i] = new char [nCol + 2];
    for(auto j(0); j < nCol + 2; j++){
      aux_matrix[i][j] = (matrix[i][j]);
    }
  }

}
bool Life::stable(){ /*<-- verifiação de se a matriz está estabelecida -->*/
  for(auto i(0); i < nLin + 2; i++)
		for(auto j(0); j < nCol + 2; j++)
			if(matrix[i][j] != aux_matrix[i][j]){
      			return false;
			}
  return true;
}

bool Life::extinct(){ /*<-- verificação para extinção -->*/
  for(auto i(0); i < nLin + 2; i++)
		for(auto j(0); j < nCol + 2; j++)
			if(matrix[i][j] == type){
      			return false;
			}
  return true;
}
