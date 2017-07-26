/*
 * Aluno(a):Marcelo Martins Vilela Filho
 * RA:202619
 */

/*
 * Objetivos: O programa tem como  objetivo realizar um processamento de imagem e aplicar
 * filtros (esticar contraste, escala de cinza ou normalizar).
 * 
 * Entradas: A entrada é uma imagem no formato ppm, que contem os valores de RGB de cada 
 * pixel da imagem.
 *
 * Saida: Consiste em um novo arquivo, com a imagem inicial mas com o filtro escolhido
 * aplicado.
 */





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void fillTheMemoryWithAVector(unsigned int *vector, FILE *archive, unsigned int size){

/*
 * Copia um vetor presente no arquivo, para a memoria principal do computador.
 * utilizo um vetor linear ao invés de uma matriz.
 */



	unsigned int aux;
	for(unsigned int i = 0; fscanf(archive," %u", &aux) != EOF && i<size; i++){
		vector[i] = aux;
	}

	fclose(archive);
}

void fillTheArchiveWithTheLinearizedMatrix(FILE *archive, unsigned int *linearizedMatrix, unsigned int size, unsigned int width){

/*
 * Copia um vetor presente na memoria principal, para um arquivo, a cópia é feita
 * respeitando a formatação, que é no formato de matriz, ou seja, depende da largura e altura.
 */


		for(unsigned int i = 0; i < size; i++){

			if(i % (3*width) == 0 && i < size - 1)
				fprintf(archive,"\n"); 
		
			fprintf(archive, "%u", linearizedMatrix[i]);

			if( (i+1) % (3*width) != 0)
				fprintf(archive," "); 
		}
}

void findTheBiggestAndTheSmallest(unsigned int *vector,unsigned int size ,unsigned int *biggest ,unsigned int *smallest, unsigned int componentPosition){

/*
 * Percorre um  vetor e encontra o maior e menor valor dele.
 */


	*biggest = vector[componentPosition];
	*smallest = vector[componentPosition];
	
	for(unsigned int i = componentPosition; i < size; i+=3){

		if(vector[i] > *biggest)
			*biggest = vector[i];

		if(vector[i] < *smallest)
			*smallest = vector[i];
			
}
	

int main(int argc, char **argv) {

	if (argc != 3) {
		fprintf(stderr, "Argumentos invalidos. Use:\n");
		fprintf(stderr, "./lab18 <arqEntrada> <arqSaida>\n");
		fprintf(stderr, "Usado:");

		for (unsigned int i=0; i<argc; i++) {
			fprintf(stderr, " %s", argv[i]);
		}

		fprintf(stderr, "\n");
		return 1;
	}

	char efeito[20] = "cinza";
	char *arqEntrada = argv[1];
	char *arqSaida = argv[2];

	//scanf("%s", efeito);

	FILE *targetArchive;
	FILE *finalArchive;
	
	targetArchive = fopen(arqEntrada, "r");
	finalArchive = fopen(arqSaida, "w");

	if(targetArchive == NULL)
		printf("Erro ao tentar abrir o arquivo\n"); 
	
	char typeOfPortablePixMap[2];	
	unsigned int width, height, iMax;
	//leitura e escrita do primeiro parametro PPM
	fscanf(targetArchive, "%s", typeOfPortablePixMap); 
	fprintf(finalArchive, "%s\n", typeOfPortablePixMap);
	//leitura do parametros de largura altura e intensidade maxima do arquivo de entrada
	fscanf(targetArchive, " %u", &width);
	fscanf(targetArchive, " %u", &height);
	fscanf(targetArchive, " %u", &iMax);
	//escrita dos parametros para o arquivo final
	fprintf(finalArchive, "%u %u\n", width, height);
	fprintf(finalArchive, "%u", iMax);

	//criação do vetor que conterá todos o valores dos pixels
	unsigned int imageSize = 3*width*height;
	unsigned int *image = malloc(imageSize*sizeof(unsigned int));
	//copia dos valores para o vetor
	fillTheMemoryWithAVector(image, targetArchive, imageSize);
	
	
	if(strcmp(efeito, "cinza") == 0){

/*
 * Aplica o efeito escala de cinza nos pixels da image, consiste em fazer a média aritmética das
 * intensidades de cada componente do pixel , atribuir esse valor a todas as componentes do pixel.
 * na estrutura matricial sua formula é:
 *
 *	novaR[X][Y] = ⌊(imagemR[X][Y] + imagemG[X][Y] + imagemB[X][Y]) / 3⌋
 *	novaG[X][Y] = novaR[X][Y]
 *	novaB[X][Y] = novaR[X][Y]
 */

		//percorrendo o vetor realizando saltos de 3 em 3 para cada componente.
		for(unsigned int r = 0, g = 1, b = 2; b < imageSize; r+=3, g+=3, b+=3){
			float newPixelColor;			
			newPixelColor = floor(((image[r]+image[g]+image[b])/3));
			
			image[r] = newPixelColor;
			image[g] = newPixelColor;
			image[b] = newPixelColor;
			
		} 

	}else if(strcmp(efeito, "esticar") == 0){

/*
 * Aplica o efeito de esticar contraste nos pixels
 * na estrutura matricial a formula do filtro é:
 *
 *	novaR[X][Y] = ⌊((imagemR[X][Y] - Rmin) * 255)/(Rmax - Rmin)⌋
 *	novaG[X][Y] = ⌊((imagemG[X][Y] - Gmin) * 255)/(Gmax - Gmin)⌋
 *	novaB[X][Y] = ⌊((imagemB[X][Y] - Bmin) * 255)/(Bmax - Bmin)⌋
 */


		unsigned int *rMax = malloc(sizeof(unsigned int)), *gMax = malloc(sizeof(unsigned int)), *bMax = malloc(sizeof(unsigned int));
		unsigned int *rMin = malloc(sizeof(unsigned int)), *gMin = malloc(sizeof(unsigned int)), *bMin = malloc(sizeof(unsigned int));  

		//Encontra os valores maximo e minimo da intensidade de cada componente dentre todos
		//os pixels.
		findTheBiggestAndTheSmallest(image, imageSize ,rMax ,rMin, 0);
		findTheBiggestAndTheSmallest(image, imageSize ,gMax ,gMin, 1);
		findTheBiggestAndTheSmallest(image, imageSize ,bMax ,bMin, 2);


			for(unsigned int r = 0, g = 1, b = 2; b < imageSize; r+=3, g+=3, b+=3){
				float newPixelColorR , newPixelColorG, newPixelColorB;

				if(*rMax - *rMin != 0){
				newPixelColorR = floor(((image[r] - *rMin)*255)/(*rMax - *rMin));
				image[r] = newPixelColorR;
				}

				if(*gMax - *gMin != 0){
				newPixelColorG = floor(((image[g] - *gMin)*255)/(*gMax - *gMin));
				image[g] = newPixelColorG;
				}

				if(*bMax - *bMin != 0){
				newPixelColorB = floor(((image[b] - *bMin)*255)/(*bMax - *bMin));
				image[b] = newPixelColorB;			
				}		
			} 

		free(rMax);
		free(rMin);
		free(gMax);
		free(gMin);
		free(bMax);
		free(bMin);

	}else if(strcmp(efeito, "normalizar") == 0){

/*
 * Aplica o efeito de normalizar nos pixels
 * na estrutura matricial a formula do filtro é:
 *
 *	novaR[X][Y] = ⌊imagemR[X][Y] * 255 / (imagemR[X][Y] + imagemG[X][Y] + imagemB[X][Y])⌋
 *	novaG[X][Y] = ⌊imagemG[X][Y] * 255 / (imagemR[X][Y] + imagemG[X][Y] + imagemB[X][Y])⌋
 *	novaB[X][Y] = ⌊imagemB[X][Y] * 255 / (imagemR[X][Y] + imagemG[X][Y] + imagemB[X][Y])⌋
 */



		for(unsigned int r = 0, g = 1, b = 2; b < imageSize; r+=3, g+=3, b+=3){
			float sumOfComponents;	
		
			sumOfComponents = image[r]+image[g]+image[b];
			
			if(sumOfComponents != 0){
				image[r] = floor((image[r] * 255)/(sumOfComponents));
				image[g] = floor((image[g] * 255)/(sumOfComponents));
				image[b] = floor((image[b] * 255)/(sumOfComponents));
			}
		}
			

	}	
	//preenche o arquivo final com os pixels processados.	
	fillTheArchiveWithTheLinearizedMatrix(finalArchive, image, imageSize, width);
		
	free(image);
	fclose(finalArchive);


	return 0;
}
