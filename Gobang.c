#include<stdio.h>
#define R 20
#define C 20
#define COUNT 5
#define RED 'x'
#define BLUE '*'

void main(){
	void init(char (*arr)[C]);
	void scanEle(char (*arr)[C],char flag);
	void drawPic(char (*arr)[C]);
	int checkWhoWin(char (*arr)[C],char flag,int x,int y);
	char str[R][C];	
	init(str);	
};

void init(char (*arr)[C]){	
	// initial page 
	int j,i = 0;
	while(i< R){
		for( j = 0;j < C;j ++){	
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
	scanEle(arr,RED);
} 

void drawPic(char (*arr)[C]){
	// output picture of per change
	int j,i = 0;
	while(i < R){
		for( j = 0;j < C;j ++){
			if(i == 0 || j == 0){
				printf("%4i",*(*(arr + i)+j));	
			}else{
				printf("%4c",*(*(arr + i)+j));
			}				
			if(j + 1 == C){
				printf("\n");
			}	
		}
		i++;				
	}	
}

void scanEle(char (*arr)[C],char flag){
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
		if(flag == RED){
			scanEle(arr,BLUE);
		}else{
			scanEle(arr,RED);
		}
	}
		
		
	
}

int checkWhoWin(char (*arr)[C],char flag,int x,int y){
	int FrwdCk(char (*arr)[C],char flag,char f , int x, int y);
	// 00-invalid;01-success;02-continue;
	
	// check invalid input 
	if(*(*(arr + x)+y) == RED || *(*(arr + x)+y) == BLUE
		 || x == 0 || y == 0 || x == R || y == C){
		printf("invalid input please input once again \n");		
		return 00;
	}
	// check in row¡¢colum or diagonal of who have five chess; 

	
	// not about range;
	
	if(FrwdCk(arr,flag,'u' , x, y) == 5){
		return 01;
	};
	
	/*if(row == COUNT || col == COUNT || dig == COUNT){
		printf("%d,win!",flag);	
		return 01;
	}*/	
	return 02;
	
}

int FrwdCk(char (*arr)[C],char flag,char f , int x, int y){
		int i,count = 0;
		i = 1;			
		for(;i < COUNT;i++){
			if(f == 'lu'){				
				// left up
				if(0 <=x - i && 0 <=y - i && *(*(arr + x -i) + y - i) == flag){
					 count ++;
				}else{
					break;
				}			
			}
			if(f == 'u'){				
				// up
				if(0 <=x - i && *(*(arr + x -i) + y) == flag){
					 count ++;
				}else{
					break;
				}			
			}
			if(f == 'ru'){				
				// right up
				if(COUNT <=x + i && COUNT <=y + i && *(*(arr + x + i) + y + i) == flag){
					 count ++;
				}else{
					break;
				}			
			}
			if(f == 'r'){				
				// up
				if(COUNT <= y + i && *(*(arr + x) + y + i) == flag){
					 count ++;
				}else{
					break;
				}			
			}
		}
		return count;
		
	} 


