/*  Marcelo Martins Vilela Filho
    RA - 202619 - Engenharia de Computação

Objetivo:O programa tem como objetivo imprimir o tempo de espera necessário para que uma bomba exploda no momento correto de forma que desvie a trajetória inicial da outra bomba.

Entradas: Temos como entradas h ,vb , d e T que são respectivamente
a altura inicial da bomba, a velocidade inicial da bomba (vertical),
a distância horizontal entre a bomba e o alvo e a força de empuxo.

Saida: a saida imprime o tempo t (em segundos) de espera necessário para o acionamento correto da bomba e consequente desvio.


*/
#include <stdio.h>

int main (){
	float h = 0, vb = 0 , d = 0,T = 0,t = 0;
	
	scanf("%f",&h);
	scanf("%f",&vb);
	scanf("%f",&d);
	scanf("%f",&T);

	t = ((h/vb)-(d/T));
	
	printf("%.3f\n",t);





return 0;
}

