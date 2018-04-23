/**
 @details No life.h temos a definição dela que está composta da classe Life cujo a parte privade tem as variaveis necessárias para iterações 
 e funcionamento das funções assim como as suas assinaturas.
*/
#define life.h 
class Life{
 private:
		int nLin; 
		int nCol; 
		int count = 1;
		char ** matrix;
	public:
    char ** aux_matrix;
		Life(int Lin, int Col);
		Life();
  	char type;
    void set_alive(char **  matrix, char * output); 
    void update(); 
  	void print(); 
    void copy();
  	bool stable(); 
		bool extinct(); 

};
