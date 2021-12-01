#include <fcntl.h>      
#include <stdlib.h>     
#include <stdio.h>

int main(){

	FILE *fichero; 
	int n = 0, i = 0;
	int res[2000];
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
	int resTotal=0;
	i = 3;
	while(i<tam){
		if(res[i-3] + res[i-2] + res[i-1] < res[i] + res[i-2] + res[i-1]){
			printf("%d (increased) (%d,%d,%d)\n", (res[i] + res[i-2] + res[i-1]), res[i],res[i-2],res[i-1]);
			resTotal++;
		}
		else if(res[i-3] + res[i-2] + res[i-1] > res[i] + res[i-2] + res[i-1]){
			printf("%d (decreased) (%d,%d,%d)\n", (res[i] + res[i-2] + res[i-1]), res[i],res[i-2],res[i-1]);
		}
		else if(res[i-3] + res[i-2] + res[i-1] == res[i] + res[i-2] + res[i-1]){
			printf("%d (no change) (%d,%d,%d)\n", (res[i] + res[i-2] + res[i-1]), res[i],res[i-2],res[i-1]);
		}
		i++;
		
	}
	printf("El numero total de (increased) es %d", resTotal);

	return 0;
}
