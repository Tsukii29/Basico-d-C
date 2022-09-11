#include<stdio.h>
#include<locale.h> 

int main(){
	setlocale (LC_ALL, "Portuguese");
	
	int vetorA[10], vetorB[10], i=0, j=0;
	for(i=0;i<10;i++){
		printf("Digite o valor de posição %d: ", i+1);
		scanf("%d", &vetorA[i]);
		if(vetorA[i]>=0){
			for(vetorB[i]=1;vetorA[i]>1; vetorA[i]=vetorA[i]-1){
				vetorB[i]=vetorB[i]*vetorA[i];
	}
	}
		else if(vetorA[i]<0){
			vetorB[i]=0;
		}
	}
	printf("\nSerão dados os valores no formato:\nPosição em A ===> B\n");
	for(i=0;i<10;i++){
		if(vetorB[i]>=0){
			printf("\n%d ===> %d", i+1, vetorB[i]);
		}
		else{
			printf("\n%d ===> 0", i+1);
		}
	}
}
