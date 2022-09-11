#include <stdio.h>
#include <string.h>
int main(){
	
	char frase[100], palavra[20];
	printf("Digite uma frase de ateh 100 caracteres: ");
	gets(frase);
	printf("\nDigite uma palavra para ser procurada: ");
	gets(palavra);
	
	int tamanho=0, tamanhoMovel;
	tamanho=strlen(palavra);
	
	int i,j, contador;
	for(i=0;i<100;i++){
		tamanhoMovel=i+tamanho;
		while((frase[i]<=frase[tamanhoMovel])==palavra)
		contador++;
	}
	
	return(0);
}
