//Marcelo Martins Vilela Filho RA 202619 - Engenharia de Computação

/*Objetivo: O programa tem como objetivo apagar,substituir ou inverter palavras
palavras de um texto, digitado pelo usuário.

Entradas: Como entrada temos uma string, que é o texto de até 1000 caracteres, 
a operação que usuário deseja realizar ( D - deleta uma palavrado texto, R - substitui
uma palavra do texto por outra, I inverte as letras de uma palavra do texto) e a
palavra do texto sobre a qual será realizada o operação(no caso do substituir 
deve-se dizer qual é a nova palavra).

Saidas: Como saida temos o texto depois de realizar todas as operações desejadas.
*/

#include <stdio.h>
#include <string.h>

/*		
comparissonBetween faz compara duas strings, e retorna zero, caso sejam iguais,
retorna o inteiro 0.
Tal função é case insensitive e consiste em deixar todos os caracteres minúsculos
antes de usar strcmp,(que compara , mas não é case insensitive)
*/

int comparisonBetween(char a[], char b[]){

	char aux1[50], aux2[50];
	strcpy(aux1,a);
	strcpy(aux2,b);

	for(unsigned int k = 0; aux1[k] != '\n' && aux1[k] != '\0'; k++){
		if(aux1[k] >= 65 && aux1[k] <= 90){
		 aux1[k] = aux1[k] + 32;		
		}
	}

	for(unsigned int k = 0; aux2[k] != '\n' && aux2[k] != '\0'; k++){
		if(aux2[k] >= 65 && aux2[k] <= 90){
		 aux2[k] = aux2[k] + 32;		
		}
	}

	
	return strcmp(aux1, aux2);
}
/*
TakeOffFinalSpaces retira espaços depois da ultima palavra da string
texto,caso haja.
*/
void TakeOffFinalSpaces(char a[], int tamA){
	unsigned int x;
		x = strlen(a);
		if(a[x-1] == ' '){
			a[x-1] = '\n';
		}
			
		
	for(unsigned int i = x - 5; i < tamA  && a[i] != '\0'; i++){
		if(a[i] == ' ' && a[i+1] == '\n'){
			a[i] = '\n';
			a[i+1] = '\0';  
			break;
		}
		
	}
}

/*
Função Apagar, basicamente copia caracteres do texto char por char
em uma string auxiliar quando forma uma palavra compara com a 
palavra digitada pelo usuário, caso sejam iguais, é gravada a 
posição da palavra e reconstruido o texto de maneira que ao passar 
pela posição da palavra, o texto é reconstruido sem a palavra.
*/

void delete(char a[], char b[], int tamA , int tamB){

	char aux[tamB];

	for(int k = 0, l = 0; k < tamA + 1 && a[k] !='\0'; k++){

		if(a[k]!=' ' && a[k]!= '\n'){
			aux[l] = a[k];
			l++;
		}else{
			aux[l] = '\0';
			if(comparisonBetween(aux,b) == 0){				
				for(unsigned int location = 0 , rebuild = 0; rebuild < tamA + 1 && a[rebuild] != '\0'; rebuild++){
					if(location == k-1-l){
						location = location + l + 2;
					}else if( k-l-1 == -1) {
						k--;
						location = location + l + 1;
						rebuild--;

					}else{
						a[rebuild] = a[location];
						location++;
					}

				}

				k=-1; 	

			}else{
				aux[0] = '\0';
			}
			l = 0;
			continue;			
		}
	}
}

/*
Função Substituir, aqui é copiado char por char do texto para uma
string auxiliar, ao formar uma palavra, esta é comparada com
a palavra que o usuário deseja substituir, caso sejam iguais, 
o texto é reconstruido e ao passar pela posição da palavra
o programa grava a nova palavra, e continua a reconstrução
a partir do fim da palavra antiga.  
*/

void replace(char a[], char b[], char c[], int tamA , int tamB){

	unsigned int wordSize;
	char aux[tamB], aux2[tamA];
	wordSize = strlen(c);
	strcpy(aux2, a);
	

	for(int k = 0, l = 0; k < tamA + 1 && aux2[k] !='\0'; k++){

		if(aux2[k]!=' ' && aux2[k] != '\n'){
			aux[l] = aux2[k];
			l++;
		}else{
			aux[l] = '\0';
			if(comparisonBetween(aux,b) == 0){
				unsigned int aux3;
				unsigned int rebuild;

				if(a[k+1] == '\0'){
					aux3 = k;
				}else{
					aux3 = k+1;
				}

				for(rebuild = 0; rebuild < tamA + 1 && a[aux3] != '\0'; rebuild++){
					if(rebuild == k-l ){
						for(unsigned int insertWord = 0; insertWord < wordSize; insertWord++){
								aux2[rebuild+insertWord] = c[insertWord];
						}
						aux2[rebuild+wordSize] = ' ';
						rebuild = rebuild + wordSize;
					}else if(rebuild > k-l){
						aux2[rebuild] = a[aux3];
							aux3++;
					}else{
						continue;
					}
					
				}
				aux2[rebuild] = '\0';
				strcpy(a,aux2);
				aux[0]='\0';
				k=-1;	
			}else{
				aux[0] = '\0';
			}
			l = 0;
			continue;			
		}
	}
	strcpy(a,aux2);
}

/*
Função substituir porém não é case insensitive(só encontra palavras
idênticas no texto) , foi criada para facilitar o uso da função inverter.
*/
void replaceNonCaseInsensitive(char a[], char b[], char c[], int tamA , int tamB){

	unsigned int wordSize;
	char aux[tamB], aux2[tamA];
	wordSize = strlen(c);
	strcpy(aux2, a);
	

	for(int k = 0, l = 0; k < tamA + 1 && aux2[k] !='\0'; k++){

		if(aux2[k]!=' ' && aux2[k] != '\n'){
			aux[l] = aux2[k];
			l++;
		}else{
			aux[l] = '\0';
			if(strcmp(aux,b) == 0){
				unsigned int aux3;
				unsigned int rebuild;

				if(a[k+1] == '\0'){
					aux3 = k;
				}else{
					aux3 = k+1;
				}

				for(rebuild = 0; rebuild < tamA + 1 && a[aux3] != '\0'; rebuild++){
					if(rebuild == k-l ){
						for(unsigned int insertWord = 0; insertWord < wordSize; insertWord++){
								aux2[rebuild+insertWord] = c[insertWord];
						}
						aux2[rebuild+wordSize] = ' ';

						rebuild = rebuild + wordSize;
					}else if(rebuild > k-l){
						aux2[rebuild] = a[aux3];
							aux3++;
					}else{
						continue;
					}
					
				}
				aux2[rebuild] = '\0';
				strcpy(a,aux2);
				aux[0]='\0';
				k=-1;	
			}else{
				aux[0] = '\0';
			}
			l = 0;
			continue;			
		}
	}
	strcpy(a,aux2);
}

/*
Função inverter , novamente é prenchida uma string auxiliar 
letra por letra e comparada com a palavra que o usuario deseja inverter
caso seja positivo, é mandada para a função replaceNonCaseInsensitive
a palavra velha e a intertida , e substituida no texto, note que após o processo
a função continua até encontrar a proxima palavra.
*/

void invert (char a[], char b[], int tamA, int tamB){

	char aux[tamB], aux2[tamB],temp;
	unsigned int realSize;

	for(unsigned int k = 0, l = 0; k < tamA + 1 && a[k] !='\0'; k++){

		if(a[k]!=' ' && a[k]!= '\n'){
			aux[l] = a[k];
			l++;
		}else{
			aux[l] = '\0';
			if(comparisonBetween(aux,b) == 0){
				strcpy(aux2,aux);
				realSize = strlen(aux2);
				for(unsigned int j = realSize - 1, i = 0; j > i ; j--, i++){
					temp = aux2[i];
					aux2[i] = aux2[j];
					aux2[j] = temp;		
				}
				replaceNonCaseInsensitive(a,aux,aux2,tamA,tamB);	
			}else{
				aux[0] = '\0';
			}
			l = 0;
			continue;			
		}
	}

	replace(a,b,aux2,tamA,tamB);
}
	
/*
Função principal do programa que recebe a string do texto e a operação,
baseado na operação, chama uma função para alterar a string texto,
isto é continuado até o usuário digitar Q na operação.
*/	

int main (){

	unsigned int sizeT = 1000, sizeWord = 50 ;
	char text[sizeT], operation = '0', wordDelete[sizeWord], wordInvert[sizeWord], new_wordReplace[sizeWord], old_wordReplace[sizeWord];

	fgets(text, sizeT, stdin);
	printf("%s", text);

	for(;operation != 'Q';){
		scanf("%c", &operation);

		if(operation == 'D'){

			scanf("%s", wordDelete);
			delete(text, wordDelete, sizeT, sizeWord);
			TakeOffFinalSpaces(text, sizeT);
			printf("%s", text);
		}

		if(operation == 'I'){
			scanf("%s",wordInvert);
			invert(text, wordInvert, sizeT, sizeWord);
			TakeOffFinalSpaces(text, sizeT);
			printf("%s", text);
		}

		if(operation == 'R'){

			scanf("%s", old_wordReplace);
			scanf("%s", new_wordReplace);
			replace(text, old_wordReplace , new_wordReplace, sizeT, sizeWord);
			TakeOffFinalSpaces(text, sizeT);
			printf("%s", text);
			
		}

		if(operation == 'Q')
			break;	

	}


return 0;
}
