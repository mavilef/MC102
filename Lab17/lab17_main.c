#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int ra, telefone;
  char nome[100];
} Registro;
typedef struct {
  int armazenado;
  int capacidade;
  Registro *registros;
} Base;

void criar_base(Base *base, int n);
int buscar(Base *base, int ra);
void imprimir(Base *base, int ra);
void adicionar(Base *base, int ra, int telefone, char *nome);
void remover(Base *base, int ra);
void limpar(Base *base);
void liberar_base(Base *);

int main() {

  Base base;
  int capacidade;

  if (scanf("%d\n", &capacidade) != 1) {
    printf("Erro de Leitura da Capacidade\n");
    return 1;
  }
  criar_base(&base, capacidade);

  if (base.capacidade != capacidade) {
    printf("Capacidade inicial errada: %d\n", base.capacidade);
  }
  if (base.armazenado != 0) {
    printf("Quantidade armazenada inicial errada: %d\n", base.armazenado);
  }
  if (base.registros == NULL) {
    printf("Vetor de registros nao alocado.\n");
  }

  while (1) {
    char op;

    if (scanf("%s", &op) != 1) {
      break;
    } else if (op == 'q') {
      break;
    } else {
      int ra = 0;

      if (scanf("%d", &ra) != 1) {
        printf("Erro de Leitura do RA\n");
      }

      if (op == '>') {
        imprimir(&base, ra);
      } else if (op == '-') {
        remover(&base, ra);
      } else if (op == '+') {
        int telefone;
        char nome[100] = "";
        if (scanf(" %d %[^\n]", &telefone, nome) != 2) {
          printf("Erro de Leitura do telefone e nome.\n");
        }
        adicionar(&base, ra, telefone, nome);
      } else {
        printf("Comando %c desconhecido.\n", op);
      }
    }
    while (fgetc(stdin) != '\n')
      ;
  }

  liberar_base(&base);

  if (base.capacidade != 0) {
    printf("A base ainda tem capacidade %d.\n", base.capacidade);
  }
  if (base.armazenado != 0) {
    printf("A base ainda tem %d registros armazenados.\n", base.armazenado);
  }
  if (base.registros != NULL) {
    printf("A base ainda tem um pointeiro de registros.\n");
  }

  return 0;
}
