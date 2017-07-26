#include <stdio.h>

int main()
{
	int i, j, numero_de_dias, dia = 0;
	float empresa1[15] = {0}, empresa2[15] = {0}, empresa3[15] = {0}, empresa4[15] = {0}; 
	int compra1 = 0, compra2 = 0, compra3 = 0, compra4 = 0, venda1 = 0, venda2 = 0, venda3 = 0, venda4 = 0, lucro1 = 0, lucro2 = 0, lucro3 = 0, lucro4 = 0;
	float acao;
	
	scanf("%d", &numero_de_dias);
	/*No laço abaixo, o programa irá colocar os valores das ações de cada, sendo que na linha fica os valores
	  de uma empresa em cada dia e na coluna os valores das empresas em um determinado dia */
	for(i = 0; i < 4; i++)//Toda vez que uma linha de valores for digitada, uma linha será pulada
	{
		dia = 0;
		for(j = 0; j < numero_de_dias; j++)//Laço para colocar os valores para cade empresa
		{
			scanf("%f", &acao);
			if(i == 0)
			{
				empresa1[dia] = acao;//Valor da ação será atribuída para a empresa 1
				dia++; 
			}
			if(i == 1)
			{
				empresa2[dia] = acao;//Valor da ação será atribuída para a empresa 2
				dia++; 
			}
			if(i == 2)
			{
				empresa3[dia] = acao;//Valor da ação será atribuída para a empresa 3
				dia++; 
			} 	
			if(i == 3)
			{
				empresa4[dia] = acao;//Valor da ação será atribuída para a empresa 4
				dia++; 
			} 	
			 	 			
		}
		
	}



	float lucroTotal = 0, lucroMax = 0;

	for(int tentativacompra1 = 0; tentativacompra1 < numero_de_dias; tentativacompra1++)
	{
		for(int tentativavenda1 = tentativacompra1; tentativavenda1 < numero_de_dias; tentativavenda1++)
		{
			for(int tentativacompra2 = 0; tentativacompra2 < numero_de_dias; tentativacompra2++)
			{
				for( int tentativavenda2 = tentativacompra2; tentativavenda2 < numero_de_dias; tentativavenda2++)
				{
					for(int tentativacompra3 = 0; tentativacompra3 < numero_de_dias; tentativacompra3++)
					{
						for(int tentativavenda3 = tentativacompra3; tentativavenda3 < numero_de_dias; tentativavenda3++)
						{
							for(int tentativacompra4 = 0; tentativacompra4 < numero_de_dias; tentativacompra4++)
							{
								for(int tentativavenda4 = tentativacompra4; tentativavenda4 < numero_de_dias; tentativavenda4++)
								{									 
									if(tentativacompra2 >= tentativavenda1 && tentativacompra3 >= tentativavenda1 && tentativacompra4 >= tentativavenda1) 
									{		
										lucroTotal = empresa1[tentativavenda1] - empresa1[tentativacompra1] + empresa2[tentativavenda2] - empresa2[tentativacompra2] +  empresa3[tentativavenda3] - empresa3[tentativacompra3] +  empresa4[tentativavenda4] - empresa4[tentativacompra4];    	
										if(lucroTotal > lucroMax)
										{
											lucroMax = lucroTotal;
											compra1 = tentativacompra1;
											compra2 = tentativacompra2;
											compra3 = tentativacompra3;
											compra4 = tentativacompra4;
											venda1 = tentativavenda1;
											venda2 = tentativavenda2;	
											venda3 = tentativavenda3;	
											venda4 = tentativavenda4;													
										} 	 
									}
									else if(tentativacompra1 >= tentativavenda2 && tentativacompra3 >= tentativavenda2 && tentativacompra4 >= tentativavenda2)									
    									{
										lucroTotal = empresa1[tentativavenda1] - empresa1[tentativacompra1] + empresa2[tentativavenda2] - empresa2[tentativacompra2] +  empresa3[tentativavenda3] - empresa3[tentativacompra3] +  empresa4[tentativavenda4] - empresa4[tentativacompra4];
										if(lucroTotal > lucroMax)
										{
											lucroMax = lucroTotal;
											compra1 = tentativacompra1;
											compra2 = tentativacompra2;
											compra3 = tentativacompra3;
											compra4 = tentativacompra4;
											venda1 = tentativavenda1;
											venda2 = tentativavenda2;	
											venda3 = tentativavenda3;	
											venda4 = tentativavenda4;													
										} 	 
					
									}
									else if(tentativacompra1 >= tentativavenda3 && tentativacompra2 >= tentativavenda3 && tentativacompra4 >= tentativavenda3)
									{
										lucroTotal = empresa1[tentativavenda1] - empresa1[tentativacompra1] + empresa2[tentativavenda2] - empresa2[tentativacompra2] +  empresa3[tentativavenda3] - empresa3[tentativacompra3] +  empresa4[tentativavenda4] - empresa4[tentativacompra4];
										if(lucroTotal > lucroMax)
										{
											lucroMax = lucroTotal;
											compra1 = tentativacompra1;
											compra2 = tentativacompra2;
											compra3 = tentativacompra3;
											compra4 = tentativacompra4;
											venda1 = tentativavenda1;
											venda2 = tentativavenda2;	
											venda3 = tentativavenda3;	
											venda4 = tentativavenda4;													
										} 	 

									}
									else if(tentativacompra1 >= tentativavenda4 && tentativacompra2 >= tentativavenda4 && tentativacompra3 >= tentativavenda4)	
									{
										lucroTotal = empresa1[tentativavenda1] - empresa1[tentativacompra1] + empresa2[tentativavenda2] - empresa2[tentativacompra2] +  empresa3[tentativavenda3] - empresa3[tentativacompra3] +  empresa4[tentativavenda4] - empresa4[tentativacompra4];
										if(lucroTotal > lucroMax)
										{
											lucroMax = lucroTotal;
											compra1 = tentativacompra1;
											compra2 = tentativacompra2;
											compra3 = tentativacompra3;
											compra4 = tentativacompra4;
											venda1 = tentativavenda1;
											venda2 = tentativavenda2;	
											venda3 = tentativavenda3;	
											venda4 = tentativavenda4;													
										} 	 

									}
								}	
							}
						}
					}
				}
			}
		}   
	}   

	printf("%d %d\n", compra1 + 1, venda1 + 1);
	printf("%d %d\n", compra2 + 1, venda2 + 1);
	printf("%d %d\n", compra3 + 1, venda3 + 1);
	printf("%d %d\n", compra4 + 1, venda4 + 1);

	
	
	

	printf("Lucro: %.2f\n", lucroMax);
	
	  






	return 0;
}
