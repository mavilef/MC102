//Marcelo Martins Vilela Filho RA 202619 - Engenharia de Computação

/*Objetivo: O programa tem como objetivo fazer operações com uma lista de RA's 
inseridos pelo usuário, as operações consistem em ordenar a lista , inserir um RA
á lista, encontrar a posição de um RA na lista, remover um RA da lista e imprimir na
tela á lista. 

Entradas: Como entrada são utilizadas a o numero inicial de RA's da lista, a lista de RA's
e a as operações: 'c' para ordenar a lista em  ordem crescente, 'd' para para ordenar a lista
em ordem decrescente, 'b' para buscar um RA na lista e imprimir sua posição, 'i' para inserir
um RA na lista, 'r' para remover um RA da lista e 'p' para imprimir a lista de RA's na tela.

OBS: A descrição de cada função está comentada em seu escopo.   

Saidas: como saida temos a efetivação da função escolhida pelo usuário.
*/

#include  <stdio.h>
#include <string.h>

int sorted = 0;

	/* Sorted é uma variável global que inidica a situação de ordenação
	 * ordenado crescente, ordenado decrescente e desordenado
	 * é explicado com mais detalhes na função verifySortion 
	 * que verifica a ordenação.
	 */

int verifyIfBelongs(int vector[], int vectorSize , int numberToBeVerified);
void vectorReader(int vector[], int vectorSize);
void printVector(int vector[], int vectorSize);
void crescentBubbleSort(int vector[], int vectorSize);
void decrescentBubbleSort(int vector[], int vectorSize);
int binarySearch(int vector[], int vectorSize , int numberSearched);
int insert(int vector[], int vectorSize, int numberToBeInserted, int maxSize);
int removeNumber(int vector[], int vectorSize, int numberToBeRemoved);
int verifySortion(int vector[], int vectorSize);


int main(){

	/* Função principal:
	 * É colocado um laço do que aguarda o usuario digitar uma operação e as realiza 
	 * tais operações são realizadas utilizando chamadas de funções.
	*/

	int listSize;
	scanf("%d",&listSize);

	const int sizeMax = 150;
	int list[sizeMax];
	vectorReader(list, listSize);
	
	char operation;

	for(;operation != 's';){

		sorted = verifySortion(list, listSize);

		int numberToSearch, numberToInsert, numberToRemove;

		scanf("%c",&operation);

		switch(operation){

			case 'c':
				crescentBubbleSort(list,listSize);
				break;

			case 'p':
				printVector(list,listSize);
				break;
	
			case 'd':
				decrescentBubbleSort(list,listSize);
				break;

			case 'i':
				scanf("%d",&numberToInsert);
				listSize = listSize + insert(list,listSize,numberToInsert,sizeMax);			
				break;

			case 'r':
				scanf("%d",&numberToRemove);
				listSize = listSize - removeNumber(list, listSize, numberToRemove);			
				break;

			case 'b':

				scanf("%d",&numberToSearch);
				binarySearch(list,listSize,numberToSearch);			
				break;
				
			case 's':
				return 0;
				

		}


	}

	return 0;

}

int verifyIfBelongs(int vector[], int vectorSize , int numberToBeVerified){

	/* Essa função verifica se determinado elemento pertence a um vetor
	 * retorna 1 se ja pertencer e retorna 0 se não pertencer.
	 */

	for(int i = 0; i<vectorSize; i++){
		if(numberToBeVerified == vector[i])
			return 1; 
	}

	return 0;

}

void vectorReader(int vector[], int vectorSize){

	/* Essa faz a leitura dos dados de um vetor, dado seu tamanho.
	 */


	for(int i = 0; i<vectorSize; i++)
		scanf("%d",&vector[i]);
	
}

void printVector(int vector[], int vectorSize){

	/* Essa função verifica se determinado elemento pertence a um vetor
	 * retorna 1 se ja pertencer e retorna 0 se não pertencer.
	 */


	if(vectorSize != 0){
		for(int i = 0; i<vectorSize; i++){
			if(vector[i] != 0){
				printf("%d ",vector[i]);
			}
		}
	
		printf("\n");
	}
}

void crescentBubbleSort(int vector[], int vectorSize){

	/* Esta função faz o BubbleSort(Algorítmo de ordenação que compara sequencialmente 
	 * numeros dois a dois e inverte sua ordem se o segundo numero for maior que o primeiro)
	 * crescente.
	 */

	int temp;

	for(int i = vectorSize-1; i>=1; i--){
		for(int j = 0; j<vectorSize-1; j++){
			if(vector[j]>vector[j+1]){
				temp = vector[j];
				vector[j] = vector[j+1];
				vector[j+1] = temp;
			}
		}
	}

	sorted = 1;
}

void decrescentBubbleSort(int vector[], int vectorSize){

	/* Esta função faz o BubbleSort(Algorítmo de ordenação que compara sequencialmente 
	 * numeros dois a dois e inverte sua ordem se o segundo numero for menor que o primeiro)
	 * decrescente.
	 */

	int temp;

	for(int i = vectorSize-1; i>=1; i--){
		for(int j = 0; j<vectorSize-1; j++){
			if(vector[j]<vector[j+1]){
				temp = vector[j];
				vector[j] = vector[j+1];
				vector[j+1] = temp;
			}
		}
	}

	sorted = 2;
}

int binarySearch(int vector[], int vectorSize , int numberSearched){

	/* Faz o algorítmo de busca binária, para encontrar um determinado numero em um vetor
	 * e imprimir sua posição(O algorítmo consiste em fazer sucessivas verificações em subvetores
	 * de um vetor ordenado, de forma que o subvetor é gerador apartir da relação (maior ou menor) 
	 * entre o numero a ser encontrado e o numero localizado no meio do vetor.
	 * é importante ressaltar que há pequenas alterações entre vetor ordenados na forma decrescente e 
	 * na forma crescente.
	 */


	int init = 0, end = vectorSize - 1, middle;

	/* Binary search para um vetor crescente.
	 */


	if(sorted == 1){
		while(init <= end){

			middle = (init + end)/2;
			
			printf("%d ", middle);

			if(vector[middle] == numberSearched){		
				printf("\n%d esta na posicao: %d\n", numberSearched, middle);
				return 0;
			}
			else if(vector[middle] > numberSearched){
				end = middle - 1;
			}
			else if(vector[middle] < numberSearched){
				init = middle + 1;
			}		
		}
	
	printf("\n%d nao esta na lista!\n", numberSearched);	
	return 0;	

	/* Binary search para um vetor decrescente.
	 */


	}else if(sorted == 2){

		while(init <= end){

			middle = (init + end)/2;
			
			printf("%d ", middle);

			if(vector[middle] == numberSearched){		
				printf("\n%d esta na posicao: %d\n", numberSearched, middle);
				return 0;
			}
			else if(vector[middle] < numberSearched){
				end = middle - 1;
			}
			else if(vector[middle] > numberSearched){
				init = middle + 1;
			}		
		}
	
	printf("\n%d nao esta na lista!\n", numberSearched);	
	return 0;	

	
	/* Mensagem de erro para um vetor desordenado.
	 */

	}else{
		printf("Vetor nao ordenado!\n");
		return 0;
	}


}

int insert(int vector[], int vectorSize, int numberToBeInserted, int maxSize){

	/* Na inserção, basicamente, é verificado se o numero ja pertence ao vetor
	 * se não, é adicionado á ultima posição do vetor e, conforme ordenação 
	 * prévia é chamada a função BubbleSort Crescente ou Decrescente.
	 * caso o elemento já exista é impresso uma mensagem de erro. 
	 */


	if(vectorSize == maxSize){
		printf("Limite de vagas excedido!\n");
		return 0;
	}

	if(verifyIfBelongs(vector,vectorSize,numberToBeInserted) == 0){

		if(sorted == 0){

			vector[vectorSize] = numberToBeInserted;
			vectorSize++;

		}else if(sorted == 1){

			vector[vectorSize] = numberToBeInserted;
			vectorSize++;
			crescentBubbleSort(vector,vectorSize);
			

		}else if(sorted == 2){

			vector[vectorSize] = numberToBeInserted;
			vectorSize++;
			decrescentBubbleSort(vector,vectorSize);

		}

		return 1;
	
	}else{

	printf("Aluno ja matriculado na turma!\n");
	return 0;
	
	}

}

int removeNumber(int vector[], int vectorSize, int numberToBeRemoved){

	/* A função remover utiliza de um laço que quando percorre os elementos 
	 * e se é encontrado o numero que precisa ser removido no vetor, então
	 * é criado uma copia do vetor que subcreve o vetor inicial sem o numero desejado.
	 * caso não encontre o numero ou não haja valore sno vetor é impressa uma mensagem de erro.
	 */


	if(vectorSize == 0){
		printf("Nao ha alunos cadastrados na turma!\n");
		return 0;
	}

	int vectorCopy[vectorSize];

	for(int k = 0; k<vectorSize; k++)
		vectorCopy[k] = vector[k]; 

	for(int i = 0; i<vectorSize; i++)
		if(vector[i] == numberToBeRemoved){

			for(int j = i; j < vectorSize; j++)
				vector[j] = vectorCopy[j+1]; 

			
			return 1;
		}
	

	printf("Aluno nao matriculado na turma!\n");
	return 0;

}

int verifySortion(int vector[], int vectorSize){

	/* A função verifica a ordenação do vetor:
	 * e altera a condição da variável global que indica o tipo da ordenação do vetor
	 * sorted = 0(se desordenado), sorted = 1 (se crescente), sorted = 2 (se decrescente).
	 */

	
	if(vector[0]>vector[1]){
		for(int i = 0; i < vectorSize - 1;i++){
			if(vector[i] < vector[i+1]){
				return 0;
			}
			
		}
		return 2;
	}else if(vector[0]<vector[1]){

		for(int i = 0; i < vectorSize - 1;i++){
			if(vector[i] > vector[i+1]){
				return 0;
			}
			
		}

		return 1;
	}

	return 0;
}


