//Marcelo Martins Vilela Filho RA 202619 - Engenharia de Computação

/*Objetivo: O programa tem o objetivo de imprimir na tela uma figura escolhida pelo usuário(quadrado,losango,triangulo) de tamanho 
correspondente ao parametro numerico inserido pelo usuário.

Entradas: Como entrada temos um a letra inicial correspondente á figura desejada(Q/q, T/t, L/l) e um numero inteiro maior que 2 ,
e impar no caso do losango.
No programa ás variáveis de entrada são "id" do tipo char, que indica a figura, e "h" do tipo int, que indica o tamanho da  figura. 

Saidas:É impresso na tela a figura correspondente á digitada pelo usuário feita de asteriscos("*") com uma moldura feita de pontos(".").*/

#include <stdio.h>

int main () {

char id;
int h, asterisco_max = 0, corretor1 = 0, invalido = 0 , inversor = 0, corretor2 , espaco_tinvertido = 0, corretor3;

scanf("%c %d", &id, &h);

asterisco_max= (h+1)/2;
corretor2 = asterisco_max-1;
corretor3 = h;

//corretor1 é uma variável que corrige o quando o triangulo/losango irá imprimir os asteriscos, para que fique em função da linha.
//O corretor2 é uma variável que ajuda que corrige o losango quando o numero de asteriscos tem que começar a diminuir.
/*O corretor3 corrige um problema de quando é digitado l 5 , por algum motivo, o programa imprime erroneamente quando
é dado o parâmetro 5 para o tamanho.Corretor3 diminui uma quantidade de espaços quando o numero de asteriscos começa a 
diminuir (com h =5 é impresso um a mais).
*/
if((id == 'l' || id == 'L') && (h%2==0))
	 // restrições de h impar no caso do losango.
	invalido = 1;
if((id == 'Q' || id == 'q' || id== 'T' || id=='t'|| id=='l'||id=='L' ) && (h<2))
	// restrição no caso de (h<2).
	invalido = 1;

if(invalido!=1){
	switch(id){

		case 'Q': case 'q': 

			/*Este primeiro for diz quando imprimir uma linha de pontos ou 
			imprimir uma linha da estrutura do quadrado.
			*/ 
		
		
			for(int controlador_linhas=0 ; controlador_linhas <= h+1 ; controlador_linhas++){

				if(controlador_linhas==0||controlador_linhas==h+1)

				/*Esta Parte imprime a primeira linha do quadrado, de
				 acordo com a lei dada por (2*h-1)+4
				*/

				for(int pontos=0;pontos<(2*h-1)+4;pontos++){
					printf(".");
					if(pontos==(2*h-1)+3)
						printf("\n");
				} else

				/*Esta Parte imprime as linhas estruturais do quadrado.Note que basta 
				imprimir ". "no começo estrutura no fim de h+1(pois a estrutura
				é um a mais do que h )estrutura imprimir "* " quando
				não está nos extremos da estrutura. 
				*/
				for(int estrutura = 0; estrutura<=h+1; estrutura++){

					if(estrutura==0){
						printf(". ");
					}else{
						if(estrutura==h+1){
							printf(".\n");
						}else{
							if(estrutura!=0 && estrutura!=h+1)
								printf("* ");		
						}
					}
	
				}	
			}
		break;

		case 'T': case 't':

			/*Este primeiro for diz quando imprimir uma linha de pontos ou 
			imprimir uma linha da estrutura do triângulo.
			*/ 
		
		
			for(int controlador_linhas=0 ; controlador_linhas <= h+1 ; controlador_linhas++){

				if(controlador_linhas==0||controlador_linhas==h+1){

				/*Esta Parte imprime a primeira linha do triângulo, de
				 acordo com asterisco lei dada por (2*h-1)+4
				*/

					for(int pontos=0;pontos<(2*h-1)+4;pontos++){
						printf(".");
							if(pontos==(2*h-1)+3)
								printf("\n");
					}
				}else{

				/*Esta Parte imprime as linhas estruturais do triangulo.Em linhas gerais,
				é impresso uma quantidade de linhas antes do primeiro asterisco, que no caso do triangulo
				é quando o "controlador_linhas" chegar em h+1-corretor1 , sendo o corretor1 um amenos do que 
				o controlador linhas.(tal fato é feito observando outputs).
				quando o controlador de linhas chega no ultimo espaço , o programa imprime os asteriscos da linha(igual ao 
				numero da linha e o numero de espaços depois do ultimo asterisco.(que é o numero de espaços inicial- 1 ,
				pois em cada asterisco já é impresso um espaço.				
				*/
					corretor1=controlador_linhas-1;

					for(int estrutura=0;estrutura<(2*h-1)+4;estrutura++){

				
						if(estrutura==0){
							printf(".");
						}else if(estrutura==h+1-corretor1||estrutura==h+1+corretor1){
							for(int asterisco = 0; asterisco<controlador_linhas;asterisco++)
								printf("* ");
							for(int ef = 0; ef<=h-1-controlador_linhas;ef++)
								printf(" ");
							printf(".\n");
							break;
						}else{
							printf(" ");
						}
					}

				}
			}
		break;

		case 'l': case 'L':

			/*Este primeiro for diz quando imprimir uma linha de pontos ou 
			imprimir uma linha da estrutura do losango.
			*/ 
		
			asterisco_max = (h+1)/2;
		
		
			for(int controlador_linhas=0;controlador_linhas<=h+1;controlador_linhas++){

				if(controlador_linhas==0||controlador_linhas==h+1){

				/*Esta Parte imprime asterisco primeira linha do losango, de
				 acordo com asterisco lei dada por h+4
				*/

					for(int pontos=0;pontos<h+4;pontos++){
						printf(".");

							if(pontos==h+3)
								printf("\n");
					}
				}else if(inversor < asterisco_max) {

				/*Esta Parte imprime linha estrutural do losango , quando o numero de asteriscos por linhas
				é crescente.Em linhas gerais,
				é impresso uma quantidade de linhas antes do primeiro asterisco, que no caso do triangulo
				é quando o "controlador_linhas" chegar em h+1-corretor1 , sendo o corretor1 um amenos do que 
				o controlador linhas.(tal fato é feito observando outputs).
				quando o controlador de linhas chega no ultimo espaço , o programa imprime os asteriscos da linha(igual ao 
				numero da linha e o numero de espaços depois do ultimo asterisco.(que é o numero de espaços inicial- 1 ,
				pois em cada asterisco já é impresso um espaço.	
				agora usamos as variaveis 'inversor' que avisa quando é necessário começar a diminuir o numero de asteriscos
				por linha, e 'asterisco_max' que identifica qual é o numero maximo de asteriscos numa linha antes começar a 
				diminuir o numero de asteriscos por linha(é uma função de h).
				'espaço_tinvertido' nos diz o numero de espaços iniciais dados na ultima linha de asteriscos. 
							
				*/
					corretor1=controlador_linhas-1;
					asterisco_max= (h+1)/2;

					for(int estrutura=0;estrutura<h+4;estrutura++){
				
						if(estrutura==0){

							printf(".");

						}else if(estrutura==asterisco_max+1-corretor1||estrutura==asterisco_max+1+corretor1){
							
							inversor=0;		
							
							for(int asterisco = 0; asterisco<controlador_linhas;asterisco++){
								printf("* ");
								inversor++;
							}
							if(estrutura!=inversor -1)
								espaco_tinvertido = 0;

							for(int espaco_final = 0; espaco_final<=asterisco_max-1-controlador_linhas;espaco_final++)
								printf(" ");
								
							

							printf(".\n");
							break;
						}else{
							espaco_tinvertido++;
							printf(" ");

						}
					}

				}else{

				/*Esta Parte imprime linha estrutural do losango , quando o numero de asteriscos por linhas
				é decrescente. a variável que indica quando é necessário entrar aqui é 'inversor'.
				*/
						if(corretor3==5){
				//corrige o bug de quando o usuário digita h = 5.
							espaco_tinvertido--;
							corretor3--;
						}

					for(int estrutura=0;estrutura<h+4;estrutura++){

				
						if(estrutura==0){

							printf(".");

						}else if(estrutura==espaco_tinvertido + 3){

								for(int asterisco = 0; asterisco<corretor2;asterisco++)
									printf("* ");

								for(int espaco_final = 0; espaco_final<=espaco_tinvertido  ;espaco_final++)
									printf(" ");

								espaco_tinvertido++;
								corretor2--;
								printf(".\n");

								break;
								
						}else{

							printf(" ");

						}
					}
				} 
			}
		break;

		default:
 
		/*restrição no caso de não existir uma figura relacionada a id digitada 
		pelo usuario.
		*/

			printf("entrada invalida\n");
		break;
	}
}else{
	printf("entrada invalida\n");
}

return 0;
}


