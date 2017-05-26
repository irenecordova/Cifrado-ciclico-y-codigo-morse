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
	  if ispunt(caracter)
		caracter=caracter;
	  else if isspace(caracter)
		caracter="/";
      	  else
		caracter=arreglo[caracter];	
	  printf("%s ",caracter);
}


int main(int argc, char *argv[])
{
	char lista[100][100]={};
	lista[65]=".-";
	lista[66]="-...";
	lista[67]="-.-.";
  	lista[68]="-..";
  	lista[69]=".";
  	lista[70]="..-.";
  	lista[71]="--.";
  	lista[72]="....";
  	lista[73]="..";
  	lista[74]=".---";
  	lista[75]="-.-";
  	lista[76]=".-..";
  	lista[77]="--";
  	lista[78]="-.";
  	lista[79]="---";
  	lista[80]=".--.";
  	lista[81]="--.-";
  	lista[82]=".-.";
  	lista[83]="...";
  	lista[84]="-";
  	lista[85]="..-";
  	lista[86]="...-";
  	lista[87]=".--";
  	lista[88]="-..-";
  	lista[89]="-.--";
  	lista[90]="--..";

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
