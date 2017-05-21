#include <stdio.h>
#include <string.h>
#include <ctype.h>

int cifradoCiclico(char cadena[],  int llave)
{


        for (int i=0; i<strlen(cadena); i++)
        {
          char caracter=cadena[i];
          if  ispunct(caracter)
                caracter=caracter;
          else if isspace(caracter)
                caracter=caracter;
          else if  (caracter=='Z' || caracter=='z' || caracter=='Y' || caracter=='y' || caracter=='X' || caracter=='x' )
                caracter=caracter-26+(int)llave;
          else
                caracter=caracter+(int)llave;
          printf("%c",caracter);
        }
}


void main()
{
	char mensaje[50];
	int llave;
	puts("CIFRADO CÍCLICO");
  	printf("Ingrese mensaje a cifrar: ");
	scanf("%s",mensaje);
	printf("Ingrese la llave númerica: ");
	scanf("%d",llave);
	printf("Mensaje cifrado: ");
	cifradoCiclico(mensaje, llave);
}



