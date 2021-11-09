#include <stdio.h>
#include <math.h>
main()
{
	float votos,a,b,c,d,e,porciento;
	
	printf("ingresa el total de votos:");
	scanf("%f",&votos);
	printf("\n\tPARTIDO                    VOTOS");
	printf("-------                    -----");
	
	a=votos*.40,b=votos*.30,c=votos*.15,d=votos*.10,e=votos*.5;	
	
	printf("\n\tPAN                        %f",a);
	printf("\n\tPRI                        %f",b);
	printf("\n\tPT                         %f",c);
	printf("\n\tIndependiente              %f",d);
	printf("\n\tOtros                      %f",d);

	return 0;
	
}
