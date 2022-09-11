#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

#define MAX 5
 
typedef struct
 {
	char aluno[25];
	int matricula;
	float mediaf;
 } dados;

void iniciar(dados *a, dados *b, dados *c);
void preencherDados(dados *a);
void examinarDados(dados *a, dados *b, dados *c);
void imprimirDados(dados *a, dados *b, dados *c);

int totAprov = 0, totReprov = 0;
dados vetor[MAX], vetorAprov[MAX], vetorReprov[MAX];

int main()
 {
	dados vetor[MAX];
	int i;
	
    iniciar(vetor,vetorAprov, vetorReprov);
	preencherDados(vetor);
	examinarDados(vetor, vetorAprov, vetorReprov);
    imprimirDados(vetor, vetorAprov, vetorReprov);
	return(0);	
 }  


void iniciar(dados *a, dados *b, dados *c)
  {
	int i;
	
	for (i=0; i < MAX; i++)
	   {
          strcpy(a[i].aluno, "NULL");
		  a[i].matricula = 0;
		  a[i].mediaf   = -1;
		
		  strcpy(b[i].aluno, "NULL");
		  b[i].matricula = 0;
		  b[i].mediaf   = -1;
		
          strcpy(c[i].aluno, "NULL");
		  c[i].matricula = 0;
		  c[i].mediaf   = -1;
	
	   }  
  }

void preencherDados(dados *a)
  {
	int i;
	for (i=0; i < MAX; i++)
	   {
		system ("cls");
		
		if (strcmp(a[i].aluno, "NULL") == 0)
		  {
		     printf("\nDigite o nome do aluno %d:  ", i+1);
		     scanf("%25s", &a[i].aluno);
		     printf("\nDigite a matr.do aluno %d:  ", i+1);
		     scanf("%5d", &a[i].matricula);
		     printf("\nDigite a media do aluno %d: ", i+1);
		     scanf("%f", &a[i].mediaf);
	      }
	   } 
	system("cls");    
	printf("\nDADOS DIGITADOS: ");  
	for (i=0; i < MAX; i++)
	   {
	     printf("\nNome : \t%10s  Matric.: \t%5d  Media \t%.2f", a[i].aluno, a[i].matricula, a[i].mediaf); 
       }
    getch();   
  }


void examinarDados(dados *a, dados *b, dados *c) 
 {
	int i;
	for (i=0; i < MAX; i++)
	   {
	      if (a[i].mediaf >= 5 && a[i].aluno != NULL)  
		    {
		      b[i] = a[i];
			  totAprov++;
		    }
	      if (a[i].mediaf < 5 && a[i].aluno != NULL)
		    {
			  c[i] = a[i];
			  totReprov++;
		    }
	   }
 } 


void imprimirDados(dados *a, dados *b, dados *c)
  {
	system("cls");
	int i,j;
	
	printf("\nDADOS TOTAIS:\n");  
	for (i=0; i < MAX; i++)
	   printf("\nNome : \t%10s  Matric.: %5d  Media %.2f", a[i].aluno, a[i].matricula, a[i].mediaf); 
	
	printf("\n\nAPROVADOS:\n");   
 	for (i=0; i < MAX; i++)
 	  if (b[i].mediaf != -1)
 	    printf("Nome : \t%10s  Matric.: %5d  Media %.2f\n", b[i].aluno, b[i].matricula, b[i].mediaf); 
 	   
	printf("\n===> Total Aprov.: %d", totAprov);
	  
	printf("\n\nREPROVADOS:");   
 	for (i=0; i < MAX; i++)
 	  if (c[i].mediaf != -1)
 	    printf("\nNome : \t%10s  Matric.: %5d  Media %.2fn", c[i].aluno, c[i].matricula, c[i].mediaf); 
 	   
 	 printf("\n\n===> Total Reprov.: %d", totReprov);  

  }
