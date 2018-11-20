#define R 20
#define C 20
#define COUNT 5
#define RED 'x'
#define BLUE '*'
#define JUDGE 4
//#define DEBUGM


struct cacheChessInfo{	
	// Here cache location of chess; 
	char upName[3];
	char dName[3];
	// count chess;		
	int countUp;
	int countD;	
	// How many chess;
	int countAmongUp;
	int countAmongD;
}cci_struct[4];
