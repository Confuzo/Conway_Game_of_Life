#include "../include/header.h"

Life::Life(int Lin, int Col){

        nLin = Lin;
        nCol = Col;
}

Life::Life(){}

void Life::set_alive(char **  matrix, char * output){
      this->matrix = matrix;
      std::ofstream outfile (output, std::ios::app);

      outfile << "\nThe "<< count <<"° conjecture of the life generation is: \n";
         for(auto i(1); i< nLin+1; i++){
           for(auto j(1); j < nCol+1; j++){
             outfile << matrix[i][j];
           }
           outfile << "\n";
      	}

        outfile.close();
}

void Life::update(){

  int alive, survive;
  for (auto i(1); i < nLin + 1; i++){
    for (auto j(1); j < nCol + 1; j++){
      alive = 0;
      survive = 0;
      if(matrix[i][j] == '.'){
        if(matrix[i-1][j-1] == type){
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
        std::cout << alive;
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
        std::cout << survive;
        if(survive != 3 and survive != 2){
          aux_matrix[i][j] = '.';
        }
      }
    }
  }

  count++;

}

void Life::print(){
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
bool Life::stable(){
      return true;
}

bool Life::extinct(){
      return true;
}
