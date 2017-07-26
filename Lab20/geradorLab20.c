#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char **argv ){

	if (argc != 2) {
		fprintf(stderr, "Argumentos invalidos. Use:\n");
		fprintf(stderr, "./geradorLab20 <arqSaida>\n");
		fprintf(stderr, "Usado:");

		for (unsigned int i=0; i<argc; i++) {
			fprintf(stderr, " %s", argv[i]);
		}

		fprintf(stderr, "\n");
		return 1;
	}


	char *archiveName = argv[1];

	FILE *finalArchive = fopen(archiveName, "w");

	int x, lines, columns;
	printf("digite o numero de linhas: ");
	scanf("%d", &lines);
	printf("digite o numero de colunas: ");
	scanf(" %d", &columns);

	fprintf(finalArchive,"%d %d\n", lines, columns);

	srand(time((NULL)));	

	for(int i = 0; i < lines; i++){
		for(int j = 0; j < columns; j++){
			
			//x = rand() % 3;
			//if(x == 0)
				fprintf(finalArchive,"* ");
			//if(x == 1)
				//fprintf(finalArchive,"# ");
			//if(x == 2)
				//fprintf(finalArchive,"- ");
			
		}

		fprintf(finalArchive,"\n");
	}

	fclose(finalArchive);

	printf("O arquivo com o nome %s foi gerado!\n", archiveName);

	return 0;

}
