#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
int main()
   {
     float preconormal, descontopromo, valor_a_pagar, precototal;
     float preco_lancamento = 20;
     float preco_fora_lancamento = 10;
     int cod_cli, dia, categoria;
     char resp ='S';
   do
     {
       system("cls");	
       printf("\nDigite o codigo do cliente => ");
       scanf("%d", &cod_cli);
	   
       printf("\nDigite a categoria (1)- LANCAMENTO  (2)- FORA DE LANCAMENTO => ");
       scanf("%d",&categoria);
       	   
       printf("\nDigite o dia da semana  1 - SEG  2 - TER  3 - QUA  4 - QUI  5 - SEX  6 - SAB => ");
       scanf("%d",&dia);
       
       if (dia == 1 && categoria == 1) 
         {
           valor_a_pagar = preco_lancamento - (0.01 * preco_lancamento) ; 
           printf("\n\nEntrei A");
         }
       else if (dia == 1 && categoria == 2)
	       {
             valor_a_pagar = preco_fora_lancamento - (0.02 * preco_fora_lancamento);
             printf("\n\nEntrei B");
	       }
	      
       else if  ((dia == 2 || dia == 3 || dia == 4) && (categoria == 1))
	       {
             valor_a_pagar = preco_lancamento - (0.05 * preco_lancamento) ;  
             printf("\n\nEntrei C");
           }
       else if ((dia == 2 || dia == 3 || dia == 4) && (categoria == 2))
           {
	         valor_a_pagar = preco_fora_lancamento - (0.05 * preco_fora_lancamento);
	         printf("\n\nEntrei D");
	       }
 
       else if ((dia == 5  || dia == 6) && (categoria == 1))
	       {
             valor_a_pagar = preco_lancamento; 
	         printf("\n\nEntrei E"); 
           }
       else if ((dia == 5  || dia == 6) && (categoria == 2))
	       {
	         valor_a_pagar = preco_fora_lancamento;
	         printf("\n\nEntrei F");
	       }
 
     printf("\n\nPRECO FINAL A PAGAR = %.2f\n", valor_a_pagar);
     printf("\n\nQuer fazer outro entrada de dados [s/n] : ");
	 resp = toupper(getche()); 
    }
   while (resp == 'S'); 
  return 0;	
 
}
