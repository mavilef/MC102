#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
A ideia para gerar sem repeticoes e que setado a letra da posicao k,
geramos todas as possibilidades e quando voltar do backtracking temos
que colocar uma letra diferente na posição k, pois senão geraríamos
as repetições. Por isso depois de setado uma posição a próxima letra
da posição é dado por proxima_letra_diferente que discarta letras iguais a já setada.
 */
void generate(char *string_ordenada, int *letra_usada, char *word, int n, int k);

char * sort(char string[]);

int main(){

  char *string_inicial;
  string_inicial = (char*) malloc(sizeof(char));
  int string_inicial_tam = 0;
  char c;
  while(scanf("%c", &c) && c != '\n') {
    string_inicial_tam++;
    string_inicial = (char*) realloc(string_inicial, string_inicial_tam+1 * sizeof(char));
    string_inicial[string_inicial_tam-1] = c;
    string_inicial[string_inicial_tam] = '\0';
  }
  char *string_ordenada =  sort(string_inicial);
  int n  = strlen(string_ordenada);  
  int *letra_usada = malloc(n*sizeof(int));
  char *anagrama = malloc((n+1)*sizeof(char));

  int i=0;
  for(i=0; i<n; i++)
    letra_usada[i]=0;
  generate(string_ordenada, letra_usada, anagrama, n, 0);

  free(anagrama);
  free(string_ordenada);
  free(letra_usada);
}

char * sort(char string[]){
  int count[256], i;
  char *sr;

  for(i=0; i<256; i++)
    count[i] = 0;
  
  i=0;
  while(string[i] != '\0'){
    count[(int)string[i]]++;
    i++;
  }
  
  sr = malloc((i+1)*sizeof(char));
  
  int j=0, k=0;
  for(i=0; i<256; i++){
    if(count[i]!=0){
      for(k=0; k<count[i]; k++){
	sr[j] = i;
	j++;
      }
    }
  }
  sr[j] = '\0';
  return sr;
}

