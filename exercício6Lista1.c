#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

int mdc(int num1, int num2);

int main(){
	char resp='S';
	
	do{
	system("cls");
	int num1, num2, resultado;
	printf("Digite dois numeros: ");
	scanf("%d %d", &num1,&num2);
	resultado=mdc(num1, num2);
	printf("\nResultado %d", resultado);
	
	printf("\nDeseja rodar de novo[s/n]:");
	resp=toupper(getche());
	}
	while(resp=='S');
	
}

int mdc(int num1, int num2) {

    int resto;

    do {
        resto = num1 % num2;

        num1 = num2;
        num2 = resto;

    } while (resto != 0);

    return num1;
}
