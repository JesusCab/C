/*lista de numeros enteros
1)agregar elementos a una lista al final
2) agregar elementos al principio
3) agregar elementos despues de cierto numero
4) buscar un elemento despues de cierto numero
5) eliminar el primer elemento de la lista
6) eliminar el ultimo elemento de la lista
7) eliminar cualquier elemento de la lista*/
#include <stdio.h>
#include <stdlib.h>
struct Elementos{
	int dato;
	struct Elementos *sig;
};
typedef struct Elemento Elem;
typedef Elem* L;



void agrfin();
void agrprin();
void agrcnum();
void buscnum();
void elimpnum();
void elimunum();
void elimcel();

int main(){
	int opc,i,n,j;
	do{
	printf("Eliga una opcion par realizar su lista:\n\t[1]Agregar elemento al final\n\t[2]Agregar elemnto al principio\n\t[3]Agregar despues de cierto numero\n\t[4]Buscar cierto numero\n\t[5]Eliminar primer numero\n\t[6]Eliminar el ultimo numero\n\t[7]Eliminar cualquier numero(1 por 1)\n\t[8]Salir");
	scanf("%d",&i);	
		switch(opc){
			case 1:
			agrfin();
				break;
				
			case 2:
				agrprin();
				break;
				
			case 3:
				agrcnum();
				break;
			case 4:
				buscum();
				break;
			
			case 5:
				elimpnum();
				break;
			
			case 6:
				elimunum();
				break;
			
			case 7:
				elimcel();				
				break;
			
			case 8:
			break;
			default:
				break;
			}
		}while(opc!=8);	
system("pause");
return 0;	
}

void agrfin(L *lista,int dato){
	Elem* nuevo = (Elem*)calloc(sizeof(Elem));
	nuevo->dato = dato;
	nuevo->sig = NULL;
	
	if(*lista == NULL)
		*lista = nuevo;
	else{
		nuevo->sig = *lista;
		*lista = nuevo;
		}
}
void agrprin(){
	
}
void agrcnum(){
	
}
void buscnum(){
	
}
void elimpnum(){
	
}
void elimcel(){
	
}
