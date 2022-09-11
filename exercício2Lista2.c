#include<stdio.h>
#include<math.h>
#include<locale.h>

int main(){
	//Botando portugues
	setlocale(LC_ALL, "Portuguese");
	
	//info dos lados
	float ladoA, ladoB, ladoC, hipot, cat1, cat2;
	printf("Digite o primeiro lado do triângulo: ");
	scanf("%f", &ladoA);
	printf("Digite o segundo lado do triângulo: ");
	scanf("%f", &ladoB);
	printf("Digite o terceiro lado do triângulo: ");
	scanf("%f", &ladoC);
	
	//definindo a hipotenusa e os catetos
	hipot=ladoA;
	cat1=ladoA;
	cat2=ladoA;
	if(ladoC>ladoA&&ladoC>ladoB){
		hipot=ladoC;
		cat1=ladoA;
		cat2=ladoB;
	}
	else if(ladoA>ladoB&&ladoA>ladoC){
		hipot=ladoA;
		cat1=ladoB;
		cat2=ladoC;
	}
	else if(ladoB>ladoA&&ladoB>ladoC){
		hipot=ladoB;
		cat1=ladoA;
		cat2=ladoC;
	}
	
	//testando se é triangulo
	if(ladoA+ladoB<ladoC||ladoA+ladoC<ladoB||ladoB+ladoC<ladoA){
		printf("\nOs valores inseridos não formam um triângulo.");
	}
	else if(ladoA+ladoB>=ladoC && ladoA+ladoC>=ladoB && ladoB+ladoC>=ladoA){
		printf("\nOs valores inseridos formam um triângulo!");
		
		//na condição de ser um triangulo temos a primeira qualidade:
		if(ladoA==ladoB&&ladoA==ladoC){
			printf("\n\nOs valores inseridos formam um triangulo equilátero.");
		}
		else if(ladoA==ladoB&&ladoA!=ladoC||ladoA!=ladoB&&ladoA==ladoC||ladoA!=ladoB&&ladoB==ladoC){
			printf("\n\nOs valores inseridos formam um triangulo isósceles.");
		}
		else if(ladoA!=ladoB&&ladoA!=ladoC&&ladoB!=ladoC){
			printf("\n\nOs valores inseridos formam um triangulo escaleno.");
		}
		
		//e a segunda qualidade:
		if(pow(hipot,2)==pow(cat1,2)+pow(cat2,2)){
			printf("\n\nAlém disso, esse triângulo é retângulo!");
		}
		else if(pow(hipot,2)>pow(cat1,2)+pow(cat2,2)){
			printf("\n\nAlém disso, esse triângulo é obtusângulo!");
		}
		else if(pow(hipot,2)<pow(cat1,2)+pow(cat2,2)){
			printf("\n\nAlém disso, esse triângulo é acutângulo!");
		}
		}
		return(0);
	}
