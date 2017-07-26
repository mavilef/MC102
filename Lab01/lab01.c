/*  Marcelo Martins Vilela Filho
    RA - 202619 - Engenharia de Computação

Objetivo:O programa calcula o quanto um passageiro deve pagar por um transporte dada
uma distancia até seu ponto de destino.

Entrada:é necessario a entrada de vi(valor inicial, fixo, cobrado pelo motorista) , xi ( posição horizontal inicial do passageiro) yi(posição vertical inicial do passageiro) , xf ( posição horizontal final do passageiro), yf (posição vertical final do passageiro) , t ( taxa por distancia percorrida cobrada pelo motorista,varia).

Saida: imprime a variavel v que representa o custo final para o passageiro.

*/

#include <stdio.h>

int main(){
	int vi, xi , yi,xf,yf ,t, v;
	
	scanf("%i",&vi);
	scanf("%i",&xi);
	scanf("%i",&yi);
	scanf("%i",&xf);
	scanf("%i",&yf);
	scanf("%i",&t);
	
	v = vi + ((xf-xi)+(yf-yi))*t;

	printf("%i\n", v);

	return 0;



}
