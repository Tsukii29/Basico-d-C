#include <stdio.h>

int main(){
	int vetor[10], i=0, soma=0, aux=0;
	
	for(i=0;i<10;i++){
		printf("\nDigite o %d numero inteiro: ",i);
		scanf("%d", &vetor[i]);	
		soma=soma+vetor[i];	
	}

	int media=0, igual=0;
	media=soma/10;
	printf("\nA media desses inteiros eh:%d", media);
	
	for(i=0; i<10; i++){
		if(vetor[i]==media){
			igual++;
			printf("\n\nO inteiro que eh igual a média eh: %d", vetor[i]);
		}
	}
	
	printf("\n\nO numero de vetores iguais a media eh: %d", igual);
	
return(0);
}
