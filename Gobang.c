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
	int x,y,result;
	scanf("%d,%d",&x,&y);


		
	result = checkWhoWin(arr,flag,x,y);
	if(result == 00){
		scanEle(arr,flag);
		return;
	}
 	if(result == 01){		
		printf("Are you want continue(yes/no):");
		char tell[3];
		scanf("%s",&tell); 
		
		strcmp(tell,"yes") == 0? init(arr) : "";
		return;
	}
	if(result == 02){
		*(*(arr + y)+x) = flag;	
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
	int FrwdCk(char (*arr)[C],char flag,char f[2] , int x, int y);
	int dwCk(char (*arr)[C],char flag,char f[2] , int x, int y);
	// 00-invalid;01-success;02-continue;
	
	// check invalid input 
	if(*(*(arr + y)+x) == RED || *(*(arr + y)+x) == BLUE
		 || x == 0 || y == 0 || x == R || y == C){
		printf("invalid input please input once again \n");		
		return 00;
	}
	// check in row¡¢colum or diagonal of who have five chess; 

	
	// not about range;	

	//printf("%d\n",dwCk(arr,flag,"rd" , x, y));	
	if(dwCk(arr,flag,"rd" , x, y) >= COUNT || 
		dwCk(arr,flag,"d" , x, y) >= COUNT ||
			dwCk(arr,flag,"ld" , x, y) >= COUNT ||
				dwCk(arr,flag,"l" , x, y) >= COUNT){
		printf("%c,win!",flag);	
		return 01;
	}
	return 02;
	
}

int dwCk(char (*arr)[C],char flag,char f[2] , int x, int y){	
	
	// include self;
	int i,count = 1;
	for(i= 1;i < COUNT;i++){		
			if(strcmp(f,"rd") == 0){				
				// right down
				if(x + i <= C && y + i < R && *(*(arr + y + i) + x + i) == flag){
					 count ++;
				}else{
					count = count + FrwdCk(arr,flag,"lu", x, y);
					break;
				}			
			}
			if(strcmp(f,"d") == 0){				
				// down
				if(y + i <= R && *(*(arr + y + i) + x) == flag){
					 count ++;
				}else{
					count = count + FrwdCk(arr,flag,"u", x, y);
					break;
				}			
			}
			if(strcmp(f,"ld") == 0){	
						
				// left down
				if(R <=y + i && 0 <=x - i && *(*(arr + y + i) + x - i) == flag){
					 count ++;
				}else{
					count = count + FrwdCk(arr,flag,"ru", x, y);
					break;
				}			
			}
			if(strcmp(f,"l") == 0){				
				// left
				if(0 <= x - i && *(*(arr + y) + x - i) == flag){
					 count ++;
				}else{
					count = count + FrwdCk(arr,flag,"r", x, y);
					break;
				}			
			}
		}
		return count;
}

int FrwdCk(char (*arr)[C],char flag,char f[2] , int x, int y){
		// No include self
		int i,count = 0;
			
		for(i= 1;i < COUNT;i++){
		
			if(strcmp(f,"lu") == 0){				
				// left up
				if(0 <=x - i && 0 <=y - i && *(*(arr + y -i) + x - i) == flag){
					 count ++;
				}else{
					break;
				}			
			}
			if(strcmp(f,"u") == 0){				
				// up
				if(0 <=y - i && *(*(arr + y -i) + x) == flag){
					 count ++;
				}else{
					break;
				}			
			}
			if(strcmp(f,"ru") == 0){				
				// right up
				if(0 <= y - i && x + i <= C && *(*(arr + y + i) + x + i) == flag){
					 count ++;
				}else{
					break;
				}			
			}
			if(strcmp(f,"r") == 0){				
				// right
				if(x + i < C && *(*(arr + y) + x + i) == flag){
					 count ++;
				}else{
					break;
				}			
			}
		}
		return count;
		
	} 
	


