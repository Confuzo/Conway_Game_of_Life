#define life.h /*<-- definindo a classe life.h com as assinaturas de todas as funções presente nela -->*/
class Life{
 private:
		int nLin; /*<-- dentro da parte privada temos o numero de colunas e linhas que seram usadas para gerar -->*/ 
		int nCol; /*<-- a matriz do Conway Game of Life -->*/
		int count = 1;
		char ** matrix;
	public:
    char ** aux_matrix;
		Life(int Lin, int Col);
		Life();
  	char type;
    void set_alive(char **  matrix, char * output); /*<-- set alive será os atributos para as celulas da matriz -->*/
    void update(); /*<-- update servirá para atualizar a matriz,ou seja,a troca de gração -->*/
  	void print(); /*<-- irá imprimir as novas etapas -->*/
    void copy();
  	bool stable(); /*<-- esta função serve para verificar se vai haver estabilidade ou não das gerações -->*/
		bool extinct(); /*<-- já está,para verificar a extinção -->*/

};
