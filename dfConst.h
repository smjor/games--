#define R 20
#define C 20
#define COUNT 5
#define RED 'x'
#define BLUE '*'
#define JUDGE 9 
//#define DEBUGM

struct CountPerDirectionChess{
	// array[0]-count;array[1]-up of chess ;array[2] - down of chess;
	int Count_horizotal[3];
	int Count_leftSlash[3];
	int Count_vertical[3];
	int Count_rightSlash[3];
}cpdc={
	{
		{
			1,0,0
		},
		{
			1,0,0
		},
		{
			1,0,0
		},
	}
};
 




