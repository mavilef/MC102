#include<stdio.h>
#include<stdlib.h>


void followPath(char **field, int xOcorrence, int yOcorrence, int lines, int columns, char simbol);

int main(){
  
	char **field ;
	int lines, columns;
 
	scanf("%d %d",&lines,&columns);

  
	field = malloc(lines*sizeof(char*));

	for(int i = 0; i < lines; i++){
		field[i]=malloc(columns*sizeof(char));
	}
	
  
	for(int i = 0; i<lines; i++){
		for(int j = 0; j<columns; j++){
			scanf(" %c", &field[i][j]);
		}
	}

	int alies = 0, enemies = 0;
	for(int i = 0; i < lines; i++){
		for(int j = 0;j<columns;j++){
			if(field[i][j]=='*'){
				enemies++;
				followPath(field, i, j, lines, columns, '*');

     
			}else if(field[i][j]=='#'){
				alies++;
				followPath(field, i, j, lines, columns, '#');   
			}    
		}    
	}
  
	printf("Bases rebeldes: %d\n", alies); 
	printf("Bases do imperio: %d\n", enemies);
	return 0;
 }


void followPath(char **field, int xOcorrence, int yOcorrence, int lines, int columns, char simbol){
	int i = xOcorrence, j = yOcorrence;
	field[i][j]='-';
	if(i+1 < lines){
		if(field[i+1][j] == simbol){
			followPath(field, i+1, j, lines, columns, simbol); 
			
		}  
	}
 
	if(i-1 >= 0){
		if(field[i-1][j] == simbol){
			followPath(field, i-1, j, lines, columns, simbol);  
			
		}  
	}
 
	if(j+1 < columns){
		if(field[i][j+1] == simbol){
			followPath(field, i, j+1, lines, columns, simbol);  
			
		}  
	}
 
	if(j-1 >= 0){
		if(field[i][j-1] == simbol){
			followPath(field, i, j-1, lines, columns, simbol); 
			

		}  
	}
 
	if(i+1 < lines && j+1< columns){
		if(field[i+1][j+1] == simbol){
			followPath(field, i+1, j+1, lines, columns, simbol);			   
		}  
 	}
 
 
	if(i+1 < lines && j-1>=0){
		if(field[i+1][j-1] == simbol){
			followPath(field, i+1, j-1, lines, columns, simbol);			
		}  
	}
 
	if(i-1 >= 0 && j+1< columns){
		if(field[i-1][j+1] == simbol){
			followPath(field, i-1, j+1, lines, columns, simbol);		
		}  
	}
 
	if(i-1 >= 0 && j-1 >= 0){
		if(field[i-1][j-1] == simbol){
			followPath(field, i-1, j-1, lines, columns, simbol); 
		}  
	}
}
