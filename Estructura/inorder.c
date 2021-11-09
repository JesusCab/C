#include <stdio.h>
#include <stdlib.h>
struct nodo{
	int dato;
	struct nodo * izq;
	struct nodo * der;
	struct nodo ** ramas;
	struct nodo * ramas[8];
};


void ino(struct nodo * r){
	if (r != NULL){
		ino(r->izq);
		
		printf("%d",r->dato);
		
		ino(r->der);
	}
}


int main(){
	
	
	
	getch();
	return 0;
}
