#include<stdio.h>
#include"dfConst.h"
#include"checkWhoWin.c"

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
	system("cls");	
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




	


