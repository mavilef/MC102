//Marcelo Martins Vilela Filho RA 202619 - Engenharia de Computação

/*Objetivo: O programa tem como objetivo de imprimir as operações necessárias para se obter o maior lucro possivel dadas previsões do preço de açoes
de 4 empresas para d dias. 

Entradas:Como entradas temos o numero de dias (d) que serão analisados as empresas, e as previsões para as 4 empresas(uma em cada linha)
para os d dias.

Saidas:Como saida é impresso as operações, necessárias para se obter o maior lucro possível

Nota do programador: é utilizado 3 matrizes tridimensionais uma com os o lucros(pos), obtidos pelas outras duas matrizes(ini e end), 
assim, os for's aninhados conferem em pos, o maior lucro possível.

*/


#include<stdio.h>

double maximo(double a, double b){
	if(a>b)
		return a;
	else
		return b;
}

int intersecao(int a , int b, int c, int d){
	if (b <= c || a >= d) {
		return 0;
	}
	return 1;
}


int main(){

	int dias, Lucro = 0;
	int idx;

	scanf("%d",&dias);
	
	double resfinal = 0;
	double acao[4][dias]; /* matriz ações das empresas.*/
	double pos[4][dias][dias];/* matriz do lucro em cada intervalos.*/
	int ini[4][dias][dias]; /* matriz dos intevalos iniciais.*/
	int end[4][dias][dias];/* matriz intervalos finais.*/
	double mini = 0;	
	double resp = 0;/* Lucro maximo armazenado (caso haja lucro)*/	
							

	
	//Faz a leitura do preço das ações das empresas para cada dia.
	for(int k = 0; k < 4; k++)
			for(int j =  0; j < dias; j++)
				scanf("%lf",&acao[k][j]);

	//Testa se há possibilidade de lucros.
	for(int i = 0; i<4; i++){
			if(Lucro==1)
				break;
		
			for(int j = 0; j<dias-1; j++){
				if(acao[i][j]>acao[i][j+1]){
					Lucro=0;	
				}else{
					Lucro=1;
					break;
				}
			}
		}
	
			
	// Coloca as possibilidades de dias.(Caso seja possivel obter algum lucro).
	if(Lucro == 1){
		for(int i = 0; i < 4; i++){
			for(int inicio = 0; inicio < dias; inicio++){
				for(int fim = inicio; fim < dias; fim++) {
					resp = -1;
					mini = acao[i][inicio];
					idx = inicio;
					for(int l = inicio; l <= fim; l++){
						if (acao[i][l] - mini > resp) {
							resp = acao[i][l] - mini;
							ini[i][inicio][fim] = idx;
							end[i][inicio][fim] = l;
							pos[i][inicio][fim]= resp;
						}
						if (acao[i][l] < mini) {
							mini = acao[i][l];
							idx = l;
						}
					}
				}
			}
		}
	//Encontra o melhor caminho possível na matriz, armazena para impressão posterior.
		int melhorca, melhorcb, melhorcc, melhorcd, melhorva, melhorvb, melhorvc, melhorvd;
		for(int inicioa = 0; inicioa < dias; inicioa++)
			for(int fima = inicioa; fima < dias; fima++)
				for(int iniciob = 0; iniciob < dias; iniciob++)
					for(int fimb = iniciob; fimb < dias; fimb++)
						for(int inicioc = 0; inicioc < dias; inicioc++)
							for(int fimc = inicioc; fimc < dias; fimc++)
								for(int iniciod = 0; iniciod < dias; iniciod++)
									for(int fimd = iniciod; fimd < dias; fimd++){
											if(intersecao(inicioa, fima, iniciob, fimb)||intersecao(inicioa, fima, inicioc, fimc)||intersecao(inicioa, fima, iniciod, fimd)||intersecao(iniciob, fimb, inicioc, fimc)||intersecao(iniciob, fimb, iniciod, fimd)||intersecao(inicioc, fimc, iniciod, fimd)){
												continue;
											}
										
											double aux= pos[0][inicioa][fima]+pos[1][iniciob][fimb]+pos[2][inicioc][fimc]+pos[3][iniciod][fimd];
											if(aux>resfinal){

												resfinal = aux;
												melhorca = ini[0][inicioa][fima];
												melhorcb = ini[1][iniciob][fimb];
												melhorcc = ini[2][inicioc][fimc];
												melhorcd = ini[3][iniciod][fimd];
												melhorva = end[0][inicioa][fima];
												melhorvb = end[1][iniciob][fimb];
												melhorvc = end[2][inicioc][fimc];
												melhorvd = end[3][iniciod][fimd];
																						
											}
																
									}
		
								
		if(melhorva - melhorca > 0){
			printf("acao 1: compra %d, venda %d, lucro %.2f\n", melhorca + 1, melhorva + 1, pos[0][melhorca][melhorva]);
		}	

		if(melhorvb - melhorcb > 0){
			printf("acao 2: compra %d, venda %d, lucro %.2f\n", melhorcb + 1, melhorvb + 1, pos[1][melhorcb][melhorvb] );
		}				

		if(melhorvc - melhorcc > 0){
			printf("acao 3: compra %d, venda %d, lucro %.2f\n", melhorcc + 1, melhorvc + 1, pos[2][melhorcc][melhorvc]);
		}				

		if(melhorvd - melhorcd > 0){
			printf("acao 4: compra %d, venda %d, lucro %.2f\n", melhorcd + 1, melhorvd + 1, pos[3][melhorcd][melhorvd]);
		}	
		printf("Lucro: %.2f\n", resfinal);			
			
	}else{
		printf("Lucro: %.2f\n", resfinal);
	}

	return 0;
}
