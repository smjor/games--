#include<stdio.h>
#define r 20
#define c 20
#define count 5
#define red 'x'
#define blue '*'

void main(){
	void init(char (*arr)[c]);
	void scanEle(char (*arr)[c],char flag);
	void drawPic(char (*arr)[c]);
	int checkWhoWin(char (*arr)[c],char flag,int x,int y);
	char str[r][c];	
	init(str);	
};

void init(char (*arr)[c]){	
	// initial page 
	int j,i = 0;
	while(i< r){
		for( j = 0;j < c;j ++){	
			if(i == 0){
				*(*(arr + i)+j) = j;
			}else{
				*(*(arr + i)+j) = '.';	
			}					
		}
		if(i != 0){
			*(*(arr + i)+0) = i;
		}			
		i++;
	}	
	drawPic(arr);
	// input directive
	scanEle(arr,red);
} 

void drawPic(char (*arr)[c]){
	// output picture of per change
	int j,i = 0;
	while(i < r){
		for( j = 0;j < c;j ++){
			if(i == 0 || j == 0){
				printf("%4i",*(*(arr + i)+j));	
			}else{
				printf("%4c",*(*(arr + i)+j));
			}				
			if(j + 1 == c){
				printf("\n");
			}	
		}
		i++;				
	}	
}

void scanEle(char (*arr)[c],char flag){
	printf("Please input directive(x,y):");
	int x,y;
	scanf("%d,%d",&x,&y);
	if(checkWhoWin(arr,flag,x,y) == 00){
		scanEle(arr,flag);
		return;
	}
 	if(checkWhoWin(arr,flag,x,y) == 01){
		char tell;
		printf("Are you want continue(y/n):");
		scanf("%d",tell);
		tell == 'y'? init(arr) : "";
		return;
	}
	if(checkWhoWin(arr,flag,x,y) == 02){
		*(*(arr + x)+y) = flag;	
		system("cls");	
		drawPic(arr);
		if(flag == red){
			scanEle(arr,blue);
		}else{
			scanEle(arr,red);
		}
	}
		
		
	
}

int checkWhoWin(char (*arr)[c],char flag,int x,int y){
	// 00-invalid;01-success;02-continue;
	
	// check invalid input 
	if(*(*(arr + x)+y) == red || *(*(arr + x)+y) == blue
		 || x == 0 || y == 0 || x == r || y == c){
		printf("invalid input please input once again \n");		
		return 00;
	}
	// check in row¡¢colum or diagonal of who have five chess; 
	int i,row,col,dig;
	row = 0;col = 0;dig = 0;
	// not about range;
	int startx,starty,endx,endy;
	startx = x + 1 - count > 0 ? x + 1 - count : 1;
 	starty = y + 1 - count > 0 ? y + 1 - count : 1;
 	endx = x -1 +count < row ? x -1 +count > row : row - 1;
  	endy = y -1 +count < row ? y -1 +count > row : row - 1;
  	
  	while(startx <= endx){
		for(i = starty;i < endy; i ++){
			if(*(*(arr + startx) +i) == flag){
				// count row
				row ++;
			}
			if(*(*(arr + startx ) + ) == flag){
				col ++;
			}
			if(*(*(arr + x + i) + y +i) == flag ){
				dig ++;
			}
		}  	
		startx ++;
  	}
	
	if(row == count || col == count || dig == count){
		printf("%d,win!",flag);	
		return 01;
	}	
	return 02;
}




