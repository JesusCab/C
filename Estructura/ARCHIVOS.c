#include <stdio.h>
#include <stdlib.h>
typedef struct persona{
	char nombre[30];
	int edad;
	struct persona * sgte;
}Persona;

int main(){
	FILE * file;
	int opc;
	Persona * persona = (Persona*)malloc(sizeof(Persona));
		// verificar si el archivo existe
		if(file=fopen("prueba.txt","rb")){
			printf("\n\tSEA BIENVENIDO AL MENU DE OPCIONES!");
			fclose(file);
		}else{
			file=fopen("prueba.txt","wb");
			printf("\n\tEL ARCHIVO HA SIDO CREADO!");
			fclose(file);
		}
		
		
	do{
		printf("\n\t1) INSERTAR EN EL ARCHIVO");
		printf("\n\t2) VER LO QUE HAY EN LA LISTA");
		printf("\n\t3) SALIR");
		printf("\n\tRESPUESTA: ");
		scanf("%d",&opc);
		switch(opc){
			case 1:
				file = fopen("prueba.txt","ab+");
				printf("\n\tDIGITE UN NOMBRE: ");
				fflush(stdin);
				gets(persona->nombre);
				printf("\n\tDigite la edad: ");
				scanf("%d",&persona->edad);
				fwrite(persona,sizeof(Persona),1,file);
				fclose(file);
				break;
			case 2:
				file = fopen("prueba.txt","rb");
				fread(persona,sizeof(Persona),1,file);
				while(!feof(file)){
					printf("\n\tNombre: %s",persona->nombre);
					printf("\n\tedad: %d",persona->edad);
					fread(persona,sizeof(Persona),1,file);
				}
				fclose(file);
				break;
			case 3:
				break;
		}
	}while(opc != 3);
	getch();
	return 0;
}
