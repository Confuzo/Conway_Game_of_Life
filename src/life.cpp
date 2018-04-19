#include "life.h"

Life::Life(int Lin, int Col){

        nLin = Lin;
        nCol = Col;
    }

void Life::set_alive(char **  entry){
      matriz = entry;
    }
    
void Life::update(){}
    
void Life::print(){
    std::cout << "\nThe currrent conjecture of the life generation is: \n";
       for(auto i(0); i< nLin; i++){
         for(auto j(0); j < nCol; j++){
           std::cout << matriz[i][j];
         }
         std::cout << "\n";
    	}
}
    
bool Life::stable(){
      return true;
}
    
bool Life::extinct(){
      return true;
}

Life::reader_file(char*argv){}