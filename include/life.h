#ifndef life.h
#define life.h
class Life{
		int nLin;
		int nCol;
		char ** matriz;
	public:
		Life(int Lin, int Col);
    	char type;
    	void set_alive(char **  entry);
    	void update();
    	void print();
    	bool stable();
    	bool extinct();

};

Life reader_file(char*argv);
#endif