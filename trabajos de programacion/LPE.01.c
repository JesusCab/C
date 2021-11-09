#include <stdio.h>
main()
{
	int sem;
	float prom;
	char nom[5];
	char carr[3];
	char fac[4];
	
	printf("\n\tIngrese su nombre:");
	scanf("%s",nom);
	fflush(stdin);
	
	printf("\n\tIngrese su carrera:");
	scanf("%s",carr);
	fflush(stdin);
	
	printf("\n\tIngrese su semestre actual:");
	scanf("%d",&sem);
	fflush(stdin);
	
	printf("\n\tIngrese su promedio:");
	scanf("%f",&prom);
	fflush(stdin);
	
	printf("\n\tIngrese el nombre de la facultad:");
	gets(fac);
	fflush(stdin);
	
	printf("\n\tNombre %s",nom);
	printf("\n\tAlumno de la carrera %s",carr);
	printf("\n\tCursando el semestre %d",sem);
	printf("\n\tCon promedio de %.1f",prom);
	printf("\n\tEstudiante de %s",fac);
	
	return 0;
	
}
