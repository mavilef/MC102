/* Laboratorio 15B - Brincando com cordas
 * Nome: Marcelo Martins Vilela Filho
 * RA:202619
 */

/*
 * Objetivos:O programa tem como base a brincadeira rational tangle dance e tem como objetivo avaliar se dado uma sequencia de 
 * ações, as cordas estarão separadas ou se cruzaram em algum ponto.
 * 
 * Entradas:A entrada está na função main, que é dada neste laboratório,e basicamente consiste na inserção de '+', '-' e '*'
 * que significam respectivamente, troca por cima, troca por baixo e giro.
 * 
 * Saida: A função main faz a chamada de funçoẽs que simplificam as açoẽs de forma que remove ações que resultam
 * na mesma posição inicial, essas funções foram produzidas nesse laboratório.
 */

#include <stdio.h>
#include <string.h>

/* Funcao: removePadrao
 *
 *    Processa linearmente (e uma unica vez) os carateres de uma dada sequencia de movimentos,
 *    removendo as ocorrencias de um dado padrao.
 * 
 * Parametros:
 *          str: sequencia de movimentos '+', '-', '*'
 *       padrao: subsequencia de movimentos, cujas ocorrencias devem ser removidas
 *    targetStr: sequencia obtida apos a remocao de str de todas as ocorrencias do dado padrao.
 *               
 *  
 * Retorno:
 *
 *    1, se as occorrencias do dado padrao foram removidas
 *    0, caso contrario
 *
 * Exemplo:
 *
 *     char seq1[15] = "+-*+-*-*+++";
 *     char seq2[15];
 *
 *     char padrao1[3] = "+-"
 *     char padrao2[3] = "**"
 * 
 *     removePadrao(seq1, padrao1, seq2); // seq2 sera "**-*+++"
 *     removePadrao(seq1, padrao2, seq2); // seq2 sera "+-*+-*-*+++" 
 * 
 */
int removePadrao(char str[], char padrao[], char targetStr[]) {

/*
 * Nota do Programador: A lógica dessa função é percorrer o vetor inicial de tamanho actualSizeStr e comparar
 * seus caracteres com o caractere inicial de padrao(padrao[0]), os caracteres diferentes serão copiados para 
 * targetStr, mas caso um digito de str seja igual ao primeiro digito de padrao, um laço é acionado 
 * visando conferir se padrao esta contindo inteiramente depois daquela posição.Se estiver contido o indice que percorre
 * salta o tamanho de padrao(actualSizeSequence) e continua comparando/copiando dali em diante, fazendo o mesmo processo até o fim de str.
 * Trata-se de uma cópia seletiva para targetStr, copiando a string sem a sequencia padrçao;
 */


	int actualSizeStr = strlen(str) + 1, actualSizeSequence = strlen(padrao), counter = 0, copy, iDidSomething = 0;	

	for(int i = 0, j = 0; i < actualSizeStr ; i++){

		copy = 0; // copy indica quando é necessário copiar(0) ou não(1).

		if(str[i] == padrao[0]){
			for(int j = 0; j < actualSizeSequence; j++){
				if(str[i+j] == padrao[j]){
					counter++; // counter é uma variável contadora, usada para conferir se padrão está inteiramente em str.
				}else{
					counter=0;
					break;
				}
			}
		}

		if(counter == actualSizeSequence){// indica se padrao está inteiramente em str.
			iDidSomething = 1;//variável que indica se havia foi removido a sequencia alguma vez.
			counter = 0;
			i = i + actualSizeSequence - 1;// salto do indice, quando padrao está em str.
			copy = 1;//aciona a variável para não copiar.
		}

		if(copy == 0){//faz a copia quando necessário.
			targetStr[j] =  str[i];
			j++;
		}
		
	}

	return iDidSomething;
}

/* Funcao: removeBloco
 *
 *    Processa linearmente (e uma unica vez) os carateres de uma dada sequencia de movimentos,
 *    removendo o bloco inicial delimitado pelo dado caractere.
 * 
 * Parametros:
 *          str: sequencia de movimentos '+', '-', '*'
 *            c: caractere delimitador do bloco a ser removido
 *    targetStr: se str comeca com o caractere do parametro c, targetStr contera a sequencia obtida
 *               apos a remocao (de str) do bloco de movimentos da primeira posicao de str ate a 
 *               segunda ocorrencia (inclusive) do caractere do parametro c. Se nao exsitir uma segunda 
 *               ocorrencia do caracter do parametro c, targetStr deve conter a sequencia vazia.
 *
 * Retorno:
 *
 *    1, se o bloco foi removido
 *    0, caso contrario
 *
 * Exemplo:
 *
 *     char seq1[15] = "+-*+-*-*+++";
 *     char seq2[15] = "*+-*+-*-*+++";
 *     char seq3[15] = "*+-+--+++";
 *     char seq4[15];
 * 
 *     removeBloco(seq1, '*', seq4); // seq4 sera "+-*+-*-*+++"
 *     removeBloco(seq2, '*', seq4); // seq4 sera "+-*-*+++"
 *     removeBloco(seq3, '*', seq4); // seq4 sera "" (sequencia vazia)
 * 
 */
int removeBloco(char str[], char c, char targetStr[]) {

/*
 * Nota do Programador: A lógica dessa função é ativar/desativar uma variável que indica quando é para copiar str em targetStr ou não.
 * Essa variável é cpy, que é inicializada com o valor 1, que é impar, enquanto for impar a variável todo caractere de str é copiado para
 * targetStr, caso seja par a cópia é interrompida.
 * Um laço foi feito com um indice que percorre str, se a primeira letra de str for igual a c, é somado 1 em cpy,fazendo com que se torne par
 * e interrompe-se as cópias para targetStr(porém o indice ainda percorre), se é encontrada outra letra em str igual a c, soma-se mais um cpy, transformando-a 
 * novamente em impar, aciona-se uma variável que indica que a operação já foi feita, e retoma-se a cópia até o fim de str. 
 * A variável eraseTheLast foi usada para fazer a remoção do da segunda ocorrencia de c(se houver) e também para indicar que já foi removido o bloco,
 * sem ela a segunda ocorrencia é copiada pois cpy é somada antes de apagar o ultimo caracter.
 */


	int cpy = 1, doIDidSomething = 0, eraseTheLast = 0;

	for(int i = 0, j = 0;i < strlen(str) + 1; i++){

		if(str[i] == c && str[0] == c){	//verifica se str começa com c, e se há outra ocorrencia de c após a primeira
			doIDidSomething = 1;//variável que indica se operação foi realizada alguma vez, ou se estamos apenas realizando uma cópia de str.

			if(eraseTheLast != 2){//verifica se já foi realizada a operação de remover o bloco(a operação tem de ser realizada uma só vez).
			eraseTheLast = 1;
			cpy++;//transforma cpy em impar/par.
			} 	
		}

		if(cpy % 2 != 0 || str[i] == '\0'){
			
		if(eraseTheLast == 1 && str[i] == c){//apaga a ultima ocorrência de c.(após a primeira).
				eraseTheLast = 2;// Indica que o bloco ja foi removido. 
				continue;	
			}
			
			targetStr[j] = str[i];// faz as cópias para targetStr.
			j++;
		}
	}

	return doIDidSomething;
}

/* Funcao: substituiPadrao
 *
 *    Processa linearmente (e uma unica vez) os carateres de uma dada sequencia de movimentos,
 *    substituindo as ocorrencias de um dado padrao por um novo padrao.
 *
 * Parametros:
 *           str: sequencia de movimentos '+', '-', '*'
 *        padrao: subsequencia de movimentos, cujas ocorrencias devem ser substituidas pelo novoPadrao
 *    novoPadrao: subsequencia de movimentos que deve substituir cada ocorrencia do dado padrao
 *     targetStr: sequencia obtida apos a substituicao em str de todas as ocorrencias do dado padrao 
 *                pelo novoPadrao
 *
 *     Voce pode assumir que as subsequencias padrao e novoPadrao tem o mesmo tamanho.
 *
 * Retorno:
 *
 *    1, se as ocorrencias do dado padrao foram substituidas pelo novoPadrao
 *    0, caso contrario
 *
 * Exemplo:
 *
 *     char seq1[15] = "+*+-+*+-*++";
 *     char seq2[15];
 *     char seq3[15];
 *
 *     char padrao[5] = "+*+"
 *     char novoPadrao[5] = "*-*"
 * 
 *     substituiPadrao(seq1, padrao, novoPadrao, seq2); // seq2 sera "*-*-*-*-*++"
 *     substituiPadrao(seq2, padrao, novoPadrao, seq3);  // seq3 sera "*-*-*-*-*++" 
 * 
 */
int substituiPadrao(char str[], char padrao[], char novoPadrao[], char targetStr[]) {

/*
 * Nota do Programador: A lógica dessa função é percorrer o vetor inicial de tamanho actualSizeStr e comparar
 * seus caracteres com o caractere inicial de padrao(padrao[0]), os caracteres diferentes serão copiados para 
 * targetStr, mas caso o um digito de str seja igual ao primeiro digito de padrao, um laço é acionado 
 * visando conferir se padrao esta contindo inteiramente depois daquela posição.Se estiver contido o indice copia 
 * o novo padrão apartir da posição onde estaria o primeiro. depois disso continua-se a comparar/copiar str.
 * até encontrar(ou não) uma nova ocorrência de padrao.
 * Trata-se de uma cópia seletiva para targetStr, copiando a string com a nova sequencia;
 */


	int actualSizeStr = strlen(str) + 1, actualSizeSequence = strlen(padrao), counter = 0, copy, iDidSomething = 0;	

	for(int i = 0, j = 0; i < actualSizeStr ; i++){

		copy = 0;// copy indica quando é necessário copiar(0) ou não(1) de str.

		if(str[i] == padrao[0]){
			for(int j = 0; j < actualSizeSequence; j++){
				if(str[i+j] == padrao[j]){
					counter++; // counter é uma variável contadora, usada para conferir se padrão está inteiramente em str.
				}else{
					counter=0;
					break;
				}
			}
		}

		if(counter == actualSizeSequence){// indica se padrao está inteiramente em str.
			iDidSomething = 1;//variável que indica se havia foi removido a sequencia alguma vez.
			counter = 0;
			copy = 1;//aciona a variável para não copiar de str, e iniciar a cópia do novo padrão.
		}

		if(copy == 0){//faz a copia de str para targetStr quando necessário.
			targetStr[j] =  str[i];
			j++;
		}else{
			for(int k = 0; k < strlen(novoPadrao); k++){ //faz a copia de novoPadrao para targetStr quando necessário.
				targetStr[j] = novoPadrao[k];
				j++;
			}
			i = i + strlen(novoPadrao) - 1;	 // faz o salta pulando o novo padrao copiado, para não subscrever com o antigo padrão.
		}
		
	}

	return iDidSomething;

}
