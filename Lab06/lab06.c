//Marcelo Martins Vilela Filho RA 202619 - Engenharia de Computação

/*Objetivo: O programa tem objetivo de verificar se uma espaçonave após t segundos(digitado pelo usuario) tem uma quantidade maior ou igual a uma quantidade c, suficiente para ativar uma função da espaçonave.

Entradas: t é o tempo máximo disponível até ativar a função.c é quantidade necessária para ativar a função , após esse valores o usuário deve inserir o fluxo de combustível em cada instante especificado antes.

Saidas:O programa imprime sé é possivel ou não utilizar a função da espaçonave, e o tempo em que irá usar ( sendo t+1 , o próximo tempo) a função. */

#include <stdio.h>

int main (){

int i ,t, c , f, acumulador=0;
scanf("%d %d", &t, &c);

	for(i = 1; i<=t ; i++){

	scanf("%d", &f);
	acumulador = acumulador + f;

	if(acumulador >= c)
	break;

	}

	if(acumulador >= c)
	printf("sim\n%d\n", i);
	else
	printf("nao\n%d\n", t+1);
	
	

return 0;
}
