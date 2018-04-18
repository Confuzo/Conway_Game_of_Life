#define header
#include <iostream>
#include <fstream>

class Life{
  private:
    int nLin;
    int nCol;
    char ** matriz;
  public:
    Life(int Lin, int Col){

        nLin = Lin;
        nCol = Col;
    }
    char type;
    //we must define how to parse informtaion to here
    void set_alive(char **  entry){
      matriz = entry;
    }
    void update(){

    }
    void print(){
      std::cout << "\nThe currrent conjecture of the life generation is: \n";
       for(auto i(0); i< nLin; i++){
         for(auto j(0); j < nCol; j++){
           std::cout << matriz[i][j];
         }
         std::cout << "\n";
       }
    }
    bool stable(){
      return true;
    }
    bool extinct(){
      return true;
    }
};

Life reader_file();
