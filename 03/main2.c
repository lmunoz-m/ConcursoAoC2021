#include <fcntl.h>      
#include <stdlib.h>     
#include <stdio.h>
#include <string.h>

void take_bits(int pos, char res[1000][100], char valor, int vuelta, char bitsO[1000][100],char bitsZ[1000][100]);
char ganador(int pos, char res[1000][100]);


int main(){

	FILE *fichero; 
	char res[1000][100];
	char bitsO[1000][100];
	char bitsZ[1000][100];
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
	int z = 0, n = 0,vueltas1 =0, t =0, res1 = 0,resTotal=0;
  	while(j<12)
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
/* 			printf("La vuelta %d hay %d unos\n",vueltas1,z );
			printf("La vuelta %d hay %d ceros\n",vueltas1,n ); */

			if ( z > n)
			{
				take_bits(j, res, '1', vueltas1, bitsO,bitsZ);
				printf("La vuelta %d la gana 1 %d\n",vueltas1,z );
			}
			else if ( n > z)
			{
				//take_bits(j, res, '0');
				//printf("La vuelta %d la gana 0 %d\n",vueltas1,n );
			}
			/* else if ( n == z)
				take_bits(j, res, '0'); */

			z = 0;
			n = 0;
			j++;
			i = 0;
		}
		i++;
	}

	return 0;
}

char ganador(int pos, char res[1000][100])
{
	int i = 0, j = 0;
	int z = 0, n = 0, t =0, res1 = 0;
	char resTotal;
  	while(j<12)
	{

		if(res[i][pos] == '1')
		{
			z++;
		}
		else if(res[i][pos] == '0')
		{
			n++;
		}
		if(i==999)
		{	
			if ( z > n)
			{
				printf("El ganador en la pos %d es el 1\n", pos);
				resTotal =  '1';
			}
			else if ( n > z)
			{
				printf("El ganador en la pos %d es el 0\n", pos);
				resTotal = '0';
			}
			else if ( n == z)
				printf("Hay empate en la pos %d\n", pos);
				resTotal = '1'; 

			j = 12;
		}
		i++;
	}

	return resTotal;
}	

void take_bits(int pos, char res[1000][100], char valor, int vuelta, char bitsO[1000][100],char bitsZ[1000][100])
{
	int i = 0, j = 0;
	/* char bitsO[1000][100];
	char bitsZ[1000][100]; */
	int z = 0, n = 0,vueltas1 =0, t =0, s = 0;
	char comp;

	if (vuelta == 1)
	{
		comp = valor;
	}	
	else
	{
		comp = ganador(pos,res);
	}

	while(j<12)
	{
		if(res[i][pos] == comp)
		{
			j = 0;
			n = 0;
			while(j<12)
			{
				bitsO[z][n] = res[i][j];
				
				j++;
				n++;
			}
			printf("Anadido ganando 1 %s\n", bitsO[z]);
			z++;
			j = 0;
		}
		else if(res[i][pos] == comp)
		{
			j = 0;
			s = 0;
			while(j<12)
			{
				bitsZ[t][s] = res[i][j];
				
				j++;
				s++;
			}
			printf("Anadido ganando 0 %s\n", bitsZ[t]);
			t++;
			j = 0;
		}
		
		if(i==999)
		{	
			pos++;
			vuelta++;
			take_bits(pos, res, valor, vuelta, bitsO, bitsZ);
			/* z = 0;
			n = 0;
			j++;
			i = 0; */
		}
		i++;
	}
}



/*void take_bits(int j, char res[1000][100], char valor)
{
 	int	i = 0;
	char bitsO[1000][12];
	char bitsZ[1000][12];

	int s = 0, t =0,z = 0;
  	while(i<1000)
	{
		
		if (res[i][0] == valor)
		{
			bitsO[t][z] = res[i][j]; 
			//z++;
			
			//i = 0;
			
		}
		else if (res[i][0] != valor)
		{
			i++;

		}
		 else if (valor == 0)
		{
			bitsZ[s] = res[i];
			printf("Añadido ganando 0 %s", bitsZ[s]);

		} 
		if(z == 12)
		{
			t++;
			i++;
			 j = 0;
			z = 0; 
		}	
		z++;
		j++;
		

	} 
	int tam = t;
	t = 0;
	while(t<tam)
		printf("Anadido ganando 1 %s", bitsO[t++]);

}*/
