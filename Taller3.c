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
          else if  (caracter == 'Z')
                caracter=caracter-26+llave;
          else
                caracter=caracter+llave;
          printf("%c",caracter);
        }
}


void main()
{
  char cadena[]= "ZOILA";
  cifradoCiclico(cadena, 3);
}



