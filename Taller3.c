#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int cifradoCiclico(char cadena[],  int llave)
{


        for (int i=0; i<strlen(cadena); i++)
        {
          char caracter=cadena[i];
          if  (ispunct(caracter) || isspace(caracter))
                caracter=caracter;
          else if  (((caracter+llave) > 90 && (caracter+llave) < 97 ) || ((caracter+llave) > 122))
               	caracter=caracter-(26*(llave/26))+llave;
          else
                caracter=caracter+llave;
          printf("%c", caracter);
        }
}

int cifradoClaveMorse(char arreglo[], char cadena[])
{
	for (int i=0; i<strlen(cadena); i++)
	{
	  char caracter=cadena[i];
	  if (ispunt(caracter))
		caracter=caracter;
	  else
		caracter=arreglo[caracter];	
	  printf("%s ",caracter);
}


int main(int argc, char *argv[])
{
	if (argc==3)
	{
		puts("CIFRADO CÍCLICO");   	
		printf("Mensaje cifrado: ");
	   	cifradoCiclico(argv[2], atoi(argv[1]));
		printf("\n");
		return 0;
	}
	else if (argc==2 || argc>3)
	{
		puts("Debe ingresar 2 parámetros.");
		return 0;
	}
	else
	{	
		char mensaje[1024];
		int llave;
		puts("CIFRADO CÍCLICO");
  		printf("Ingrese mensaje a cifrar: ");
		fgets(mensaje, 1024, stdin);
		printf("Ingrese la llave númerica: ");
        	scanf("%d",&llave);
		printf("Mensaje cifrado: ");
		cifradoCiclico(mensaje, llave);
		printf("\n");
		return 0;
	} 
}
