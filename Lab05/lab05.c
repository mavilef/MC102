//Marcelo Martins Vilela Filho RA 202619 - Engenharia de Computação

/*Objetivo: O programa tem objetivo de verificar , dada uma lista de números , o maior deles , o menor e a média aritmética de todos os numeros inseridos.

Entradas: n é a quantidade de numeros que serão inseridos na lista.
v é o numero da lista, perceba que, a cada ciclo o v é substituido pelo próximo numero inserido e será comparado, indiretamente, com os outros.

Saidas:é impresso na tela o maior numero inserido, o menor e a média aritmética entre todos os numeros inseridos.
As Variáveis de saída são max(para o maior numero inserido) , min (para o menor numero inserido) e sum(para a soma de todos os numeros inseridos)*/

#include <stdio.h>

int main(){

int n ;
float v, min = 99999, max = -99999 ,sum = 0;

scanf("%d", &n);

	for(int i = 1; i<=n;i++){
	
	scanf("%f",&v);
	
	sum = sum + v;

	if(v>max)
	max = v;

	if(v<min)
	min = v;
	}

printf("%.2f\n%.2f\n%.2f\n", min, max, sum/n);

return 0;

}


