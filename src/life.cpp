// /<-- @file life.h -->/
#include "../include/header.h"

Life::Life(int Lin, int Col){

        nLin = Lin;
        nCol = Col;
}

Life::Life(){}

void Life::set_alive(char **  matrix, char * output){
      this->matrix = matrix;
      std::ofstream outfile (output);

      outfile << "\nThe "<< count <<"° conjecture of the life generation is: \n";
         for(auto i(0); i< nLin; i++){
           for(auto j(0); j < nCol; j++){
             outfile << matrix[i][j];
             auto matrix_one = matrix[0][0];
           }
           outfile << "\n";
      	}

        outfile.close();
}

void Life::update(){


}

void Life::print(){
    std::cout << "\nThe "<< count <<"° conjecture of the life generation is: \n";
       for(auto i(0); i< nLin; i++){
         for(auto j(0); j < nCol; j++){
           std::cout << matrix[i][j];
         }
         std::cout << "\n";
    	}
}

bool Life::stable( char** matrix_one, char **matrix){
	for(auto i{0}; i < nLin; i++)
		for(auto j{0}; j < nCol ; j++)
			if(matrix_one[i][j] == matrix[i][j]){
      			return false;
			}
	return true;
}

bool Life::extinct(){
      return true;
}
