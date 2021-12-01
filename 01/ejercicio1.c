#include <fcntl.h>      
#include <stdlib.h>     
#include <stdio.h>

int main(int argc, char *argv[]){

	FILE *fichero; 
	int n = 0;
	int res[2000];
	int i = 0;
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int j = 0;
	int z = 0;
	int resultado = 0;
	char cadena[100];

   	fichero = fopen ("input.txt", "r");
   	if (fichero==NULL)
   	{
        perror("Error al abrir fichero:");
        exit(1);
  	}

	while (fgets(cadena, 100, fichero) != NULL)
	{
      	n = atoi(cadena);
		res[i] = n;
		i++;

	}
	int tam = i;
	int res1 = 0;
	i = 0;
	
  	while(j<tam-1){
		j = i + 1;
		if ( i == 0)
			printf("%d (N/A - no previous measurement)\n", res[0]);
		if(res[i] < res[j])
		{
			printf("%d (increased)\n", res[j]);
			res1++;
		}
		else if(res[i] > res[j])
		{
			printf("%d (decreased)\n", res[j]);
		}
		i++;
	}

	printf("El numero total de (increased) es %d", res1);

	return 0;
}
