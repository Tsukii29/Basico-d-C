#include <stdio.h>
int main(){
	int Dias;
	float Anos;
		printf("Entre com um numero inteiro de dias: ");
		scanf("%d", &Dias);
		Anos = Dias/365.25;
		printf("\nO numero de %d dias equivale a %.2f anos!", Dias, Anos);
	return(0);
		
}
