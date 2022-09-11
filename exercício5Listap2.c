#include <stdio.h>

void imprimeVetor(float vetor[20]);
float trocaPosicoes(float vetor[20]);

void main(){
	
	float vetor[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	
	printf("Vetor inicial:\n");
	imprimeVetor(vetor);
	
	printf("===============\n");
	vetor[20]=trocaPosicoes(vetor);
	
	printf("Vetor trocado:\n");
	imprimeVetor(vetor);
	
}

void imprimeVetor(float vetor[20]){
	
	int i;
	for(i=0;i<20;i++){
		printf("%.2f\n", vetor[i]);
	}
}

float trocaPosicoes(float vetor[20]){
	int i,j;
	float aux;
	for (i=0,j=19; i<12,j>9; i++, j--){
		aux=vetor[i];
		vetor[i]=vetor[j];
		vetor[j]=aux;
	}

}

