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
		//printf("%s",res[i] );

		i++;
	}
	
	tam = i;
	i = 0, j = 0;
	int z = 0, n = 0,vueltas1 =0, vueltas2 =0, res1 = 0,resTotal=0;
  	while(j<13)
	{

		if(res[i][j] == '1')
		{
			z++;
		}
		else if(res[i][j] == '0')
		{
			n++;
		}
		if(i==999)
		{	
			vueltas1++;
			if ( z > n)
			{
				
				printf("La vuelta %d la gana 1 %d\n",vueltas1,z );
			}
			else if ( n > z)
			{
				printf("La vuelta %d la gana 0 %d\n",vueltas1,n );
			}	
			z = 0;
			n = 0;
			j++;
			i = 0;
		}
		i++;
	}

	return 0;
}
