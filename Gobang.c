#include<stdio.h>
#define r 20
#define c 20
void main(){
	void init(char (*arr)[c]);
	void scanEle(char (*arr)[c],char flag);
	void drawPic(char (*arr)[c]);
	char str[r][c];	
	init(str);
	// input directive
	scanEle(str,'x');
	
};

void init(char (*arr)[c]){	
	
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
} 

void drawPic(char (*arr)[c]){
	int j,i = 0;
	while(i < r){
		for( j = 0;j < c;j ++){
			if(i == 0){
				printf("%4i",*(*(arr + i)+j));	
			}else if(j == 0){
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
	*(*(arr + x)+y) = flag;
	system("cls");	
	drawPic(arr);
	if(flag == 'x'){
		scanEle(arr,'*');
	}else{
		scanEle(arr,'x');
	}
}




