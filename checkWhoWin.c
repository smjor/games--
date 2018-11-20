

	
int checkWhoWin(char (*arr)[C],char flag,int x,int y){
	int FrwdCk(char (*arr)[C],char flag,char f[2] , int x, int y);
	int dwCk(char (*arr)[C],char flag,char f[2] , int x, int y);
	int evalFunc(char (*arr)[C],char flag, int x, int y);

	// 00-invalid;01-success;02-continue;
	
	// check invalid input 
	if(*(*(arr + y)+x) == RED || *(*(arr + y)+x) == BLUE
		 || x == 0 || y == 0 || x == R || y == C){
		printf("invalid input please input once again \n");		
		return 00;
	}
	// check in row¡¢colum or diagonal of who have five chess; 

	evalFunc(arr,flag, x, y);
	// not about range;	

	//printf("%d\n",dwCk(arr,flag,"rd" , x, y));	
	int i;
	int winFlag = 0;
	
	for(i = 0;i < JUDGE;i ++){
		#ifdef DEBUGM
		printf("upName=%s\n",cci_struct[i].upName);
		printf("dName=%s\n",cci_struct[i].dName);
		printf("countUp=%d\n",cci_struct[i].countUp);
		printf("countD=%d\n",cci_struct[i].countD);
		printf("countAmongUp=%d\n",cci_struct[i].countAmongUp);
		printf("countAmongD=%d\n",cci_struct[i].countAmongD);
		#endif
		#ifndef DEBUGM		 
		
		if(5 <= cci_struct[i].countD || 5 <= cci_struct[i].countUp){
			winFlag = 1;	
		}			
		if(5 <= (cci_struct[i].countD + cci_struct[i].countUp -1)){
			winFlag = 1;	
		}		
		if(winFlag){
			// success
			return 01;
		}
		#endif
		
	}
	
	return 02;
	
}

int evalFunc(char (*arr)[C],char flag, int x, int y){
		// initialize struct cacheChessInfo
		int i;
		for(i = 0;i < JUDGE;i ++){
			cci_struct[i].countUp = 0;
			cci_struct[i].countD = 0;
			cci_struct[i].countAmongUp = 0;
			cci_struct[i].countAmongD = 0;
		}
	
		dwCk(arr,flag,"rd" , x, y);
		dwCk(arr,flag,"d" , x, y);
		dwCk(arr,flag,"ld" , x, y);
		dwCk(arr,flag,"l" , x, y);
		FrwdCk(arr,flag,"lu" , x, y);
		FrwdCk(arr,flag,"u" , x, y);
		FrwdCk(arr,flag,"ru" , x, y);
		FrwdCk(arr,flag,"r" , x, y);
}

int dwCk(char (*arr)[C],char flag,char f[2] , int x, int y){	

	// include self;
	int i,count = 1;
	// cache Empty cell;
	int countEmpty = 0;
	// First count through the FLAG;
	int first = 1;
	
	for(i= 1;i < COUNT;i++){		
			if(strcmp(f,"rd") == 0 && x + i <= C && y + i <= R){				
				// right down
				strcpy(cci_struct[0].dName,"rd");
				
				if(first && *(*(arr + y + i) + x + i) == flag){
					 count ++;
					 cci_struct[0].countD = count;
				}else{					
					first = 2;				
				}		
				if(count == 1){
					if(*(*(arr + y + i) + x + i) != (flag == RED?BLUE:RED)){
						// first come in;
						countEmpty ++;
						cci_struct[0].countAmongD = countEmpty;
						first = 1;
					}else{
						// block
						break;
					}
					
				}
					
			}
			if(strcmp(f,"d") == 0 && y + i <= R){				
				// down
				strcpy(cci_struct[1].dName,"d");	
				if(first && *(*(arr + y + i) + x) == flag){
					 count ++;
					 cci_struct[1].countD = count;
				}else{					
					first = 0;	
				}
				if(count == 1){
					if(*(*(arr + y + i) + x) != (flag == RED?BLUE:RED)){
						// first come in;
						countEmpty ++;
						cci_struct[1].countAmongD = countEmpty;
						first = 1;
					}else{
						break;
					}
					
				}
							
			}
			if(strcmp(f,"ld") == 0 && R <=y + i && 0 <x - i){	
				strcpy(cci_struct[2].dName , "ld");			
				// left down
				if(first && *(*(arr + y + i) + x - i) == flag){
					 count ++;
					 cci_struct[2].countD = count;
				}else{					
					first = 0;	
				}
				if(count == 1){
					if(*(*(arr + y + i) + x - i) != (flag == RED?BLUE:RED)){
						// first come in;
						countEmpty ++;
						cci_struct[2].countAmongD = countEmpty;
						first = 1;
					}else{
						break;
					}
					
				}
							
			}
			if(strcmp(f,"l") == 0 && 0 < x - i){				
				// left
				strcpy(cci_struct[3].dName , "l");
				if(first && *(*(arr + y) + x - i) == flag){
					 count ++;
					 cci_struct[3].countD = count;
				}else{					
					first = 0;	
				}
				if(count == 1){
					if(*(*(arr + y) + x - i) != (flag == RED?BLUE:RED)){
						// first come in;
						countEmpty ++;
						cci_struct[3].countAmongD = countEmpty;
						first = 1;
					}else{
						break;
					}					
				}								
			}
		}
		return 1;
}

int FrwdCk(char (*arr)[C],char flag,char f[2] , int x, int y){
	
		// include self
		int i,count = 1;
		// cache Empty cell;
		int countEmpty = 0;
		// First count through the FLAG;
		int first = 1;
		for(i= 1;i < COUNT;i++){
		
			if(strcmp(f,"lu") == 0 && 0 <x - i && 0 <y - i){				
				// left up
				strcpy(cci_struct[0].upName , "lu");
				if(first == 1 && *(*(arr + y -i) + x - i) == flag){
					 count ++;
					 cci_struct[0].countUp = count;
				}else{
					
					first = 0;
				}
								
				if(count == 1){
					if(*(*(arr + y -i) + x - i) != (flag == RED?BLUE:RED)){
						// first come in;
						countEmpty ++;
						cci_struct[0].countAmongUp = countEmpty;
						first = 1;
					}else{
						break;
					}					
				}
														
			}
			if(strcmp(f,"u") == 0 && 0 <y - i){				
				// up
				strcpy(cci_struct[1].upName , "u");	
				if(first == 1 && *(*(arr + y -i) + x) == flag){
					 count ++;
					 cci_struct[1].countUp = count;
				}else{
					
					first = 0;
				}
				
				if(count == 1){
					if(*(*(arr + y -i) + x) != (flag == RED?BLUE:RED)){
						// first come in;
						countEmpty ++;
						cci_struct[1].countAmongUp = countEmpty;
						first = 1;
					}else{
						break;
					}
					
				}
							
			}
			if(strcmp(f,"ru") == 0 && 0 < y - i && x + i <= C){				
				// right up
				strcpy(cci_struct[2].upName , "ru");
				if(first == 1 && *(*(arr + y + i) + x + i) == flag){
					 count ++;
					 cci_struct[2].countUp = count;
				}else{
					
					first = 0;
				}
				if(count == 1){
					if(*(*(arr + y + i) + x + i) != (flag == RED?BLUE:RED)){
						// first come in;
						countEmpty ++;
						cci_struct[2].countAmongUp = countEmpty;
						first = 1;
					}else{
						break;
					}
					
				}
								
			}
			if(strcmp(f,"r") == 0 && x + i < C){				
				// right
				strcpy(cci_struct[3].upName , "r");		
				if(first == 1 && *(*(arr + y) + x + i) == flag){
					 count ++;
					 cci_struct[3].countUp = count;
				}else{					
					first = 0;
				}
				if(count == 1){
					if(*(*(arr + y) + x + i) != (flag == RED?BLUE:RED)){
						// first come in;
						countEmpty ++;
						cci_struct[3].countAmongUp = countEmpty;
						first = 1;
					}else{
						break;
					}					
				}					
			}
		}
		return 1;		
} 
