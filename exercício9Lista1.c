#include <stdio.h>
int main(){
	int i=1,j,max=0, soma=0;
	printf("Digite um valor máximo para se encontrar os numeros perfeitos: ");
	scanf("%d", &max);
	
	for(j=1;j<=max;j++){
		soma=0;
		for(i=1;i<j;i++){
			if(j%i==0){
				soma=soma+i;
			}
		}
		if(soma==j){
			printf("\nO numero %d eh perfeito", j);
		}
		else{
			printf("\nO numero %d n eh perfeito", j);
		}
	}
return(0);	
}
