#include<stdio.h>
#include<math.h>
#include<locale.h>

int main(){
	//Botando portugues
	setlocale(LC_ALL, "Portuguese");
	
	//info dos lados
	float ladoA, ladoB, ladoC, hipot, cat1, cat2;
	printf("Digite o primeiro lado do tri�ngulo: ");
	scanf("%f", &ladoA);
	printf("Digite o segundo lado do tri�ngulo: ");
	scanf("%f", &ladoB);
	printf("Digite o terceiro lado do tri�ngulo: ");
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
	
	//testando se � triangulo
	if(ladoA+ladoB<ladoC||ladoA+ladoC<ladoB||ladoB+ladoC<ladoA){
		printf("\nOs valores inseridos n�o formam um tri�ngulo.");
	}
	else if(ladoA+ladoB>=ladoC && ladoA+ladoC>=ladoB && ladoB+ladoC>=ladoA){
		printf("\nOs valores inseridos formam um tri�ngulo!");
		
		//na condi��o de ser um triangulo temos a primeira qualidade:
		if(ladoA==ladoB&&ladoA==ladoC){
			printf("\n\nOs valores inseridos formam um triangulo equil�tero.");
		}
		else if(ladoA==ladoB&&ladoA!=ladoC||ladoA!=ladoB&&ladoA==ladoC||ladoA!=ladoB&&ladoB==ladoC){
			printf("\n\nOs valores inseridos formam um triangulo is�sceles.");
		}
		else if(ladoA!=ladoB&&ladoA!=ladoC&&ladoB!=ladoC){
			printf("\n\nOs valores inseridos formam um triangulo escaleno.");
		}
		
		//e a segunda qualidade:
		if(pow(hipot,2)==pow(cat1,2)+pow(cat2,2)){
			printf("\n\nAl�m disso, esse tri�ngulo � ret�ngulo!");
		}
		else if(pow(hipot,2)>pow(cat1,2)+pow(cat2,2)){
			printf("\n\nAl�m disso, esse tri�ngulo � obtus�ngulo!");
		}
		else if(pow(hipot,2)<pow(cat1,2)+pow(cat2,2)){
			printf("\n\nAl�m disso, esse tri�ngulo � acut�ngulo!");
		}
		}
		return(0);
	}
