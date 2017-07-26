//Marcelo Martins Vilela Filho RA 202619 - Engenharia de Computação

/*Objetivo: O programa tem o objetivo de calcular, dado um cateto 'a' de um triangulo , da todos os possiveis outros lados de modo que o triangulo seja retângulo(Verificando de acordo com o teorema de pitagoras).

Entradas: Como entrada temos a variável a , que corresponde a um cateto do triangulo.

Saidas:Como saida é impresso as trinca ordenadas (a,b,c) onde a e b são os catetos do triangulo e c é a hipotenusa. */

#include <stdio.h>

int main(){

int a  , aq ,bq , cq , ind;

// aq , bq e cq são os quadrados dos lados.
// ind é uma variável indicadora , usada para sinalizar quando não há possíveis trincas ordenadas.

scanf("%d", &a);

aq=a*a;
	for(int c = 1 ; c<=1000 ; c++){

		cq = c*c;

		for(int b = 1; b<=1000;b++){

		bq=b*b;

			if(aq == cq - bq){
			printf("(%d, %d, %d)\n", a, b, c);		
			ind++;
			
			}
		}
		
	
	}

if(ind ==0)
printf("-\n");



return 0;
}
