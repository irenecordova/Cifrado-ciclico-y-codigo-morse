#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char mensajeCifrado[1024]="";
char lista[100][100]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
                                "--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-",
                                "-.--","--.."};

int cifradoCiclico(char cadena[],  int llave)
{
	for (int i=0; i<strlen(cadena); i++)
        {
          char caracter=cadena[i];
          if  (ispunct(caracter) || isspace(caracter))
                mensajeCifrado[i]=caracter;
	  else if (llave>0)
          	if  (((caracter+llave) > 90) && (caracter < 97 ))
			mensajeCifrado[i]=caracter+llave-(26*((caracter+llave-65)/26));
	  	else if (((caracter+llave) > 122) && (caracter > 96))
	 		mensajeCifrado[i]=caracter+llave-(26*((caracter+llave-97)/26));
		else
			mensajeCifrado[i]=caracter+llave;
	  else if (llave<0)
		if (((caracter+llave) < 90) && (caracter < 91))
			if ((caracter+llave) >= 65)
				mensajeCifrado[i]=caracter+llave;
			else 
				mensajeCifrado[i]=caracter+llave+(26*(((caracter-llave-65)/26)+1));
		else if (((caracter+llave) < 122) && (caracter > 96))
			if ((caracter+llave) >= 97)
				mensajeCifrado[i]=caracter+llave;
			else		
				mensajeCifrado[i]=caracter+llave+(26*(((caracter-llave-97)/26)+1));
	  	else
                	mensajeCifrado[i]=caracter+llave+26;
    	 printf("%c", mensajeCifrado[i]);
        }
}

int cifradoClaveMorse(char cadena[], int llave)
{
	for (int i=0; i<strlen(cadena); i++)
	{
	  char caracter=cadena[i];
	  if ispunct(caracter)
		printf("%c ",caracter);
	  else if isspace(caracter)
		printf("/ ");
      	  else
		{
		  caracter=toupper(cadena[i]);
		  printf("%s ",lista[caracter-65]);
		}		  
	}
}


int main(int argc, char *argv[])
{

	if (argc==3)
	{
		printf("Mensaje cifrado: ");
	   	cifradoCiclico(argv[2], atoi(argv[1]));
		printf("\n");
		printf("Mensaje cifrado en morse: ");
		cifradoClaveMorse(mensajeCifrado, atoi(argv[1]));
		printf("\n");
		return 0;
	}
	else if (argc==2 || argc>3)
	{
		puts("Debe ingresar 3 parámetros.");
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
        	scanf("%d", &llave);
		printf("Mensaje cifrado: ");
		cifradoCiclico(mensaje, llave);
		printf("Mensaje cifrado en morse: ");
		cifradoClaveMorse(mensajeCifrado, llave);
                printf("\n");		
		return 0;
	} 
}
