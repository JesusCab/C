//Caballero Nagaya Jesus Adrian ID.1816014  Estructura de Datos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estructuras-listas
typedef struct Avion{
	int ID;
	char Nombre[20];
    char Piloto[40];
    int CantMax;
    int AO;
    //puntero de la lista
 struct Avion *sig;
}A;
typedef struct Pasajero{
		int ID;
	char Nombre[40];
    int Edad;	
    int IDA;
    //puntero de la lista
 struct Pasajero *sig;
}P;
typedef A* LA;
typedef P* LP;

//prototipos
void Menu();
void subMenu(LA*,LP*,int opc);
void Altas(LA*,LP*,int opc); 
void Modificar(LA*,LP*,int opc);
void Bajas(LA*,LP*,int opc);
void BuscarLleno(LA,LP);
void BuscarVacio(LA,LP);
void imprimir(LA,LP,int opc);
int IDV(LA,LP,int IDA);
void ElimBoleto(LA,LP, int ID);
void ElimVuelo(LA,LP,int IDA);

//main
int main(){
	Menu();
	system("pause");
	return 0;
}

//funciones
void Menu(){
	LA nodoA=NULL;
	LP nodoP=NULL;
	int opc;
	opc=0;
	do{
	system("cls");
	printf("\n\tBienvenido Al Aeropuerto Del Norte!!! ");
	printf("\n\t----->>>----->>>----->>>------>>>----->>>\n\tSeleccione una opcion (Introduzca[0] para salir):");
	printf("\n\t[1]Avion.");
	printf("\n\t[2]Pasajeros.");	
    printf("\n\t[3]Mostrar Aviones.");
	printf("\n\t[4]Mostrar Pasajeros.");
	printf("\n\t[5]Mostrar Aviones Llenos.");
	printf("\n\t[6]Mostrar Aviones Disponibles.");
	printf("\n\t\t>>>");
	scanf("%d",&opc);
	system("cls");
	switch(opc){
        case 0:
		system("exit");//termina el programa
        break;
		case 1:
		printf("\nAvion.");
		subMenu(&nodoA,&nodoP,opc);  
		break;
		case 2:
        printf("\nPasajeros.");
		subMenu(&nodoA,&nodoP,opc);
        break; 
        case 3:
		imprimir(nodoA,nodoP,opc);
        break;
        case 4:
		imprimir(nodoA,nodoP,opc);
        break;
        case 5:
		BuscarLleno(nodoA,nodoP);
        break;
        case 6:
		BuscarVacio(nodoA,nodoP);
        break;
		}
	}while(opc!=0);
}

void subMenu(LA *nodoA,LP *nodoP, int opc){ 

	int opc2=0;
	printf("\nContinuando...");
	printf("\n[0]Regresar.");
	printf("\n[1]Altas.");
	printf("\n[2]Bajas.");
	printf("\n[3]Modificar.");
		printf("\n\t\t>>>");
    scanf("%d",&opc2);	
	switch(opc2){
		case 0:
		return;
		break;
		case 1:
		Altas(nodoA,nodoP,opc);
		break;
		case 2:
		Bajas(nodoA,nodoP,opc); 
		break;
		case 3:
		Modificar(nodoA,nodoP,opc);
		break;
	}
}


void Altas(LA *nodoA,LP *nodoP, int opc){
     LA auxA=*nodoA;
     int Val=2;
	if(opc==1){
 
	A* nuevo=(A*)malloc(sizeof(A));
	 do{
	system("cls");
	printf("\nAvion:");
	printf("\n\tID: ");
	scanf("%d",&nuevo->ID);
	fflush(stdin);
	printf("\n\ttNombre del Avion: ");
	scanf("%s",&nuevo->Nombre);
	fflush(stdin);
	printf("\n\tPiloto: ");
	gets(nuevo->Piloto);
	printf("\n\tCantidad Maxima Pasajeros: ");
	scanf("%d",&nuevo->CantMax);
	nuevo->AO=0;
	printf("\n\t\t¿Los datos son correctos?[1]SI[2]NO: ");
	scanf("%d",&Val);
	fflush(stdin);
	}while(Val==2);
	nuevo->sig = NULL;
	if(*nodoA==NULL){
		*nodoA=nuevo;
	}
	else{
		nuevo->sig=*nodoA;
		*nodoA=nuevo;
			}
		}
		
if(opc==2){
	
           	P* nuevo=(P*)malloc(sizeof(P));
	do{
       	     int IDA;
	system("cls");
	printf("\nPasajeros:");
	printf("\n\tID Pasajero: ");
	scanf("%d",&nuevo->ID);
	fflush(stdin);
	printf("\n\tNombre del Pasajero: ");
	gets(nuevo->Nombre);
	printf("\n\tEdad: ");
	scanf("%d",&nuevo->Edad);
	printf("\n\tID avion: ");
	scanf("%d",&nuevo->IDA);
	fflush(stdin);
	Val=IDV(*nodoA,*nodoP,nuevo->IDA);
		if(Val==29){
                printf("No hay aviones disponibles\n");
                system("pause");
                return;
                }
		if(Val!=3){
		printf("\n\t¿Los datos son correctos?[1]SI[2]NO: ");
		scanf("%d",&Val);
		}else Val=2;
		if(Val==1){
         	while(auxA != NULL){
                       if(auxA->ID==nuevo->IDA){
                     	if(auxA->AO<auxA->CantMax){
                       auxA->AO++;
                        system("pause");
						}else{
      					printf("AVION LLENO\n");
     					system("pause");
      					return;
							}
   					  }
    			auxA=auxA->sig;
			}
        }
	}while(Val==2);
	nuevo->sig = NULL;
	if(*nodoP==NULL){
	*nodoP=nuevo;
	}
	else{
		nuevo->sig=*nodoP;
		*nodoP=nuevo;
		}
   	}
}


void Bajas(LA *nodoA,LP *nodoP,int opc){
int ID=0;
     if(opc==1){
     printf("ID del Avion a eliminar");
     scanf("%d",&ID);
if(*nodoA==NULL)
printf("Lista vacia\n");
else{
	LA aux=*nodoA;
	LA previo=NULL;
	if(aux->ID==ID){
		  LA aux=*nodoA;
      *nodoA=aux->sig;
      free(aux);
	}else{
	while(aux->sig!=NULL&&aux->ID!=ID){
		previo=aux;
		aux=aux->sig;
	}
	if(aux->ID==ID){
		if(aux->sig==NULL){
			previo->sig=NULL;
			free(aux);
		}else{
			previo->sig=aux->sig;
			free(aux);
			}
			}else printf("El elemento no existe\n");
		}
	}
}

if(opc==2){
     printf("ID del Pasajero a eliminar");
     scanf("%d",&ID);
if(*nodoP==NULL)
printf("Lista vacia\n");
else{
	LP aux=*nodoP;
	LP previo=NULL;
	if(aux->ID==ID){
		  LP aux=*nodoP;
      *nodoP=aux->sig;
      free(aux);
		}else{
		while(aux->sig!=NULL&&aux->ID!=ID){
		previo=aux;
		aux=aux->sig;
			}
			if(aux->ID==ID){
				if(aux->sig==NULL){
				previo->sig=NULL;
				free(aux);
				}else{
					previo->sig=aux->sig;
					free(aux);
					}
				}else printf("El elemento no existe\n");
				}
			}
	}
system("pause");
}

void imprimir(LA nodoA,LP nodoP,int opc){
     int opc2;
         int ID;
         char Nombre[10];    
     if(opc==3){
    printf("Aviones\n");
    printf("\n[1]Todos.");
	printf("\n[2]ID(procura sea unico).");	
    printf("\n[3]Nombre.");
    printf("\n\t\t>>>");
    scanf("%d",&opc2);
     switch(opc2){
              
    case 1:
	while(nodoA!=NULL){
	printf("\n\t ID del Avion :%d",nodoA->ID);
	printf("\n\tNombre Del Avion :%s",nodoA->Nombre);
	printf("\n\tNombre Del Piloto a cargo del Avion:%s",nodoA->Piloto);
	printf("\n\tCantidad Max de pasajeros :%d",nodoA->CantMax);
	printf("\n\tAsientos Ocupados: %d",nodoA->AO);
	nodoA=nodoA->sig;
	}break;
	case 2:
	printf("\n\tIngrese ID que desea imprimir: ");
	scanf("%d",&ID);
        while(nodoA->ID!=ID){
    if(nodoA->sig==NULL)
    break;
    else
   	nodoA=nodoA->sig;                     
	 }
     if(nodoA->ID==ID){
		printf("\n\tID del Avion :%d",nodoA->ID);
	printf("\n\tNombre Del Avion :%s",nodoA->Nombre);
	printf("\n\tNombre Del Piloto a cargo del :%s",nodoA->Piloto);
	printf("\n\tCantidad Max de pasajeros :%d",nodoA->CantMax);
		}
    break;
    case 3:
	printf("Ingrese Nombre que desesa imprimir: ");
	scanf("%s",&Nombre);
              	while(strcmp(nodoA->Nombre, Nombre)!=0){
    if(nodoA->sig==NULL){
    break;
	}else{
   	nodoA=nodoA->sig;    
	}
 }
     if(strcmp(nodoA->Nombre,Nombre)==0)
 {
	printf("\n\tID del Avion :%d",nodoA->ID);
	printf("\n\tNombre Del Avion :%s",nodoA->Nombre);
	printf("\n\tNombre Del Piloto a cargo del Avion :%s",nodoA->Piloto);
	printf("\n\tCantidad Max de pasajeros : %d",nodoA->CantMax);
		}
    break;
    }
}
	if(opc==4){
    printf("\nPasajeros");
    printf("\n\t[1]Todos.");
	printf("\n\t[2]ID(procure sea unico)");	
    printf("\n\t[3]Nombre.");
    	printf("\n\t\t>>>");
   	 scanf("%d",&opc2);
   	 fflush(stdin);
     switch(opc2){
            printf("Pasajeros\n");
    case 1:  while(nodoP != NULL){
	printf("\n/tID del Pasajero :%d",nodoP->ID);
	printf("\n\tNombre Del Pasajero :%s",nodoP->Nombre);
	printf("\n\tEdad del pasajero :%d",nodoP->Edad);
	printf("\n\tID del Avion asignado para el pasajero %s\n\tID Avion :%d\n",nodoP->Nombre,nodoP->IDA);
	while(nodoA->ID!=nodoP->IDA){
        nodoA=nodoA->sig;               
 }
 printf("\nNombre del Avion Asignado: %s",nodoA->Nombre);
		nodoP=nodoP->sig;
               }break;
         case 2:  printf("Ingrese ID a imprimir: ");
	scanf("%d",&ID);
              	while(nodoP->ID!=ID){
    if(nodoP->sig==NULL)
    break;
    else
   	nodoP=nodoP->sig;                
 }
     if(nodoP->ID==ID){
			printf("\n\tID del Pasajero : %d",nodoP->ID);
	printf("\n\tNombre Del Pasajero : %s",nodoP->Nombre);
	printf("\n\tEdad del pasajero : %d",nodoP->Edad);
	printf("\n\tID del Avion asignado al pasajero %s\n\tID Aavion :%d\n",nodoP->Nombre,nodoP->IDA);
	while(nodoA->ID!=nodoP->IDA){
        nodoA=nodoA->sig;               
 	}
 	printf("\n\tNombre del Avion Asignado: %s",nodoA->Nombre);
    }
    break;
    case 3:printf("Ingrese Nombre a imprimir: ");
	scanf("%s",&Nombre);
    while(strcmp(nodoP->Nombre, Nombre)!=0){
    if(nodoP->sig==NULL){
    break;
	}else{
   	nodoP=nodoP->sig;
		}          
 	}
     if(strcmp(nodoP->Nombre, Nombre)==0){
	printf("\n\tID del Pasajero : %d",nodoP->ID);
	printf("\n\tNombre Del Pasajero : %s",nodoP->Nombre);
	printf("\n\tEdad del pasajero: %d",nodoP->Edad);
	printf("\n\tID del Avion asignado al pasajero %s\n\tIDAvion: %d\n",nodoP->Nombre,nodoP->IDA);
	while(nodoA->ID!=nodoP->IDA){
            nodoA=nodoA->sig;               
 }
 printf("\nNombre del vuelo del Avion Asignado: %s",nodoA->Nombre);
	}
    break;     
            }
     	}	
     system("pause");
    }
     

  void Modificar(LA *nodoA,LP *nodoP,int opc){
          int opc2=0;
              int auxID;
            int Val=2;
          if(opc==1){
          LA aux = *nodoA;
          printf("\n\tModificar Aviones");
          printf("\n\tIngrese ID del avion: ");
          scanf("%d",&auxID);
      	while(aux->ID!=auxID){
    if(aux->sig==NULL){
	break;
	}else{
   	aux = aux->sig; 
		}              
	}
     if(aux->ID==auxID){
    system("pause");
   	printf("\n\tSeleccione lo que desea Modificar");
    printf("\n\t ID Avion :%d",aux->ID);
	printf("\n\t Nombre Del Avion :%s",aux->Nombre);
	printf("\n\t Nombre Del Piloto a cargo del Avion :%s",aux->Piloto);
	printf("\n\t Cantidad Maxima de pasajeros: %d",aux->CantMax);
	  scanf("%d",&opc2);
	  	switch(opc2){
		case 0:
		return;
		break;
		case 1:
		printf("\nIngrese ID: ");              
		scanf("%d",&aux->ID);
		break;
		case 2:
		printf("\nNombre: ");
		scanf("%s",&aux->Nombre);
		fflush(stdin);
		break;
		case 3:
		printf("\nPiloto: ");
		gets(aux->Piloto); 
		break;
		case 4: 
		printf("\nCantidad Maxima Pasajeros: ");
		scanf("%d",&aux->CantMax);
		break;
		}
 		}else{
      	printf("No existe esa ID intente de nuevo\n");
      	system("pause");
     	 return;
        	}
    	}
         if(opc==2){ 
          LP aux = *nodoP;
          printf("\n\tModificar Pasajeros");
          printf("\n\tIngrese ID del Pasajero:");
          scanf("%d",&auxID);
      	while(aux->ID!=auxID){
    if(aux->sig==NULL)
    break;
    else
   	aux = aux->sig;                
 	}
     if(aux->ID==auxID){
      system("pause");
     	printf("\n\tSeleccione lo que desea MODIFICAR");
     	printf("\n\tID del Pasajero :%d",aux->ID);
	printf("\n\tnNombre del Pasajero :%s",aux->Nombre);
	printf("\n\tEdad del pasajero :%d",aux->Edad);
	printf("\n\tID del vuelo asignado al pasajero %s\n\tID Avion: %d\n",aux->Nombre,aux->IDA);
	  scanf("%d",&opc2);
	  	switch(opc2){
		case 0:
		return;
		break;
		case 1:
		printf("\nIngrese ID:");
		scanf("%d",&aux->ID);
		break;
		case 2:
		printf("\nNombre: ");
		scanf("%s",&aux->Nombre);
		fflush(stdin);
		break;
		case 3:
		printf("\nEdad: ");
		scanf("%d",&aux->Edad);
		break;
		case 4:            
            do{
		printf("\nID del nuevo Avion: ");
		scanf("%d",&aux->IDA);
		Val=IDV(*nodoA,*nodoP,aux->IDA);
		if(Val==290120){
        printf("\nNo hay aviones disponibles\n");
        system("pause");
        return;
         }
		}while(Val==2||Val==3);
		break;
		}
 		}else {
      	printf("No existe el ID\n");
      	system("pause");
      	return;
        		}
    		}
     	}
     
 void BuscarLleno(LA nodoA,LP nodoP){
 printf("\n\tAviones Llenos:/n");
 while(nodoA != NULL){
              if(nodoA->AO>=nodoA->CantMax){
		printf("\n\tID Avion :%d",nodoA->ID);
	printf("\n\tNombre del Avion :%s",nodoA->Nombre);
	printf("\n\tNombre del Piloto a cargo del Avion :%s",nodoA->Piloto);
	printf("\n\tCantidad Maxima de pasajeros :%d",nodoA->CantMax);
	printf("\n\tAsientos Ocupados :%d",nodoA->AO);
    		}
    	nodoA=nodoA->sig;
		}
	system("pause");
    }  
      
 void BuscarVacio(LA nodoA,LP nodoP){
 printf("\n\tAviones Disponibles:/n");
 while(nodoA!=NULL){
    if(nodoA->AO<nodoA->CantMax){
	printf("\n\tID Avion :%d",nodoA->ID);
	printf("\n\tNombre del Avion :%s",nodoA->Nombre);
	printf("\n\tNombre del Piloto a cargo del Avion :%s",nodoA->Piloto);
	printf("\n\tCantidad Maxima de pasajeros :%d",nodoA->CantMax);
	printf("\n\tAsientos Ocupados: %d",nodoA->AO);
	printf("\n");
    }
    	nodoA=nodoA->sig;
	}
	system("pause");
      }    
	  
//validar la existencia del id	  
 int IDV(LA nodoA,LP nodoP, int IDA){
    if(nodoA==NULL)
    return 404;
    else{
   	while(nodoA->ID!=IDA){
    if(nodoA->sig==NULL){
    break;
	}else
   	nodoA=nodoA->sig;     
	}
 }
 if(nodoA->ID==IDA){
 return 1;
 }else {
      printf("\n\tNo existe el ID\n");
      system("pause");
      return 4;
         }
	}

