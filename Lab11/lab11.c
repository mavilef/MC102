//Marcelo Martins Vilela Filho RA 202619 - Engenharia de Computação

/*Objetivo: O programa tem como objetivo encontrar palavras de um texto que 
correspondam a parâmetros para uma nave, se sim , é impresso na tela as 
instruções.

Entradas: Como entrada temos uma string, que é o texto.

Saidas: Como saida temos os parametros que devem ser seguidos pela nave para 
ajustar canhões ( direção e angulação em relação ao chão).
*/

#include <stdio.h>
#include <string.h>

/* A função comparisonBetween converte caracteres maiusculos de uma palavra(a[])
 * do texto em minúsculos, após isso a função compara (através da função strcmp) 
 * a palavra, colocada como parametro a[], com a palavra colocada como parametro
 * b[].Ou seja, a função torna a função strcmp , "case insensitive".  */

int comparisonBetween(char a[], char b[]){
	for(int k = 0; a[k] != '\n' && a[k] != '\0'; k++){
		if(a[k] >= 65 && a[k] <= 90){
		 a[k] = a[k] + 32;		
		}
	}
	
	return strcmp(a, b);
}


int main(){

	int sizeT = 1000, sizeP = 46;  /* sizeT = tamanho máximo do texto.
					* sizeP = tamanho máximo das palavras
					* do texto.
					* Nota:os tamanho já levam em 
					* consideração o \0 da palavra.
					*/


	char text[sizeT+1], word[sizeP+1];

	/*Leitura do text, onde fgets(nome da string,tamanho maximo,
	 * entrada padrão) faz a leitura até o /n digitado pelo usuário.
	 * Lembrando que o fgets coloca \0 depois de ler o \n . 
	 */

	fgets(text, sizeT, stdin);

	/*Inicializa um indice(i) que varre o texto (até /0), grava as
	 * palavras em outra string, e compara a ultima com os parametros
	 * dados no enunciado,e imprime na tela um codigo conforme o enunciado.  
	 */
	for(int i = 0, j = 0; i < sizeT + 1 && text[i] !='\0'; i++){
		/*O indice não grava caracteres de fim de palavra ou fim de
		 * linha("/s" ou "/n) na string da palavra */

		if(text[i]!=' ' && text[i]!= '\n'){
			word[j] = text[i];
			j++;
		}else{
			word[j] = '\0';
				if(comparisonBetween(word, "mercurio")== 0){
				printf("N");
				}
				if(comparisonBetween(word, "venus")== 0){
				printf("NE");
				}
				if(comparisonBetween(word, "terra")== 0){
				printf("L");
				}
				if(comparisonBetween(word, "marte")== 0){
				printf("SE");
				}
				if(comparisonBetween(word, "jupiter")== 0){
				printf("S");
				}
				if(comparisonBetween(word, "saturno")== 0){
				printf("SO");
				}
				if(comparisonBetween(word, "urano")== 0){
				printf("O");
				}
				if(comparisonBetween(word, "netuno")== 0){
				printf("NO");
				}
				if(comparisonBetween(word, "verde")== 0){
				printf(" - 30\n");
				}
				if(comparisonBetween(word, "amarelo")== 0){
				printf(" - 45\n");
				}
				if(comparisonBetween(word, "vermelho")== 0){
				printf(" - 60\n");
				}			
			j = 0;
			continue;			
		}
	}

	return 0;
}
