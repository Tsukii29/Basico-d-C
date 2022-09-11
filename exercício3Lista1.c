#include <stdio.h>

int main(){
	
	int i=1, inteiro=0, total=0, numpri=0;
	
	while(i!=0){
		printf("\nDigite um numero inteiro para verificar se o mesmo é primo: ");
		scanf("%d", &inteiro);
		int divisor=2, primo=1;
			if (inteiro<2){
				primo=0;
			}
		
		    while (primo==1 && divisor<=inteiro/2){
			if (inteiro%divisor==0)
			    primo=0;
				divisor++;
		    }
	
		    if (primo==1){
				printf("%d eh primo \n", inteiro);
				numpri++;
			
			}
		    else if(primo==0){
			printf("%d nao eh primo \n", inteiro);
			}
			printf("o total de numeros digitados eh: %d", i);
			printf("\no total de numeros primos encontrados eh: %d\n", numpri);
		i++;}
	
}


//scanf("tipo%alguma",&variavel);
