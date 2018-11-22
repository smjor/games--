

	
int checkWhoWin(char (*arr)[C],char flag,int x,int y){
	int dwCk(char (*arr)[C],char flag , int x, int y);
	// 00-invalid;01-success;02-continue;	
	// check invalid input 
	if(*(*(arr + y)+x) == RED || *(*(arr + y)+x) == BLUE
		 || x == 0 || y == 0 || x == R || y == C){
		printf("invalid input please input once again \n");		
		return 00;
	}
	// check in row¡¢colum or diagonal of who have five chess; 	
	int i;		
	dwCk(arr,flag,x,y);
	#ifdef DEBUGM
	printf("horizotal = %d\n",cpdc.Count_horizotal[0]);
	printf("leftSlash = %d\n",cpdc.Count_leftSlash[0]);
	printf("vertical = %d\n",cpdc.Count_vertical[0]);
	printf("rightSlash = %d\n",cpdc.Count_rightSlash[0]);
	#endif
	#ifndef DEBUGM	
	if(5 <= cpdc.Count_horizotal[0] || 
		5 <= cpdc.Count_leftSlash[0] ||
			5 <= cpdc.Count_vertical[0] ||
				5 <= cpdc.Count_rightSlash[0]){
			// success
		return 01;
	}	
	#endif
	return 02;
	
}


int dwCk(char (*arr)[C],char flag , int x, int y){	
	// initialize struct	
	int i;	
	for(i=0;i<3;i++){
		if(i == 0){
			cpdc.Count_horizotal[i] = 1;
			cpdc.Count_leftSlash[i] = 1;	
			cpdc.Count_vertical[i] =1;
			cpdc.Count_rightSlash[i] =1;
		}else{
			cpdc.Count_horizotal[i]	= 0;
			cpdc.Count_leftSlash[i] = 0;	
			cpdc.Count_vertical[i] = 0;
			cpdc.Count_rightSlash[i] = 0;
		}
		
	}
	for(i= 1;i < COUNT;i++){
		if(0 < x - i || x + i < C){				
			// left			
			if(cpdc.Count_horizotal[1] != -1 && *(*(arr + y) + x - i) == flag){
				 cpdc.Count_horizotal[0] ++;					 
			}else{
				cpdc.Count_horizotal[1] = -1;
			}
			// right
			if(cpdc.Count_horizotal[2] != -1 && *(*(arr + y) + x + i) == flag){
				 cpdc.Count_horizotal[0] ++;					 
			}else{
				cpdc.Count_horizotal[2] = -1;
			}							
		}
		if((0 <x - i && 0 <y - i) || (x + i <= C && y + i <= R)){				
				// left up				
			if(cpdc.Count_leftSlash[1] != -1 && *(*(arr + y -i) + x - i) == flag){
				 cpdc.Count_leftSlash[0] ++;					 
			}else{
				cpdc.Count_leftSlash[1] = -1;					
			}
			// right down
			if(cpdc.Count_leftSlash[2] != -1 && *(*(arr + y + i) + x + i) == flag){
				 cpdc.Count_leftSlash[0] ++;					 
			}else{
				cpdc.Count_leftSlash[2] = -1;					
			}			
													
		}	
		if(0 <y - i || y + i <= R){				
			// up					
			if(cpdc.Count_vertical[1] != -1 && *(*(arr + y -i) + x) == flag){
				 cpdc.Count_vertical[0] ++;					 
			}else{					
				cpdc.Count_vertical[1] = -1;
			}
			// down
			if(cpdc.Count_vertical[2] != -1 && *(*(arr + y + i) + x) == flag){
				 cpdc.Count_vertical[0] ++;	
			}else{					
				cpdc.Count_vertical[2] = -1;
			}						
		}
		if((0 < y - i && x + i <= C) || (R <=y + i && 0 <x - i)){				
			// right up				
			if(cpdc.Count_rightSlash[1] != -1 && *(*(arr + y + i) + x + i) == flag){
				 cpdc.Count_rightSlash[0] ++;
			}else{
				cpdc.Count_rightSlash[1] = -1;
			}
			// left down
			if(cpdc.Count_rightSlash[2] != -1 && *(*(arr + y + i) + x - i) == flag){
				 cpdc.Count_rightSlash[0] ++;
			}else{
				cpdc.Count_rightSlash[2] = -1;
			}							
		}			
	}
	return 1;		
}
