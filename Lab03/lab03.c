//Marcelo Martins Vilela Filho RA 202619 - Engenharia de Computação

/*Objetivo: O programa tem o objetivo de verificar se a variável volume(que representa o volume de combustivel de um caminhão-tanque) é suficiente para abastecer os postos de combustível A, B e C.(representados por a,b,c)sendo que se não for possivel abastecer completamente o posto , então este não é abastecido.

Entradas: a,b,c representam a capacidade de cada posto em litros.
d e h representam, respectivamente o diâmetro e o comprimento do tanque do caminhão em metros cúbicos.
A ordem de entrada é d,h,a,b,c; 

Saidas:A saida imprime na tela, quais postos serão abastecidos e quais não são, dada a capacidade do tanque.(considera-se o tanque cheio)*/


#include <stdio.h>

int main(){

float d , h , a , b , c , volume;
const float pi = 3.14;

scanf("%f %f %f %f %f",&d, &h, &a,&b,&c);

volume = pi*(d/2)*(d/2)*h*1000;

	if(volume>=a){
	printf("posto A foi reabastecido\n");
	volume = volume - a;
	}else{
	printf("posto A nao foi reabastecido\n");
	}

	if(volume>=b){
	printf("posto B foi reabastecido\n");
	volume = volume - b;
	}else{
	printf("posto B nao foi reabastecido\n");
	}

	if(volume>=c){
	printf("posto C foi reabastecido\n");
	volume = volume - c;
	}else{
	printf("posto C nao foi reabastecido\n");
	}

return 0;
}
	








