#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordena(int *conj, int tam);
int pertence(int *conj, int tam, int elemento);
int contido(int *conj_A, int *conj_B, int tam_A, int tam_B);
int* init(int *tam, int *cap);
int* adicao(int *conj, int *tam, int *cap, int elemento);
int* subtracao(int *conj, int *tam, int *cap, int elemento);
int* uniao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C);
int* intersecao(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C);
int* diferenca(int *conj_A, int *conj_B, int tam_A, int tam_B, int *tam_C, int *cap_C);


/*
------------------------------------------------------------------------------------------------------------
void print(char comando[], int *conj, int tam, int cap);


Esta funcao imprime o comando junto com os dados do conjunto (elementos, tamanho e capacidade) que sofreu a acao.

Parametros:

- comando -> Comando no formato de string;
- conj -> Conjunto que sofreu a acao;
- tam -> Quantidade de elementos do conjunto;
- cap -> Capacidade do conjunto;


------------------------------------------------------------------------------------------------------------
*/

void print(char comando[], int *conj, int tam, int cap) {
  int i;

  /* Conjunto e ordenado antes de imprimir */
  ordena(conj, tam);

  /* Dados do conjunto */
  printf("%s{", comando);

  for(i = 0; i < tam; i++) {
    (i == 0) ? printf("%d", *(conj + i)) : printf(", %d", *(conj + i));
  }

  printf("}, tamanho = %d, capacidade = %d\n", tam, cap);
}

/*
------------------------------------------------------------------------------------------------------------
int* atribuicao(char *str, int *conj, int *tam ,int *cap);


Esta funcao adiciona o valores numericos de um comando em um conjunto.

Parametros:

- str -> Valores numericos de um comando separados por virgula;
- conj -> Conjunto que tera seus valores alterados;
- tam -> Quantidade de elementos do conjunto;
- cap -> Capacidade do conjunto;


Retorno

- Um ponteiro para o conjunto.


------------------------------------------------------------------------------------------------------------
*/

int* atribuicao(char *str, int *conj, int *tam ,int *cap) {
  char *temp = NULL;
  unsigned long i = 0;
  unsigned long j = 0;

  temp = (char*) malloc((strlen(str) + 1) * sizeof(char));
  strcpy(temp, str);
  conj = init(tam, cap);

  for (i = 0, j = 0; i <= strlen(str); i++){

    if(*(str + i) == ',' || *(str + i) == '\0') {
      *(temp + j) = '\0';

      /* Elementos sao adicionados no conjunto */
      if(j > 0) { 
        conj = adicao(conj, tam, cap, atoi(temp));
      }

      j = 0;
    } else {
      *(temp + j) = *(str + i);
      j++;
    }

  }

  free(temp);
  return conj;
}

/*
------------------------------------------------------------------------------------------------------------
char* strftr(char *str);


Esta funcao extrai os valores numericos presentes em um comando e os separa por virgula.

Parametros:

- str -> Comando dado como entrada em formato de string;

Retorno

- Uma string com os numeros separados por virgula.


------------------------------------------------------------------------------------------------------------
*/

char* strftr(char *str) {
  char filter[] = "-,0123456789";
  char *temp = NULL;
  unsigned long i = 0;
  unsigned long j = 0;

  temp = (char*) malloc((strlen(str) + 1) * sizeof(char));
  strcpy(temp, str);

  for(i = 0; i < strlen(str); i++) {

    /* Filtragem de dados numericos */
    if(strchr(filter, *(str + i)) != NULL) {
      *(temp + j) = *(str + i);
      j++;
    }

  }

  *(temp + j) = '\0';
  return temp;
}


/*
------------------------------------------------------------------------------------------------------------
void parse(char *str, int **A, int **B, int *tam_A ,int *tam_B ,int *cap_A ,int *cap_B);


Esta funcao interpetra o comando dado como entrada e dispara a acao correspondente.

Parametros:

- str -> Comando dado como entrada em formato de string;
- A -> Conjunto C;
- B -> Conjunto B;
- tam_A -> Quantidade de elementos do conjunto A;
- tam_B -> Quantidade de elementos do conjunto B;
- cap_A -> Capacidade do conjunto A;
- cap_B -> Capacidade do conjunto B;

------------------------------------------------------------------------------------------------------------
*/

void parse(char *str, int **A, int **B, int *tam_A ,int *tam_B ,int *cap_A ,int *cap_B) {
  char *temp = NULL;
  char *i = NULL;
  int *C = NULL;
  int tam_C = 0;
  int cap_C = 0;

  /* Identificacao do comando de atribuicao */
  if((i = strstr(str, " = ")) != NULL) {
    temp = strftr(i + strlen(" = "));

    if(strstr(str, "A") != NULL) {
      *A = atribuicao(temp, *A, tam_A, cap_A);
      print("A = ", *A, *tam_A, *cap_A);
    } else {
      *B = atribuicao(temp, *B, tam_B, cap_B);
      print("B = ", *B, *tam_B, *cap_B);
    }

    free(temp);
  }

  /* Identificacao do comando de adicao */
  if((i = strstr(str, " += ")) != NULL) {
    temp = strftr(i + strlen(" += "));

    if(strstr(str, "A") != NULL) {
      *A = adicao(*A, tam_A, cap_A, atoi(temp));
      print("A = ", *A, *tam_A, *cap_A);
    } else {
      *B = adicao(*B, tam_B, cap_B, atoi(temp));
      print("B = ", *B, *tam_B, *cap_B);
    }

    free(temp);
  }

  /* Identificacao do comando de remocao */
  if((i = strstr(str, " -= ")) != NULL) {
    temp = strftr(i + strlen(" -= "));

    if(strstr(str, "A") != NULL) {
      *A = subtracao(*A, tam_A, cap_A, atoi(temp));
      print("A = ", *A, *tam_A, *cap_A);
    } else {
      *B = subtracao(*B, tam_B, cap_B, atoi(temp));
      print("B = ", *B, *tam_B, *cap_B);
    }

    free(temp);
  }

  /* Identificacao do comando de pertence */
  if((i = strstr(str, " e ")) != NULL) {
    temp = strftr(str);

    if(strstr(str, "A") != NULL) {
      printf("%s\n", pertence(*A, *tam_A, atoi(temp)) ? "verdadeiro" : "falso");
    } else {
      printf("%s\n", pertence(*B, *tam_B, atoi(temp)) ? "verdadeiro" : "falso");
    }

    free(temp);
  }

  /* Identificacao do comando de contido */
  if((i = strstr(str, " c ")) != NULL) {

    if(strstr(str, "A") < strstr(str, "B")) {
      printf("%s\n", contido(*A, *B, *tam_A, *tam_B) ? "verdadeiro" : "falso");
    } else {
      printf("%s\n", contido(*B, *A, *tam_B, *tam_A) ? "verdadeiro" : "falso");
    }

  }

  /* Identificacao do comando de uniao */
  if((i = strstr(str, " u ")) != NULL) {
    C = uniao(*A, *B, *tam_A, *tam_B, &tam_C, &cap_C);

    if(strstr(str, "A") < strstr(str, "B")) {
      print("A u B = ", C, tam_C, cap_C);
    } else {
      print("B u A = ", C, tam_C, cap_C);
    }
    
    free(C);
  }

  /* Identificacao do comando de intersecao */
  if((i = strstr(str, " ^ ")) != NULL) {
    C = intersecao(*A, *B, *tam_A, *tam_B, &tam_C, &cap_C);

    if(strstr(str, "A") < strstr(str, "B")) {
      print("A ^ B = ", C, tam_C, cap_C);
    } else {
      print("B ^ A = ", C, tam_C, cap_C);
    }
    
    free(C);
  }

  /* Identificacao do comando de diferenca */
  if((i = strstr(str, " \\ ")) != NULL) {
    
    if(strstr(str, "A") < strstr(str, "B")) {
      C = diferenca(*A, *B, *tam_A, *tam_B, &tam_C, &cap_C);
      print("A \\ B = ", C, tam_C, cap_C);
    } else {
      C = diferenca(*B, *A, *tam_B, *tam_A, &tam_C, &cap_C);
      print("B \\ A = ", C, tam_C, cap_C);
    }

    free(C);
  }

}

int main() {
  int *A = NULL;
  int *B = NULL;
  int tam_A = 0;
  int tam_B = 0;
  int cap_A = 0;
  int cap_B = 0;
  char *str = NULL;
  char c = ' ';
  int size = 0;
  int capacity = 0;

  /* Enquanto o comando de sair (Q) nao for dado sera lido novos comando */
  do {
    size = 0;
    /* Novos comandos sao lidos ate que uma quebra de lina seja identificada */
    while(scanf("%c", &c) && c != '\n') {
      if(str == NULL) {
        capacity = 2;
        str = (char*) malloc(capacity * sizeof(char));
      }
      if(size + 1 == capacity) {
        capacity *= 2;
        str = (char*) realloc(str, capacity * sizeof(char));
      }
      str[size] = c;
      size++;
    }
    str[size] = '\0';
    /* Interpretacao do comando */
    parse(str, &A, &B, &tam_A , &tam_B , &cap_A , &cap_B);
  } while(strcmp(str, "Q"));

  /* Dados desalocados */
  if(str) free(str);
  if(A) free(A);
  if(B) free(B);
}
