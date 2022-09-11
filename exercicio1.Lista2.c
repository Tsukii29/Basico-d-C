#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>
int main(){
	//colocando com acento
	setlocale(LC_ALL, "Portuguese");
	//repetição do programa
	char resp;
	do{
		//pegando as infos
		float numA, numB, numC;
		printf("Digite o primeiro coeficiente: ");
		scanf("%f", &numA);
		printf("Digite o segundo coeficiente: ");
		scanf("%f", &numB);
		printf("Digite o terceiro coeficiente: ");
		scanf("%f", &numC);
		
		//utilizando bask
		float raiz1, raiz2, delta, numerador1, numerador2, denominador;
		delta=numA*numC;
		delta=4*delta;
		delta=pow(numB, 2)-delta;
		denominador=2*numA;
		if(delta>=0&&denominador!=0){
			numerador1=(-numB)+sqrt(delta);
			raiz1=numerador1/denominador;
			numerador2=(-numB)-sqrt(delta);
			raiz2=numerador2/denominador;
			
		//resultados	
			printf("\nDelta: %.2f\nNumerador1: %.2f\nNumerador2: %.2f\nDenominador: %.2f", delta, numerador1, numerador2, denominador);
			printf("\n\nAs raizes encontradas foram %.2f e %.2f", raiz1, raiz2);
			
		//qualidade das raizes encontradas
			if(raiz1!=raiz2){
				printf("\n\nAs raizes são distintas!");
				getch();
			}
			else if(raiz1==raiz2){
				printf("\n\nA raiz é única!");
				getch();
			}
		}
		else{
			printf("\nOs valores digitados não possuem raizes válidas ou são imaginárias");
		}
		
		printf("\n\nInforme se deseja tentar novamente[s/n]: ");
		resp=toupper(getch());
		if(resp=='S'){
			system("cls");
		}
	}
	while(resp=='S');
	//finalização
	if(resp!='S'){
		system("cls");
		printf("Obrigado por utilizar nosso programa!");
		getch();
	}
	
	return(0);
}

