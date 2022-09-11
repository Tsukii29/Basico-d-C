#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

typedef struct{
	char rua[30];
	char numero[5];
	char complemento[15];
	char bairro[20];
	char cep[15];
	char cidade[20];
	char estado[20];
	char pais[15];
	
}end;

typedef struct{
	char ddd[5];
	char telnum[15];
	
}tel;

typedef struct{
	int dia;
	int mes;
	int ano;
}aniv;

typedef struct{
	char nome[30];
	char email[30];
	end endereco;
	tel telefone;
	aniv aniversario;
	char obs[50];
	
}dados;

int menu(void);
void inserirDados();
void organizarDados();
void imprimirDadosparcial();
void imprimirDados();
void buscarNome();
void buscarMes();
void buscarDiam();

dados agenda[100];
int k=0;

int main(){
	
	int funcao=0;
	funcao=menu();
	
	if(funcao==1){
		inserirDados();
	}
	if(funcao==2){
		imprimirDados();
	}
	if(funcao==3){
		imprimirDadosparcial();
	}
	if(funcao==4){
		buscarNome();
	}
	if(funcao==5){
		buscarMes();
	}
	if(funcao==6){
		buscarDiam();
	}
	if(funcao==7){
		return(0);
	}
	
}

int menu(){
	int funcao=0;
	
	system("cls");
	printf("===========AGENDA===========");
	printf("\n1-Inserir dados.");
	printf("\n2-Imrpimir dados.");
	printf("\n3-Imrpimir parcial dos dados.");
	printf("\n4-Buscar por nome.");
	printf("\n5-Buscar por mes de aniversario.");
	printf("\n6-Buscar por dia e mes de aniv.");
	printf("\n7-Encerrar.");
	
	printf("\n\nDigite o q deseja fazer: ");
	scanf("%d", &funcao);
	return(funcao);
}

void inserirDados(){
	char resp='S';
	do{
		system("cls");
		printf("=====INSERIR DADOS=====");
		printf("\nDigite o nome: ");
		scanf("%s",  &agenda[k].nome);
		printf("\nDigite o email: ");
		scanf("%s",  &agenda[k].email);
		printf("\nDigite a rua: ");
		scanf("%s",  &agenda[k].endereco.rua)
		printf("\nDigite o numero: ");
		scanf("%s",  &agenda[k].endereco.numero);
		printf("\nDigite o complemento: ");
		scanf("%s",  &agenda[k].endereco.complemento);
		printf("\nDigite o bairro: ");
		scanf("%s",  &agenda[k].endereco.bairro);
		printf("\nDigite o cep: ");
		scanf("%s",  &agenda[k].endereco.cep);
		printf("\nDigite a cidade: ");
		scanf("%s",  &agenda[k].endereco.cidade);
		printf("\nDigite o estado: ");
		scanf("%s",  &agenda[k].endereco.estado);
		printf("\nDigite o pais: ");
		scanf("%s",  &agenda[k].endereco.pais);
		printf("\nDigite o ddd: ");
		scanf("%s",  &agenda[k].telefone.ddd);
		printf("\nDigite telefone: ");
		scanf("%s",  &agenda[k].telefone.telnum)
		printf("\nDigite o dia do aniversario: ");
		printf("\nDigite o mes do aniversario: ");
		printf("\nDigite o ano do aniversario: ");
		k++;
		printf("\nDeseja cadastrar outro contato [s/n]: ");
		resp=toupper(getch());
	}while(resp=='S');
	
}
void imprimirDadosparcial(){
	
}
void imprimirDados(){
	
}
void buscarNome(){
	
}
void buscarMes(){
	
}
void buscarDiam(){
	
}

