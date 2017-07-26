/*
 * Aluno(a):Marcelo Martins Vilela Filho
 * RA:202619
 */

/*
 * Objetivos: A função tem como  objetivo imprimir na tela todas os anagramas(distintos)
 * de uma palavra.
 *
 * Entradas: A entrada é uma palavra, contudo o código principal ordena a palavra e nos passa  
 * uma string com todos os caracteres da palavra em ordem alfabética.
 *
 * Saida: É impresso todos os anagramas, um em cada linha e em ordem alfabética, da palavra inicial.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Entrada: 
 *          string_ordenada: a string original, que devemos processar 
 *                           para encontrarmos todos os anagramas
 *          letra_usada: um vetor de booleanos (implementado da forma 
 *                       de um vetor de inteiros) para marcarmos quais 
 *                       posições da string original já foram usadas
 *          word: o anagrama que estamos formando
 *          n: o numero de letras do anagrama
 *          k: a posição onde incluiremos a proxima letra em word
 * 
 * A ideia para gerar sem repeticoes eh que setada a letra da posicao k,
 * e retornado da chamada recursiva, temos
 * que colocar uma letra diferente na posição k, pois senão geraríamos
 * as repetições. Quando n==k incluimos a letra faltante e imprimimos o
 * anagrama.
 */

void generate(char *string_ordenada, int *letra_usada, char *word, int n, int k){

/* Notas gerais de funcionamento do programa: 
 * O caso base(ultimo ponto da recursão) é quando k, que é a posição a ser alterada em word,
 * tem valor igual a n, nesse caso, imprimimos '\0' nessa posição indicando o fim de word.
 * (lembrando que as posições de word que têm caracteres variam no intervalo [0-2]).
 *
 * Quando não estamos no caso base, percorremos letra_usada(um vetor de mesmo tamanho que 
 * string_ordenada que colocamos quais letras ja foram usadas para aquela posição da 
 * string_ordenada) e achamos uma posição em que contêm um zero, ou seja, não foi utilizada
 * conferimos se a letra de string_ordenada que está na posição que encontramos é igual a 
 * letra que já está em word.Se as duas condições forem validas, atribuimos 1(verdadeiro/usado)
 * para letra_usada e copiamos o char de string_ordenada daquela posição.
 * 
 * Caso não encontremos condições validas no loop, subimos na arvore de recursão e iniciamos(
 * ou continuamos da letra que o loop parou quando desceu a recursão) até encontrar as condições
 * ou até sair da arvore de recursão  
 */

	if(k == n){
		// terminamos o anagrama em formação
		printf("%s\n",word);
		//subida na arvore de recursão	
		return;		
	}else{
		int checkUnused = 0;
		//percorrendo letra_usada.
		while(checkUnused < n){
			if(letra_usada[checkUnused] == 0 && string_ordenada[checkUnused] != word[k]){
				// indicamos a posição copiada para word para 1(ou usada).
				letra_usada[checkUnused] = 1 ;
				//cópia do char e atualização do tamanho da word(na descida).
				word[k] = string_ordenada[checkUnused];
				word[k+1] = '\0';
				//descida na arvore.
				generate(string_ordenada, letra_usada, word, n, k+1);
				// indicamos como não usada após uma subida na arvore de recursão.
				// pois o caractere já foi utilizado no anagrama atual
				// mas no próximo é uma possibilidade.
				letra_usada[checkUnused] = 0;

			}
			checkUnused++;					
		}
		return;
	}
/*
 * OBS: O fato da string ja estar ordenada, é fundamental para o funcionamento pois,
 * na subida da arvore garantimos que não há letras repetidas mais adiante, alêm de
 * gerar os anagramas em ordem alfabética.
 */

}
