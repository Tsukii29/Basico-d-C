#include <stdio.h>

#define MAX 3

typedef struct{
	char nome[30];
	float nota1;
	float nota2;
	
}dados;

int main(){
	
	FILE *arq;
	arq=fopen("notas.txt","w");
	if(arq==NULL){
		printf("não foi possivel abrir o arquivo");
		system("pause");
		return(0);
	}
	fclose(arq);
	
	int i;
	dados vetor[MAX];
	
	for(i=0; i<MAX; i++){
		system("cls");
		printf("\nDigite o primeiro nome do aluno: ");
		scanf("%s", &vetor[i].nome);
		printf("\nDigite a primeira nota : ");
		scanf("%f", &vetor[i].nota1);
		printf("\nDigite a segunda nota: ");
		scanf("%f", &vetor[i].nota2);
	}
	
	system("cls");
	
	float medias[MAX];
	for(i=0; i<MAX; i++){
		medias[i]=(vetor[i].nota1+vetor[i].nota2)/2;
	}
	
	arq=fopen("notas.txt","a");
	for(i=0; i<MAX; i++){
		fprintf(arq, "\n%s\n%.2f\n%.2f\n%.2f",vetor[i].nome, vetor[i].nota1
		, vetor[i].nota2,medias[i]);	
	}
	fclose(arq);
	
	dados copia[MAX];
	float copiaMed[MAX];
	
	arq=fopen("notas.txt", "r");
	fseek(arq,0,SEEK_SET);
	
	for(i=0;i<MAX;i++){
		fscanf(arq,"%s",&copia[i].nome);
		fscanf(arq,"%f",&copia[i].nota1);
		fscanf(arq,"%f",&copia[i].nota2);
		fscanf(arq,"%f",&copiaMed[i]);
	}
	
	for(i=0;i<MAX;i++){
		printf("\n%s",copia[i].nome);
		printf("\n%.2f",copia[i].nota1);
		printf("\n%.2f",copia[i].nota2);
		printf("\n%.2f",copiaMed[i]);
	}
	
	float somaMed=0, mediaGeral;
	for(i=0;i<MAX;i++){
		somaMed+=copiaMed[i];
	}
	mediaGeral=somaMed/MAX;
	
	printf("\n\nA media geral da turma é %.2f",mediaGeral);
		
}
