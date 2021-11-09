#include <stdio.h>
main()
{
char Usuario[20];
char contraseña[30];
char usu [20];
char contra[30];

printf("\n\tIntroduce un nombre de usuario");
gets(usuario);
fflush(stdin);
printf("\n\tIntroduce una contraseña");
gets(contraseña);
fflush(stdin);

printf("----------------------------------------");

printf("/n/tNombre de usuario");
gets(usu);
fflush(stdin);
printf("\n\tContraseña:");
gets(contra);

printf("----------------------------------------");

if (contra = contraseña&usu=usuario)
printf ("\n\tBienvenido");
else
printf ("\n\tEL usuario o contraseña no coincide");

	
}
