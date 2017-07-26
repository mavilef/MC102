#include<stdio.h>
#include<stdlib.h>

int is_in(int x, int y, int n, int m) {
	return 0 <= x && x < n && 0 <= y && y < m;
}


void followPath(char **field ,int x, int y, int lines, int columns, int dx[], int dy[], char simbol){

	field[x][y] = '-';

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (is_in(nx, ny, lines, columns) && field[nx][ny] == simbol) {
			followPath(field, nx, ny, lines, columns, dx, dy, simbol);
		}
	}
	return;
}

int main(){
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
  
	char **field ;
	long long int lines, columns;
 
	scanf("%lld %lld",&lines,&columns);

  
	field = malloc(lines*sizeof(char*));

	for(int i = 0; i < lines; i++){
		field[i]=malloc(columns*sizeof(char));
	}
	
  
	for(int i = 0; i<lines; i++){
		for(int j = 0; j<columns; j++){
			scanf(" %c", &field[i][j]);
		}
	}

	long long int alies = 0, enemies = 0;
	for(int i = 0; i < lines; i++){
		for(int j = 0;j<columns;j++){
			if(field[i][j]=='*'){
				enemies++;
				followPath(field, i, j, lines, columns, dx, dy, '*' );

     
			}else if(field[i][j]=='#'){
				alies++;
				followPath(field, i, j, lines, columns, dx, dy, '#');   
			}    
		}    
	}
  
	printf("Bases rebeldes: %lld\n", alies); 
	printf("Bases do imperio: %lld\n", enemies);
	return 0;
 }




