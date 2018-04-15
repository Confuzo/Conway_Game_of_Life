#define header
#include <iostream>

class Life{
  private:
    int nLin;
    int nCol;
  public:
    Life(int Lin, int Col){

        nLin = Lin;
        nCol = Col;
    }
    void printn(){
       std::cout<< nLin << " " << nCol << std::endl;
    }
};
