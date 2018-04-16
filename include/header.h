#define header
#include <iostream>
#include <fstream>

class Life{
  private:
    int nLin;
    int nCol;
  public:
    Life(int Lin, int Col){

        nLin = Lin;
        nCol = Col;
    }
    void print(){
       std::cout<< nLin << " " << nCol << std::endl;
    }
};

Life reader_file();
