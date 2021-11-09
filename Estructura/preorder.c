#include <stdio.h>
#include <stdlib.h>
1211
struct nodo{
	int dato;
	struct nodo * izq;
	struct nodo * der;
	struct nodo ** ramas;
};


void preo(struct nodo * r){
	if (r != NULL){
		printf("%d",r->dato);
		preo(r->izq);
		preo(r->der);
	}
}


int main(){
	
	
	
	getch();
	return 0;
}
