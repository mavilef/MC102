//Marcelo Martins Vilela Filho RA 202619 - Engenharia de Computação

/*Objetivo: O programa tem como objetivo fazer somas e subtrações como numeros de digitos maiores do que o limite para as variaveis tipo int.
O fenomeno chamado 'overflow' ocorre quando se ultrapassa o numero de digitos maximo e assim a variável adquire valores errôneos.
para isso é utilizado vetores onde cada digito é uma das variáveis do vetor.

Entradas: Como entrada temos o numero de até 30 digitos conforme dito no enunciado.Os digitos são lidos como char, transformados em int e passados 
ao vetor do número.

Saidas:como saida é impresso os dois numeros digitados(completados com zero á esquerda) e o resultado final das operações.*/

#include <stdio.h>

/*
É necessario a usar os seguintes comandos para leitura de char.
char c;
do{
  scanf("%c", &c);
}while(c!='\n');

pois para se vc apertar enter ele irá guardar \n na variável.

para converter  um número em char para um número int/float/double deve-se tirar 48 do char.
pois na tabela ASCII
*/

int main(){
	
	int corretor = 2;/*corrige a verificação de numeros negativos, caso a subtração inicial estore o numero de casas
			, mas o resultado final não. Essa variável ainda tem função fundamental para verificação se o numero
			estoura o numero de casas decimais.
			A analise dos dois digitos a mais do vetor permite que seja decidido se o numero estoura ou não as casas pré-estabelecido.  
			*/ 

	int numero_de_caracteres = 30 + corretor, overflow = 0, negativo = 0 ,trocador = 0, tamanho_resultado;
	char c = '0', b = '0', a= '0', op;
	int numero1[numero_de_caracteres], numero2[numero_de_caracteres] , resultado[numero_de_caracteres], temp = 0, inversora[numero_de_caracteres];
	
	//zera todas as variáveis do vetor 'numero1'(inicialização)
	for(int zerador1 = 0; zerador1<numero_de_caracteres ; zerador1++)
		numero1[zerador1]=0;

	//zera todas as variáveis do vetor 'numero2'(inicialização)
	for(int zerador2 = 0; zerador2<numero_de_caracteres ; zerador2++)
		numero2[zerador2]=0;

	//zera todas as variáveis do vetor 'numero2'(inicialização)
	for(int zerador_resultado = 0; zerador_resultado<numero_de_caracteres ; zerador_resultado++)
		resultado[zerador_resultado]=0;

	//Leitura do 1º número
	for(int i=numero_de_caracteres-1 ;c!='\n';i--){ 
		scanf("%c",&c);

		if(c!='\n'&& i==numero_de_caracteres-1)
			numero1[numero_de_caracteres-1]=c-48;

		if(c!='\n'&& i<numero_de_caracteres-1){

				for(int j = i; j<=numero_de_caracteres-1 ; j++)
					numero1[j]=numero1[j+1];

 				numero1[numero_de_caracteres-1] = c-48;				
		}
						
		
	}	
	
	//leitura da operação
	do{

  		scanf("%c", &b);
		if(b!='\n')
			op=b;

	}while(b!='\n');

	//leitura do 2º número
	for(int i=numero_de_caracteres-1 ;a!='\n';i--){

		scanf("%c",&a);

		if(a!='\n'&& i==numero_de_caracteres-1)
			numero2[numero_de_caracteres-1]=a-48;

		if(a!='\n'&& i<numero_de_caracteres-1){

				for(int j = i; j<=numero_de_caracteres-1 ; j++)
					numero2[j]=numero2[j+1];

 				numero2[numero_de_caracteres-1] = a-48;				
		}
						
		
	}
	//Algorítmo de soma de dois números.

	/*Aqui soma-se caractere por caractere dos dois numeros quando a soma de dois digitos ultrapassa 10,
	extrai-se o ultimo digito da soma, e atribui-se 1 a uma variavel temporaria 'temp' assim na proxima soma 
	acrescenta-se 'temp'(que é igual a 1)e assim por diante.

	Foi adicionado uma condição especial no caso em que o vetor resultado já foi completamente preenchido e ainda sim
	haveria a variavel temporaria a ser somada o que significa que estouraria as 30 casas decimais, logo é indicado overflow.

	*/
	if(op=='+'){

		for(int soma = numero_de_caracteres - 1;soma>=0;soma--){
			
			resultado[soma] = temp + numero1[soma] + numero2[soma];

				if(resultado[soma]>=10){
					resultado[soma]=resultado[soma]%10;
						temp=1;
				}else{
					temp=0;
				}
	
				if(soma == 0 && temp == 1)
					overflow = 1;
					
		}
	
	}

	//algorítimo de subtração de dois numeros.
	if(op=='-'){

		/*é usado o algorítmo simples da subtração, e este, só funciona quando o minuendo é maior do que o subtraendo.
		Primeiramente se o primeiro numero(minuendo) é maior do que o subtraendo, se sim , continua-se o algorítmo normalmente
		caso não, é indicado a necessidade de se inverter o minuendo e o subtraendo e depois realiza-se o algoritmo normalmente alêm de indicar
		que o numero é negativo, colocando o sinal '-' no começo do resultado.
		*/


				//verifica se é possivel utilizar o algorítmo de subtração(minuendo => subtraendo)
			for(int verificador = 0; verificador<numero_de_caracteres ; verificador++){
				if(numero1[verificador]<numero2[verificador]){
					trocador=1;
					negativo=1;
					break;
				}

				if(numero1[verificador]>numero2[verificador])
					break;
			}
			//algorítmo de subtração sem inversão prévia (minuendo>= subtraendo).
			if(trocador==0){
				for(int subtracao = numero_de_caracteres-1;subtracao>=0;subtracao--){

					if(numero1[subtracao]<(numero2[subtracao]+temp)){
					resultado[subtracao] = numero1[subtracao] + 10 - numero2[subtracao] - temp;
					temp = 1;	

					}else{

					resultado[subtracao] = numero1[subtracao] - numero2[subtracao] - temp;	
					temp=0;

					}
				}
			}
			//algorítmo de subtração com inversão prévia (minuendo < subtraendo).(resposta negativa)
			if(trocador==1){

				for(int inv = numero_de_caracteres - 1; inv>=0 ; inv--){
					inversora[inv] = numero1[inv];
					numero1[inv] = numero2[inv];
					numero2[inv] = inversora[inv];
				}

				for(int subtracao = numero_de_caracteres-1;subtracao>=0;subtracao--){

					if(numero1[subtracao]<(numero2[subtracao]+temp)){
					resultado[subtracao] = numero1[subtracao] + 10 - numero2[subtracao] - temp;
					temp = 1;	

					}else{

					resultado[subtracao] = numero1[subtracao] - numero2[subtracao] - temp;	
					temp=0;

					}
				}

			}

	}

	// verifica se o resultado estoura o numero de casas decimais.
	if(resultado[0] != 0 || resultado [1] != 0)
		overflow=1;

	//verifica o numero de caracteres do resultado, para que o resultado impresso não tenha zeros à esquerda.
	if(overflow==0)
		for(tamanho_resultado = corretor; tamanho_resultado<numero_de_caracteres ; tamanho_resultado++){
			if(resultado[tamanho_resultado] != 0){
				tamanho_resultado = tamanho_resultado;
				break;
			}

			if(resultado[numero_de_caracteres - 1] == 0){
				tamanho_resultado=numero_de_caracteres - 1;
				break;
			}
		}
			

	
	if(negativo==0 && overflow==0){

		for(int tela_numero1 = corretor; tela_numero1<=numero_de_caracteres-1 ; tela_numero1++)
			printf("%d",numero1[tela_numero1]);

		printf("\n");

		for(int tela_numero2 = corretor; tela_numero2<=numero_de_caracteres-1 ; tela_numero2++)
			printf("%d",numero2[tela_numero2]);

		printf("\n");

		for(int tela_resultado = tamanho_resultado; tela_resultado<=numero_de_caracteres-1 ; tela_resultado++)
			printf("%d",resultado[tela_resultado]);


	}else if(negativo == 1 && overflow ==0){

		/*Aqui,devido á inversão prévia dos dois numeros quando resultado negativo, deve-se reverter o procedimento imprimindo os dois numeros em
		ordem invertida.
		*/ 

		for(int tela_numero2 = corretor; tela_numero2<numero_de_caracteres ; tela_numero2++)
			printf("%d",numero2[tela_numero2]);
			
		printf("\n");

		for(int tela_numero1 = corretor; tela_numero1<numero_de_caracteres ; tela_numero1++)
			printf("%d",numero1[tela_numero1]);

		printf("\n");

		printf("-");

		for(int tela_resultado = tamanho_resultado; tela_resultado<numero_de_caracteres ; tela_resultado++)
			printf("%d",resultado[tela_resultado]);

	
	}else if(negativo == 0 && overflow ==1){

		for(int tela_numero1 = corretor; tela_numero1<=numero_de_caracteres-1 ; tela_numero1++)
			printf("%d",numero1[tela_numero1]);

		printf("\n");

		for(int tela_numero2 = corretor; tela_numero2<=numero_de_caracteres-1 ; tela_numero2++)
			printf("%d",numero2[tela_numero2]);

		printf("\n");

		printf("overflow");

	}else if(negativo == 1 && overflow ==1){

		/*Aqui,devido á inversão prévia dos dois numeros quando resultado negativo, deve-se reverter o procedimento imprimindo os dois numeros em
		ordem invertida.
		*/ 


		for(int tela_numero2 = corretor; tela_numero2<numero_de_caracteres ; tela_numero2++)
			printf("%d",numero2[tela_numero2]);
			
		printf("\n");

		for(int tela_numero1 = corretor; tela_numero1<numero_de_caracteres ; tela_numero1++)
			printf("%d",numero1[tela_numero1]);

		printf("\n");

		printf("overflow");

	}

	printf("\n");
			
return 0;
}
