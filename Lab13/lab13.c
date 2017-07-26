/* Laboratorio 15 - Conjuntos
 * Nome: Marcelo Martins Vilela Filho
 * RA: 202619
 */

/*
 * Objetivos: O programa tem como objetivo fazer operações com conjuntos, taios operações 
 * são baseadas nas  operações encontradas na matemática em Teoria dos conjuntos.
 * 
 * Entradas:A entrada está na função main, que é dada neste laboratório,e basicamente 
 * consiste na inserção de elementos de conjuntos, vericação se o elemento pertence ou não ao
 * conjunto , verificação se um conjunto está contido ou não em outro, adição de elementos
 * em conjuntos, subtração de elementos em conjuntos, união de conjuntos, intersecção de conjunção
 * diferença de conjuntos, e o complementar de um conjunto em relação ao conjunto universo.
 *
 * Saida: Consiste basicamente no resultado da operação digitada pelo usuário.

 */

#include <stdio.h>

/* Funcao: pertence
 *
 * Parametros:
 *   conj: vetor contendo o conjunto de entrada
 *    tam: tamanho do conjunto
 *  letra: elemento a ser verificado pertinencia
 *
 * Retorno:
 *   1 se letra pertence a conj e 0 caso contrario
 */
int pertence(char conj[], int tam, char letra){

/* A função pertence foi feita percorrendo o conjunto através de um indice, se fosse encontrado um elemento
 * no vetor que fosse igual ao pesquisado, acionaria alteraria o valor de uma variavel indicadora que 
 * sinalizaria que o elemento pertence ao conjunto
 *
 */
	unsigned int setMembership = 0;

	for(unsigned int i = 0; i < tam; i++){

		if(conj[i] == letra){
			setMembership = 1;
			break;
		}else{
			setMembership = 0;
		}
	}

	return setMembership;	
  /* Implementar a funcao e trocar o valor de retorno */
}

/* Funcao: contido
 *
 * Parametros:
 *   conj1: vetor contendo um conjunto de entrada
 *   conj2: vetor contendo um conjunto de entrada
 *    tam1: tamanho do conjunto conj1
 *    tam2: tamanho do conjunto conj2
 *
 * Retorno:
 *   1 se conj1 esta contido em conj2 e 0 caso contrario
 */
int contido(char conj1[], char conj2[], int tam1, int tam2){

/* A função contido utiliza dois indice um no primeiro conjunto e outro no segundo, através de laços
 * são comparados todos os elementos dos dois conjuntos, e quando houver elementos iguais uma variável 
 * contadora é incrementada.
 * Ao fim dos testes se o valor da variavel contadora é igual ao numero de elementos do primeiro vetor
 * então uma variavel indicadora é incrementada indicando que o primeiro conjunto está contido no segundo.
 * caso não, a variável indicadora não é acionada fazendo com que não seja indicado que o conjunto 
 * não está contido no outro.
 */

	
	int temp = 0, subset = 0;	
	
	for(unsigned int i = 0; i< tam1; i++)
		for(unsigned int j = 0; j < tam2; j++){
			if(conj1[i] == conj2[j])	
				temp++;	
		}

	if(temp == tam1)
		subset = 1;

  return subset;
}

/* Funcoes: adicao e subtracao
 *
 * Parametros:
 *   conj: vetor contendo o conjunto que tera incluso ou removido o elemento
 *    tam: tamanho do conjunto
 *  letra: elemento a ser adicionado ou removido
 *
 * Retorno:
 *   tamanho do conjunto apos a operacao.
 */
int adicao(char conj[], int tam, char letra){

/*  A função adição, verifica se o elemento pertence ao conjunto, caso não ela aumenta o tamanho do vetor 
 * e adiciona o elemento na ultima posição do conjunto.
 */


	unsigned int newSize = tam;

	if(pertence(conj, tam, letra) == 0){
		newSize++;
		conj[newSize - 1] = letra;
	}	

  return newSize;
}

int subtracao(char conj[], int tam, char letra){

/* A função subtração através de for's encaixados encontra o elemento se for encontrado grava o indice 
 *  e move o valor encontrado para ultima posição do vetor e então é diminuido o tamanho do vetor.
 */




	unsigned int newSize = tam;

	if(pertence(conj, tam, letra) == 1){
		for(unsigned int i = 0; i < tam; i++){
			if(conj[i] == letra)
				for(unsigned int j = i+1; j < tam; j++)
					conj[j-1] = conj[j];
		}
		newSize--;
	}

  return newSize;
}

/* Funcoes: uniao, intersecao e diferenca
 *
 * Parametros:
 *   conjRes: vetor contendo o conjunto de saida/resultado da operacao
 *     conj1: vetor contendo o conjunto de entrada do primeiro operando
 *     conj2: vetor contendo o conjunto de entrada do segundo operando
 *      tam1: tamanho do conjunto conj1
 *      tam2: tamanho do conjunto conj2
 *
 * Retorno:
 *   tamanho do conjunto de saida conjRes.
 */
int uniao(char destRes[], char conj1[], char conj2[], int tam1, int tam2){

/* A função união em realiza primeiramente uma copia do primeiro conjunto no conjunto resultado
 * então , através um laço é verificado os elementos no segundo conjunto que são diferentes do 
 * primeiro, os que forem são adicionados ao conjunto resultado.
 */



	unsigned int finalSize = 0;

		for(unsigned int i = 0 ; i < tam1; i++){
			destRes[i] = conj1[i];
				finalSize++;
		}

		for(unsigned int i = 0; i < tam2; i++){
			if(pertence(conj1,tam1,conj2[i]) == 0){
				destRes[finalSize] = conj2[i];
					finalSize++;
			}
		}
				
  return finalSize;
}

int intersecao(char destRes[], char conj1[], char conj2[], int tam1, int tam2){

/* A função interseção , através de laços aninhados compara todos os elementos dos dois conjuntos 
 * quando algum elemento é igual nos dois conjuntos, é incrementados o tamanho do vetor resultado 
 * e adicionado o elemento na ultima posição dele.
 */

		unsigned int finalSize = 0;
		
		for(unsigned int i = 0; i < tam1; i++)
			for(unsigned int j = 0; j<tam2; j++)
				if(conj1[i] == conj2[j]){
					destRes[finalSize] = conj1[i];
						finalSize++;
				}	

  return finalSize;
}

int diferenca(char destRes[], char conj1[], char conj2[], int tam1, int tam2){

/* A função diferença verifica se os elementos de conjunto um não existem no conjunto 2
 * se não existirem, uma variavel indicadora é acionada, o conjunto final tem seu tamanho aumentado
 * e o elemento é adicionado á primeira posição do conjunto final(que teve seu tamanho incrementado).
 * A verificação é feita utilizando for's encaixados.
 */




		unsigned int finalSize = 0, exclusive;
	
		for(unsigned int i = 0; i < tam1; i++){
			exclusive = 1;
			for(unsigned int j = 0; j < tam2; j++){
				if(conj1[i] == conj2[j]){
					exclusive = 0;
					break;
				}
			}
			
			if(exclusive == 1){
				destRes[finalSize] = conj1[i];
				finalSize++;
			}
		} 
			

  return finalSize;
}


/* Funcao: complemento
 * Guarda em conjRes o resultado da operação U-conj, onde U é o conjunto 
 * de todas as letras minusculas do alfabeto ingles
 *
 * Parametros:
 *   conjRes: vetor contendo o conjunto de saida/resultado da operacao
 *      conj: vetor contendo o conjunto de entrada do primeiro operando
 *       tam: tamanho do conjunto conj
 *
 * Retorno:
 *   tamanho do conjunto de saida conjRes.
 */
int complemento(char conjRes[], char conj[], int tam){

/* A função complemento compara todas as letras do alfabeto inglês e 
 * com um conjunto, a priori é considerado que o elemento não pertence ao
 * conjunto (inicializando a variavel indicadora com o valor verdadeiro) 
 * se a indicadora continuar com a inalterada após toda a verificação,
 * o tamanho do conjunto final é incrementado e a letra que foi comparada
 * é adicionada a primeira posição do conjunto final.
 */




	unsigned int finalSize = 0, exclusive;

	for(char i = 'a'; i <= 'z'; i++){
			exclusive = 1;

		for(unsigned int j = 0; j < tam; j++){
			if(i == conj[j]){
				exclusive = 0;
				break;
			}
		}

		if(exclusive == 1){
			conjRes[finalSize] = i;
			finalSize++;
		}

	
		
	}	

  return finalSize;
}

