#include <stdio.h>

int main(){
	char str[80]= " ";
	int i=0, qnt=0, pnt=0, num=0, lwc=0;

	printf("\nDigite uma frase de ateh 80 caracteres: ");
	gets(str);

	for(i=0;i<80; i++){
		int ind=str[i];
		if(ind!=0 && ind!=32){
			qnt++;
		}
		
			if(ind>47 && ind<58){
				num++;
			}
			else if((ind>32 && ind<48) || (ind>57 && ind<65)){		//se for pontuação
				pnt++;
			}
			else if(ind>96 && ind<123){
				lwc++;
			}
	}
	printf("\nO numero de caracteres eh: %d", qnt);
	printf("\nO numero de numeros eh: %d", num);
	printf("\nO numero de pontuações eh: %d", pnt);
	printf("\nO numero de minúsculas eh: %d", lwc);

return(0);
}
