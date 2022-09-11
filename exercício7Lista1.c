#include <stdio.h>
int main(){
	int vetor[10], i=0, Min=0, Max=0;
	
	
	for(i=0; i<10; i++){
		printf("Digite o %d numero: ", i+1);
		scanf("%d", &vetor[i]);
		if(i==0){
			Min=vetor[i];
			Max=vetor[i];
		}
		if(vetor[i]>Max){
			Max=vetor[i];
		}
		if(vetor[i]<Min){
			Min=vetor[i];
		}
	}
	printf("\nO maior valor digitado foi: %d", Max);
	printf("\nO menor valor digitado foi: %d", Min);
return(0);
}
