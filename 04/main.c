#include <fcntl.h>      
#include <stdlib.h>     
#include <stdio.h>
#include <string.h>


void buscar(int numeros[290], int matriz[5][5], int repeticiones);
void imprimir(int matriz[5][5]);
int find_linea(int matriz[5][5]);

int main(){

	int i = 0,r = 0, j = 0, num = 0, cont = 0;
	int matriz[5][5];
	int numeros[100];
	char c;

	while (i<100)
	{
		scanf("%d,", &num);
		numeros[i] = num;
		printf("%d,", numeros[i]);
		i++;
	}
	printf("\n");
	i = 0, num = 0;

	while(r<100)
	{
		i = 0;
		while(i<5)
		{
			j = 0;
			while(j<5)
			{
				scanf("%d", &num);
				matriz[i][j] = num;
				j++;
			}
			i++;

		}
		buscar(numeros,matriz, r);
		if (find_linea(matriz) == 1)
		{
			cont++;
			printf("\nEncontrado linea en la matriz %d es el numero %d en resolverse\n", r+1, cont);
			exit(1);
		}
		r++;
		imprimir(matriz);
	}
	
	return 0;
}

void buscar(int numeros[100], int matriz[5][5], int repeticiones)
{
	int i = 0, j = 0, k = 0, cont = 0, it = 0;
	while(i<5)
	{
		
		j = 0;
		while(j<5)
		{
			if(matriz[i][j] == numeros[k])
			{
				matriz[i][j] = -5;
				cont++;
				printf("Encontrado el numeros %d en la matriz %d en la iteracion %d\n", numeros[k], repeticiones+1, cont);
			}	
			j++;
		}
		if(i == 4 && j == 5)
		{
			k++; 
			i = 0;
			j = 0;
		}	
		else if ( k == 26)
			i = 5;
		else
			i++;
	}

}

void imprimir(int matriz[5][5])
{
	int r =0, i = 0, j = 0;

		i = 0;
		while(i<5)
		{
			j = 0;
			while(j<5)
			{
				printf("%d ", matriz[i][j]);
				j++;
			}
			i++;
			printf("\n");

		}
		printf("\n");
}


int find_linea(int matriz[5][5])
{
	int i = 0, j = 0, k = 0;
	while(i<5) // buscar linea
	{
		j = 0;
		k = 0;
		while(j<5)
		{
			if(matriz[i][j] == -5 && matriz[i][j+1])
			{
				k++;
			}
			if(k == 5)
				return 1;
			else
				j++;
		}
		i++;
	}
	j = 0;
	while(j<5) // buscar columna
	{
		i = 0;
		k = 0;
		while(i<5)
		{
			if(matriz[i][j] == -5 && matriz[i+1][j])
			{
				k++;
			}
			if(k == 5)
				return 1;
			else
				i++;
		}
		j++;
	}
	return 0;
}