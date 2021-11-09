//Jesus Adrian Caballero Nagaya ID1816014
//acomodo de numeros por distintos metodos
#include <stdio.h>
int main (){
int i,n,j,k,aux=0,opco,opcb, pos=0,min=0,saltos;
printf("Introduce el numero de elementos del arreglo en desorden:");
scanf("%d",&n);
int A[n];
for(i=0;i<=n;i++){
	printf("\nIntoduce el valor %d:",i);
	scanf("%d",&A[i]);
}
printf("\nBurbuja 1:");
printf("\nInsercion 2:");
printf("\nSeleccion 3:");
printf("\nShell 4:");

printf("\nSelecciona el tipo de ordenamiento");
scanf("%d",&opco);

switch(opco){
	case 1://metodo burbuja
	printf("\nArreglo original:\n");
 for(i=0;i<=n;i++){
     	printf("%i\n",A[i]);
	}
printf("\n");
for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		if(A[j]>A[j+1]){
			aux=A[j];
			A[j]=A[j+1];
			A[j+1]=aux;
	     	}
     	}
     }
     //Ascendente
     printf("\nAscendente:\n");
     for(i=0;i<=n;i++){
     	printf("%i\n",A[i]);
	}
	printf("\n");
	//Desendente
	printf("\nDesendente:\n");
	for(i=n;i>=0;i--){
		printf("%i\n",A[i]);
	}
	break;
	case 2://metodo de insercion
	printf("\nArreglo original:\n");
        for(i=0;i<=n;i++){
     	printf("%i\n",A[i]);
	}
	for(i=0;i<n;i++){
		pos=i;
		aux=A[i];
		while (pos>0&&aux<A[pos-1]){
			A[pos]=A[pos-1];
			pos--;
		}
     	A[pos]=aux;
	}
     //Ascendente
     printf("\nAscendente:\n");
     for(i=0;i<=n;i++){
     	printf("%i\n",A[i]);
	}
	printf("\n");
	//Desendente
	printf("\nDesendente:\n");
	for(i=n;i>=0;i--){
		printf("%i\n",A[i]);
	}
	break;
	case 3://metodo de seleccion
	printf("\nArreglo original:\n");
    for(i=0;i<=n;i++){
    	printf("%i\n",A[i]);
	}
	for(i=0;i<n;i++){
		min=i;
		for(j=i+1;j<=n;j++){
		    if(A[j]<A[min]){
	            min=j;
	        }
	    }
	    aux=A[i];
	    A[i]=A[min];
	    A[min]=aux;
		}
	//Ascendente
    printf("\nAscendente:\n");
    for(i=0;i<=n;i++){
        printf("%i\n",A[i]);
	}
	printf("\n");
	//Desendente
	printf("\nDesendente:\n");
	for(i=n;i>=0;i--){
		printf("%i\n",A[i]);
	 }	
    break;
    case 4: //Metodo shell
    	printf("\nArreglo original:\n");
    for(i=0;i<=n;i++){
    	printf("%i\n",A[i]);
	}
    saltos=n/2;
    while(saltos>0){
   	for (i=saltos;i<n;i++)
   	{
		
	j=i-saltos;
	while(j>=0){
	k=j+saltos;
	if(A[j]<=A[k])	
	j=-1;
	else
	{
		int temp;
		temp=A[j];
		A[j]=A[k];
		A[k]=temp;
		j-=saltos;
	}
	  }
    }   
	saltos=saltos/2;
    }
    	//Ascendente
    printf("\nAscendente:\n");
	printf("\n");
	//Desendente
	printf("\nDesendente:\n");
	for(i=n;i>=0;i--){
		printf("%i\n",A[i]);
	 }	
   }
   printf("\n-----------------------------------------------------------------------------------------------------------------------------");
   printf("\nBusqueda de datos.");
   printf("\nBinaria 1:");
   printf("\nSecuencial 2:");
   printf("\nSelecciona el tipo de Busqueda:");
   scanf("%d",&opcb);
   int inf=0,sup=n,mitad,dato;
   	char band='F';
   printf("\nIntroduce el numero a buscar:");
     scanf("%d",&dato);
   switch (opcb){
   	 case 1://Busqueda Binaria
   	for(i=0;i<=n;i++){
     printf("%i\n",A[i]);
    }
	while(inf<=sup){
		mitad=(inf+sup)/2;
		
		if(A[mitad]==dato){
			band='V';
			break;	
		}
		if(A[mitad]>dato){
			sup=mitad;
			mitad=(inf+sup)/2;
		}
		if(A[mitad]<dato){
			inf=mitad;
			mitad=(inf+sup)/2;
		}
	}
	if(band=='F'){
		printf("\nEl numero no existe");
	}
	else if(band=='V'){
		printf("El Numero existe, en la posicion: %i",mitad);
	}
	break;
	case 2://Busqueda secuencial
	for(i=0;i<=n;i++){
     printf("%i\n",A[i]);
    }
    i=0;
    while(band=='F'&&i<n){
    	if(A[i]==dato){
    		band='V';
		}
		i++;
	}
	if(band=='F'){
		printf("\nElnumero no existe en el arreglo.");
	}
	else if(band=='V'){
		printf("\nEl numero existe, posicion:%i",i);
	}
    }
		
	getch();
	return 0; 
}
