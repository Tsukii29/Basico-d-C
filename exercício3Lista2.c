#include <stdio.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int n,i,j,vezes;
	float vetor[100];
	
	//definindo o tamanho 'n' do vetor
	printf("\nDigite a quantidade 'n' desejada para o tamanho da sequência: ");
	scanf("%d", &n);
	
	//lendo os valores digitados n vezes
	printf("Digite %d numeros reais:\n", n);
	for(i=0;i<n;i++){
		scanf("%f", &vetor[i]);
	}
	printf("\n\n\nResultados:");
	
	// conta o numero de vezes que o valor de vetor[i] aparece a partir da posição i
	for(i=0;i<n;i++) {
		vezes=1;
		
		//j são os da frente de um em um
		j=i+1;
		while(j<n){
			//se não for igual, tenta de novo
			if (vetor[j]!=vetor[i]){
				j++; 
			} 
			//se for igual incrementa vezes, e remove 1 de 'n' - igualando o vetj ao vetn pra deixar
			//o posicionamento certo e não bugar a quantidade de vezes que ocorre a repetição
			else {
				vezes++;
				n--;                   
				vetor[j]=vetor[n];       
			}
		}
		if(vezes==1){
			printf("\n%.2f ocorre %d vez.", vetor[i], vezes);
		}
		else if(vezes>1){
			printf("\n%.2f ocorre %d vezes.", vetor[i], vezes);
		}
	}
  return 0;
}
