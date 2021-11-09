/*Jesus Adrian Caballero Nagaya
iD.1816014
ProgramacionEstructurada/grp.07
26/01/18
*/
#include <stdio.h>
int main()
{
	int entero;
	float real;
	char caracter;
	char cadena [80];
	
	printf("\n\tTeclea un numero entero;");
	scanf("%d, &Entero");
	printf("\n\tTeclea un numero real;");
	scanf("\%f, &real");
	fflush(stdin);
	printf("\n\tTeclea un caracter;");
	scanf("%c, &caracter");
	fflush(stdin);
	printf("\n\tTeclea una frase;");
	gets(cadena);
	printf("\n\tESTE ES UN ENTERO=%d",entero);
	printf("\n\tESTE ES UN REAL+%f",real);
	printf("\n\tESTE ES UN CARACTER=%c",caracter);
	printf("\n\tESTA ES UNA CADENA=%s",cadena);
	
}
