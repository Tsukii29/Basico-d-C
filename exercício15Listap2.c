#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char frase[50];
	int tamanho;
}str;

int main(){
	
	FILE *arq;
	char nomeArquivo[20];
	printf("Digite o nome do arquivo: ");
	scanf("%s", &nomeArquivo);
	
	arq=fopen(nomeArquivo,"r+");
	if(arq==NULL){
		printf("arquivo nao existente.");
		exit(1);
	}
	
	//preenche os vetores
	str vetor[5];
	int i;
	for(i=0;i<5;i++){
		system ("cls");
		printf("Digite a frase %d de até 50 caracteres: ", i);
		gets(vetor[i].frase);
		vetor[i].tamanho=strlen(vetor[i].frase);
	}
	
	//transforma-os em maiúscula
	int j,k;
	for (j=0; j<5;j++){
		for (k=0; vetor[j].frase[k]!='\0'; k++) {
	    	if(vetor[j].frase[k] >= 'a' && vetor[j].frase[k] <= 'z') {
	        	vetor[j].frase[k] = vetor[j].frase[k]-32;
	    	}
		}
   	}

	//imprime no arquivo txt
	int l;
	for(l=0;l<5;l++){
		fwrite(vetor[l].frase,sizeof(char),vetor[l].tamanho,arq);
		fprintf(arq, "\n");
	}	
	fclose(arq);
	
	//pega uma copia desse arquivo
	str copiaVetor[5];
	arq=fopen(nomeArquivo,"r");
	int m;
	for(m=0;m<5;m++){
		fgets(copiaVetor[m].frase,vetor[m].tamanho,arq);
	}
	
	//imprime o vetor cópia
	int n;
	system("cls");
	for(n=0;n<5;n++){
		printf("\n%s", copiaVetor[n].frase);
	}
	
}



