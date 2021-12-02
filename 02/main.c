#include <fcntl.h>      
#include <stdlib.h>     
#include <stdio.h>
#include <string.h>
int main(){

	FILE *fichero; 
	char res[1000][100];
	int i = 0, j = 0, tam = 0;
	char cadena[100];

   	fichero = fopen ("input.txt", "r");

	while (fgets(cadena, 100, fichero) != NULL)
	{
		j=0;
		while(j<((int)strlen(cadena)+1))
      	{
			res[i][j] = cadena[j];
			j++;	  
		}
		i++;
		

	}
  

	tam = i;
	i = 0, j = 0;
	int z = 0, n = 0,s =0, t =0, res1 = 0,resTotal=0;
	char f[1000], d[1000], u[1000];
  	while(i<tam)
	{
		if(res[i][0] == 'f')
		{
			j =0;
			while(res[i][j] < '0' || res[i][j] > '9')
				j++;
			f[n] = res[i][j];
			z+= atoi(f);

		}
		else if(res[i][0] == 'd')
		{
			j=0;
			while(res[i][j] < '0' || res[i][j] > '9')
				j++;
			d[s] = res[i][j];
			res1+= atoi(d);
		}
		else if(res[i][0] == 'u')
		{
			j=0;
			while(res[i][j] < '0' || res[i][j] > '9')
				j++;
			u[t] = res[i][j];
			res1-= atoi(u);
		}
		i++;
	}

	resTotal = z*res1;
	printf("El resultado total es %d", resTotal);

	return 0;
}
