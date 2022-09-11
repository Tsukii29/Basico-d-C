#include <stdio.h>
int main(){
	
	int vetor[15], i, contador=0;
	printf("Digite 15 numeros inteiros:\n");
	for(i=0;i<=14;i++){
		scanf("%d",&vetor[i]);
	}
	
	for(i=0; i<=14; i++){
		if(i!=7&&i<15){
			if(vetor[i]==vetor[7]){
				contador++;
			}
		}
	}
	printf("\n\nO numero de numeros iguais ao que esta no meio do vetor é: %d", contador);
}
