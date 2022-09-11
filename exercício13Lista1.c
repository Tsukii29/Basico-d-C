#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	int a, b, c;
	printf("\nDigite o valor do lado a de seu triangulo: ");
	scanf("%d", &a);
	printf("\nDigite o valor do lado b de seu triangulo: ");
	scanf("%d", &b);
	printf("\nDigite o valor do lado c de seu triangulo: ");
	scanf("%d", &c);
	
	if(a+b<c || a+c<b || b+c<a){
		printf("\nO triangulo n é possivel.");
	}
	else if(a+b>c && a+c>b && b+c>a){
		printf("\nO triangulo formado é possivel.");
	}
	if(a==b && a==c){
		printf("\nEsse triangulo é equilátero");
	}
	else if(a==b || a==c || b==c){
		printf("\nEsse triangulo é isóceles");
	}
	else{
		printf("\nEsse triangulo é escaleno");
	}
	return(0);
}
