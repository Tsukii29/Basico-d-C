#include <stdio.h>

int main(){
    char cadastro[10];
    printf("Bem vindo a locadora do David Luiz!");
    printf("\nLancamentos tem aluguel de 20 pila e classicos saem por 10 merreca.");
    printf("\nMas quem sabe nao rola um desconto pra vc :D! ");
    printf("\nRecomendamos que responda as perguntas em minusculo e que o dia da semana seja posto como:\n Ex: segunda.\n"); 
    printf("\nObrigado e que vc tenha uma excelente experiencia!");
    printf("\n\nDigite o seu cadastro (ateh 8 caracteres): ");
    gets(cadastro);
    
    
    char dia[20] = " ", tipo[20] = " ";
    printf("\nDigite o dia de semana estamos: ");
    gets(dia);
    printf("\nO filme que vc procura eh novo ou velho? ");
    gets(tipo);
    
    int valor=0;
    if((dia[0] == 's' && dia[1] =='e' && dia[2] == 'g') && tipo[0]=='n'){
        printf("Hoje temos promoção de 10%% em filme novo: cada um sai por 18 pila");
        valor=18;
    }
    else if((dia[0] == 's' && dia[1] =='e' && dia[2] == 'g') && tipo[0]=='v'){
        printf("Hoje temos promoção de 20%% em filme velho: cada um sai por 8 conto");
        valor=8;
    }
    else if(((dia[0] == 't') && tipo[0]=='n')|| ((dia[0] == 'q') && tipo[0]=='n')){
        printf("Hoje temos promoção de 5%% em filme novo! Sai por 19 bozos!");
        valor=19;
    }
    else if(((dia[0] == 't') && tipo[0]=='v')||((dia[0] == 'q') && tipo[0]=='v')){
        printf("Hoje temos promoção de 5%% em filme velho! Sai por 9.5 merrehl!");
        valor=19;
    }    
    else if(tipo[0]=='n'){
        printf("Infelizmente n temos promoções hj. Um filme novo sai no valor integral de 20 fortunas");
        valor=20;
    }
    else if(tipo[0]=='v'){
        printf("Infelizmente n temos promoções hj. Um filme velho sai no valor integral de 10 cruzeiros");
        valor=10;
    }
    
    printf("\n\nCadastro: %s", cadastro);
    printf("\nSelecione seu filme e pague diretamente no caixa!\nValor: R$%d", valor);
return(0);
}
