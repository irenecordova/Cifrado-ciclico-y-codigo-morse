#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
          printf("%c",caracter);
        }
}


int main()
{
	char mensaje[1024];
	int llave;
	puts("CIFRADO CÍCLICO");
  	printf("Ingrese mensaje a cifrar: ");
	fgets(mensaje, 1024, stdin);
	printf("Ingrese la llave númerica: ");
        scanf("%d",&llave);
//	while (isalpha(llave)==1)
//	{
//	   printf("Ingrese sólo números: ");
//         scanf("%d",&llave);
//	}
	printf("Mensaje cifrado: ");
	cifradoCiclico(mensaje, llave);
	printf("\n");
	return 0; 
}
