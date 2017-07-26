#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int ra, telefone;
  char nome[100];
} Aluno;

typedef struct {
  int armazenado;
  int capacidade;
  Aluno *alunos;
} Base;

/* Funcao: criar_base
 *
 * Inicializa a base ja com a capacidade.
 *
 * Parametros:
 *   base: ponteiro para a base
 *   n: quantidade maxima de alunos
 */
void criar_base(Base *base, int n) {

	(*base).armazenado = 0;
	(*base).capacidade = n;

	(*base).alunos = malloc((*base).capacidade*sizeof(Aluno));

	printf("Base criada.\n");


}

/* Funcao: buscar
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 *
 * Retorno:
 *   Indice do registro com RA no vetor de alunos
 *   -1 caso contrario.
 */
int buscar(Base *base, int ra) {
	
	int rangeToSearch = (*base).armazenado;
	
	for(int i = 0; i < rangeToSearch; i++){
		if((*base).alunos[i].ra == ra){
			return i;
		}

	}

  return -1;
}

/* Funcao: imprimir
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 */
void imprimir(Base *base, int ra) {

	int doINeedToPrint;
	doINeedToPrint = buscar(base, ra);

	if(doINeedToPrint == -1){
		printf("Aluno %d nao encontrado.\n", ra);
	}else{
		printf("%d - %d - %s\n", (*base).alunos[doINeedToPrint].ra, (*base).alunos[doINeedToPrint].telefone, (*base).alunos[doINeedToPrint].nome);
	}

}

/* Funcoes: adicionar
 *
 * Inclui um registro sem permitir RAs duplicados.
 * A quantidade de alunos deve ser atualizada.
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 *   telefone: numero do telefone
 *   nome: string com o nome
 */
void adicionar(Base *base, int ra, int telefone, char *nome) {

	int doINeedToChangeOrRemove = buscar(base, ra);

	if(doINeedToChangeOrRemove == -1 && (*base).armazenado<(*base).capacidade){

		int lastPosition = (*base).armazenado;

		strcpy((*base).alunos[lastPosition].nome, nome);
		(*base).alunos[lastPosition].ra = ra;
		(*base).alunos[lastPosition].telefone = telefone;

		(*base).armazenado = (*base).armazenado + 1;

		printf("Adicionado: %d - %d - %s\n", ra, telefone, nome); 

	}else if(doINeedToChangeOrRemove != -1){


		strcpy((*base).alunos[doINeedToChangeOrRemove].nome, nome);
		(*base).alunos[doINeedToChangeOrRemove].ra = ra;
		(*base).alunos[doINeedToChangeOrRemove].telefone = telefone;

		printf("Alterado: %d - %d - %s\n", ra, telefone, nome); 


	}else if((*base).armazenado==(*base).capacidade){

		printf("Erro: base cheia.\n");

	}	
}

/* Funcoes: remover
 *
 * Remove um registro se o ra estiver presente.
 * O quantidade de registro deve ser atualizada.
 *
 * Parametros:
 *   base: ponteiro para a base
 *   ra: numero do RA
 */
void remover(Base *base, int ra) {

	int didINeedToRemove = 0;
	
	for(int i = 0; i<(*base).armazenado; i++){

		if((*base).alunos[i].ra == ra){

			didINeedToRemove = 1;

			for(int j = i; j < (*base).armazenado - 1; j++)
				(*base).alunos[j]=(*base).alunos[j+1];

			(*base).armazenado--;
				
		}

	}

	if(didINeedToRemove == 1){

		printf("Aluno %d removido.\n", ra);

	}else{
		printf("Aluno %d nao encontrado.\n", ra);

	}



}

/* Funcao: liberar_base
 *
 * Libera a memoria de todos alunos da base.
 * Deve deixar a base com capacidade e quantidade armazenada igual a zero
 * e o ponteiro para alunos igual a NULL.
 *
 * Parametros:
 *   base: ponteiro para a base
 */
void liberar_base(Base *base) {

	
	free((*base).alunos);
	(*base).alunos = NULL;

	(*base).armazenado = 0;
	(*base).capacidade = 0;
	
}
