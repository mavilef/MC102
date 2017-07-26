//Marcelo Martins Vilela Filho RA 202619 - Engenharia de Computação

/*Objetivo: O programa tem o objetivo de verificar se, dadas 4 cargas diferentes, se é possivel organiza-las de tal forma que seja possivel balancea-las, ou seja , se a soma de duas ou uma carga seja igual ás outras. 

Entradas: c1,c2,c3 e c4 representam as cargas(numeros inteiros);
A variável Sim foi escolhida como contador de maneira que se em algum teste for possivel é acrescentada á variavel 1 unidade;

Saidas:se for possivel, em algum caso , organizar, então , será impresso sim na tela, caso não haja casos possiveis, será impresso nao.*/

#include <stdio.h>

int main(){

//inicialização
int c1 ,c2 ,c3, c4, sim=0;
scanf("%d %d %d %d", &c1, &c2, &c3, &c4);

	if((c1+c2)==(c3+c4))
	sim++;


	if((c1+c3)==(c2+c4))
	sim++;


	if((c1+c4)==(c2+c3))
	sim++;

	if((c1)==(c2+c3+c4))
	sim++;


	if((c2)==(c1+c3+c4))
	sim++;

	if((c3)==(c1+c2+c4))
	sim++;

	if((c4)==(c1+c2+c3))
	sim++;




		if(sim>=1)
		printf("sim\n");
		else
		printf("nao\n");

return 0;

}
