#include <stdio.h>
int main(){
	int numA=0, numB=0, i=0;
	
	printf("\nDigite um primeiro valor: ");
	scanf("%d", &numA);
	printf("\nDigite um segundo valor: ");
	scanf("%d", &numB);
	
	if(numA>numB){
	printf("\nA lista dos numeros do primeiro valor ateh o segundo eh:\n%d", numA);
		while(numA>numB){
			numA=numA-1;
			printf("\n%d",numA);
		}
	}
	else if(numA<numB){
	printf("\nA lista dos numeros do primeiro valor ateh o segundo eh:\n%d", numA);
		while(numA<numB){
			numA=numA+1;
			printf("\n%d", numA);
		}
	}
	else if(numA==numB){
		printf("\nOs valores são iguais!");
	}
	
	return(0);
}
