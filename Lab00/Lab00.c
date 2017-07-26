#include <stdio.h>

int main(){

	int first, second, add, subtract, multiply, integer_div	;	
	float divide;
	
	printf("Entre com dois inteiros\n");
	scanf("%d %d", &first, &second);
	
	add	= first + second;
	subtract	= first - second;
	multiply	= first * second;
	integer_div  = first / second;
	divide = first / (float)second; //typecast
	
	printf("Soma = %d\n", add);
	printf("Diferenca = %d\n", subtract);
	printf("Multiplicacao = %d\n", multiply);
	printf("Divisao Inteira = %d\n", integer_div);
	printf("Divisao = %.2f\n", divide);

	return 0;	


}
