#include <fcntl.h>      
#include <stdlib.h>     
#include <stdio.h>
#include <string.h>
#include <math.h>

void cheap_fuel(int numeros[1000]);

int main(){

	int i = 0,r = 0, j = 0, num = 0, cont = 0;
	int numeros[1000];
	char c;

	while (i<1000)
	{
		scanf("%d,", &num);
		numeros[i] = num;
		printf("%d,", numeros[i]);
		i++;
	}
	printf("\n");
	cheap_fuel(numeros);
	return 0 ;
}

void cheap_fuel(int numeros[1000])
{
	int res[1000];
	int i = 0, fuel = 1, t = 0,h = 0,valor2 = 0, valor = 0;

	while(i<1000)
	{
		res[t] = abs(numeros[i] - fuel);
		if(i == 999)
		{
			valor = 0;
			h = 0;
			while(h<1000)
			{
				valor += res[h];
				h++;
			}
			//printf("El valor con fuel %d es %d\n", fuel, valor);
			//printf("Comparo con %d\n", valor2);

			if(valor>valor2 && fuel != 1)
			{
				printf("El valor mas pequeño es%d\n", valor2);
				exit(1);
			}	
			else
			{
				valor2 = valor;
				fuel++;
				i = 0;
				t = 0;
			}	
		}
		else
		{
			t++;
			i++;
		}
	}
	t = 0;
	
	printf("El valor con fuel es %d", valor);
}
