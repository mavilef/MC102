#include <stdio.h>
#include <stdlib.h>

/*
------------------------------------------------------------------------------------------------------------
Aluno(a):Marcelo Martins Vilela Filho
RA:202619
------------------------------------------------------------------------------------------------------------
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


/*
------------------------------------------------------------------------------------------------------------
void ordena(int *conj, int tam);


Esta funcao deve ordenar um conjunto dado como parametro.

Parametros:

- conj -> Ponteiro para o conjunto;
- tam -> Quantidade de elementos do conjunto;

------------------------------------------------------------------------------------------------------------
*/

void ordena(int *conj, int tam) {

	/*O algorítmo de ordenação usado foi o BubbleSort.
	 */

	int aux;

	for(int i = 0; i<tam; i++){
		for(int j = 0; j<tam-1; j++){
			if(conj[j]>conj[j+1]){
				aux = conj[j];
				conj[j] = conj[j+1];
				conj[j+1] = aux;	
			}	
		}
	}

}

/*
------------------------------------------------------------------------------------------------------------
int pertence(int *conj, int tam, int elemento);


Esta funcao deve verificar se um elemento esta presente no conjunto.

Parametros:

- conj -> Ponteiro para o conjunto;
- tam -> Quantidade de elementos do conjunto;
- elemento -> Elemento no qual deve ser ser verificado se esta presente no conjunto;

Retorno

- 1 Caso o elemento PERTENCA conjunto;
- 0 Caso o elemento NAO PERTENCA ao conjunto;

------------------------------------------------------------------------------------------------------------
*/

int pertence(int *conj, int tam, int elemento) {
	
/* A função pertence foi feita percorrendo o conjunto através de um indice, se fosse encontrado um elemento
 * no vetor que fosse igual ao pesquisado, retorna 1, caso contrário, retorna 0;
 *
 */

	for(int i = 0; i<tam; i++){
		if(conj[i] == elemento){
			return 1;
		}	
	}

  return 0;
}

/*
------------------------------------------------------------------------------------------------------------
int contido(int *conj_A, int *conj_B, int tam_A, int tam_B);


Esta funcao deve verificar se o conjunto A esta contido no conjunto B.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_B -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;

Retorno

- 1 Caso o conjunto A ESTEJA CONTIDO no conjunto B;
- 0 Caso o conjunto A NAO ESTEJA CONTIDO no conjunto B;

------------------------------------------------------------------------------------------------------------
*/

int contido(int *conj_A, int *conj_B, int tam_A, int tam_B) {

/* A função contido utiliza dois indice um no primeiro conjunto e outro no segundo, através de laços
 * são comparados todos os elementos dos dois conjuntos, e quando houver elementos iguais uma variável 
 * contadora é incrementada.
 * Ao fim dos testes se o valor da variavel contadora é igual ao numero de elementos do primeiro vetor
 * então uma variavel indicadora é incrementada indicando que o primeiro conjunto está contido no segundo.
 * caso não, a variável indicadora não é acionada fazendo com que não seja indicado que o conjunto 
 * não está contido no outro.
 */


	int subset = 0, cont = 0;

	for(int j = 0; j<tam_A; j++){
		for(int i = 0, j = 0; i<tam_B; i++){//percorre o conjunto B.
			if(conj_B[i] == conj_A[j]){
				cont++;
				break;
			}
		}
	}

	if(cont == tam_A){
		subset = 1;
	}
		
  return subset;
}

/*
------------------------------------------------------------------------------------------------------------
int* init(int *tam, int *cap);


Esta funcao deve inicializar um vetor(conjunto).

Parametros:
- tam -> Ponteiro para a quantidade de elementos do conjunto;
- cap -> Ponteiro para a capacidade de elementos do conjunto;

OBS:
- A capacidade inicial do vetor(conjunto) deve ser 2.
- O quantidade inicial de elementos no vetor(conjunto) deve ser zero.
- Nao confundir capacidade com quantidade de elementos.

Retorno

- Ponteiro para o conjunto;

------------------------------------------------------------------------------------------------------------
*/

int* init(int *tam, int *cap) {

/*  A função inicializa um conjunto, através da função calloc.
 */


	*cap = 2;
	*tam = 0;

	int *conj = calloc((*cap), sizeof(int));//aloca memória para o conjunto.
	
  return conj;
}

/*
------------------------------------------------------------------------------------------------------------
int* adicao(int *conj, int *tam, int *cap, int elemento);


Esta funcao deve adicionar um novo elemento no conjunto, ou seja, se o elemento ja pertence ao 
conjunto o mesmo NAO deve ser adicionado.

Parametros:
- conj -> Ponteiro para o conjunto;
- tam -> Ponteiro para a quantidade de elementos do conjunto;
- cap -> Ponteiro para a capacidade de elementos do conjunto;
- elemento -> Elementos para ser adicionado;

OBS:
- Ao adicionar um novo elemento o tamanho atual do conjunto devera ser atualizado;
- Caso o ponteiro para o conjunto seja NULL, o conjunto devera ser alocado com uma capacidade de dois (02) 
e a atualizacao da capacidade deverar ser feita;
- Caso a quantidade de elementos do conjunto seja igual a capacidade do conjunto e um novo elemento tenha que 
ser inserido, então o conjunto tera de ser realocado com o dobro da capacidade e a capcidade do conjunto 
devera ser atualizada;

Retorno

- Ponteiro para o conjunto;

------------------------------------------------------------------------------------------------------------
*/

int* adicao(int *conj, int *tam, int *cap, int elemento) {

/*  A função adição, verifica se o elemento pertence ao conjunto, caso não ela aumenta o tamanho do vetor 
 * e adiciona o elemento na ultima posição do conjunto.Alêm disso, é verificado se o vetor ja existe
 * caso não, ele é inicializado pela função init.
 */


	if(conj == NULL)//inicializa vetores inexistentes.
		conj = init(tam, cap);

	if(pertence(conj, *tam, elemento) == 0){
		if(*cap == *tam){
			
			int *aux = NULL;

			(*cap)= (*cap) * 2; 

			aux = calloc(*cap, sizeof(int));
			
			for(int i = 0; i<(*tam); i++){
				aux[i] = conj[i];
			}

			free(conj);
			conj = aux;
						
		}

			conj[*tam] = elemento;
			(*tam)++; 
	
	}
	
  return conj;
}

/*
------------------------------------------------------------------------------------------------------------
int* subtracao(int *conj, int *tam, int *cap, int elemento);


Esta funcao deve remover um elemento no conjunto caso ele exista.

Parametros:
- conj -> Ponteiro para o conjunto;
- tam -> Ponteiro para a quantidade de elementos do conjunto;
- cap -> Ponteiro para a capacidade de elementos do conjunto;
- elemento -> Elementos para ser removido;

OBS:
- Ao remover um elemento o tamanho atual do conjunto devera ser atualizado;
- Caso a capacidade seja maior que dois (02) e a quantidade de elementos do conjunto seja menor ou igual que 1/4 da capacidade do conjunto, então 
o conjunto tera de ser realocado com a metade da capacidade e a capacidade do conjunto devera ser atualizada.

Retorno

- Ponteiro para o conjunto;

------------------------------------------------------------------------------------------------------------
*/

int* subtracao(int *conj, int *tam, int *cap, int elemento) {

/* A função subtração através de for's encaixados encontra o elemento se for encontrado grava o indice 
 *  e move o valor encontrado para ultima posição do vetor e então é diminuido o tamanho do vetor.
 */

	int *aux = NULL;	
	
	if(pertence(conj, *tam, elemento)){

		for(int i = 0; i<*tam; i++){
			if(conj[i] == elemento){
				for(int j = i; j+1<(*tam); j++){
					conj[j]=conj[j+1];
				}
			}
			
		}

		(*tam)--;
	}


		if((*cap)>2 && (*tam)<=(*cap)/4){

			(*cap) = (*cap)/2;
			aux = calloc((*cap),sizeof(int));

			for(int i = 0; i<(*tam); i++){
				aux[i]=conj[i];
			}
		
			free(conj);
			conj=aux;

		}





  return conj;
}

/*
------------------------------------------------------------------------------------------------------------
int* uniao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C);


Esta funcao deve computar a uniao entre os conjuntos A e B. O resultado dessa uniao deve ser armazenado em 
um novo conjunto C.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_b -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;
- tam_C -> Ponteiro para a quantidade de elementos do conjunto resultante;
- cap_C -> Ponteiro para a capacidade de elementos do conjunto resultante;

OBS:
- O tamanho atual e a capacidade do conjunto resultante C devera seguir a logica apresentada nas funcoes 
init e adicao.
- Os valores de quantidade de elementos e capacidade do conjunto resultante C devem ser atualizados 
respectivamente nos parametros tam_C e cap_C.

Retorno

- Ponteiro para o conjunto C;

------------------------------------------------------------------------------------------------------------
*/

int* uniao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {

/* A função união em realiza primeiramente uma copia do primeiro conjunto no conjunto resultado
 * então , através um laço é verificado os elementos no segundo conjunto que são diferentes do 
 * primeiro, os que forem são adicionados ao conjunto resultado.
 */



	int *conj_C = NULL;

	conj_C = init(tam_C, cap_C); 

	for(int i = 0; i<tam_A; i++){
		conj_C = adicao(conj_C, tam_C, cap_C, conj_A[i]);
	}

	for(int i = 0; i<tam_B; i++){
		conj_C = adicao(conj_C, tam_C, cap_C, conj_B[i]);
	}


  return conj_C;
}

/*
------------------------------------------------------------------------------------------------------------
int* intersecao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C);


Esta funcao deve computar a intersecao entre os conjuntos A e B. O resultado dessa intersecao deve ser 
armazenada em um novo conjunto C.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_b -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;
- tam_C -> Ponteiro para a quantidade de elementos do conjunto resultante;
- cap_C -> Ponteiro para a capacidade de elementos do conjunto resultante;
- elemento -> Elementos para ser removido;

OBS:
- O tamanho atual e a capacidade do conjunto resultante C devera seguir a logica apresentada nas funcoes 
init e adicao.
- Os valores de quantidade de elementos e capacidade do conjunto resultante C devem ser atualizados 
respectivamente nos parametros tam_C e cap_C.

Retorno

- Ponteiro para o conjunto C;

------------------------------------------------------------------------------------------------------------
*/

int* intersecao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {

/* A função interseção , através de laços aninhados compara todos os elementos dos dois conjuntos 
 * quando algum elemento é igual nos dois conjuntos, é incrementados o tamanho do vetor resultado 
 * e adicionado o elemento na ultima posição dele.
 */


	int *conj_C = NULL;

	conj_C = init(tam_C, cap_C); 

	for(int i = 0; i<tam_A; i++){
		if(pertence(conj_B, tam_B, conj_A[i]))
			conj_C = adicao(conj_C, tam_C, cap_C, conj_A[i]);
		
	}


  return conj_C;
}

/*
------------------------------------------------------------------------------------------------------------
int* diferenca(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C);


Esta funcao deve computar a diferenca entre os conjuntos A e B. O resultado dessa diferenca deve ser 
armazenada em um novo conjunto C.

Parametros:
- conj_A -> Ponteiro para o conjunto A;
- conj_b -> Ponteiro para o conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;
- tam_C -> Ponteiro para a quantidade de elementos do conjunto resultante;
- cap_C -> Ponteiro para a capacidade de elementos do conjunto resultante;
- elemento -> Elementos para ser removido;

OBS:
- O tamanho atual e a capacidade do conjunto resultante C devera seguir a logica apresentada nas funcoes 
init e adicao.
- Os valores de quantidade de elementos e capacidade do conjunto resultante C devem ser atualizados 
respectivamente nos parametros tam_C e cap_C.

Retorno

- Ponteiro para o conjunto C;

------------------------------------------------------------------------------------------------------------
*/

int* diferenca(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C) {

/* A função diferença verifica se os elementos de conjunto um não existem no conjunto 2
 * se não existirem, uma variavel indicadora é acionada, o conjunto final tem seu tamanho aumentado
 * e o elemento é adicionado á primeira posição do conjunto final(que teve seu tamanho incrementado).
 * A verificação é feita utilizando for's encaixados.
 */


	int *conj_C = NULL;
	int exclusive;

	conj_C = init(tam_C, cap_C); 

	for(int i = 0; i<tam_A; i++){

		exclusive = 1;

		for(int j = 0; j<tam_B; j++)
			if(conj_A[i] == conj_B[j]){
				exclusive = 0;
				break;
			}

		if(exclusive){
			conj_C = adicao(conj_C, tam_C, cap_C, conj_A[i]);			 
		}			
	}


  return conj_C;

}
