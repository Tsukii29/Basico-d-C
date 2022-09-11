#include <stdio.h>

int main(){
	FILE *arq;
	arq=fopen("notas.txt", "r");
	
	char notasA[30], notasB[30], notasC[30];
	int i=48, j=32;
	
	fseek(arq,i*sizeof(char),SEEK_SET);
	fseek(arq,j*sizeof(char),SEEK_CUR);
	
	fgets(notasA,27,arq);
	printf("\n%s", notasA);
/*	fgets(notasB,24,arq);
	printf("\n%s", notasB);
	fgets(notasC,25,arq);
	printf("\n%s", notasC);*/
}
