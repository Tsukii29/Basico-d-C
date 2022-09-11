#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>

void gotoxy (short x, short y);

typedef struct{
	int dia;
	int mes;
	int ano;
}dtNasc;
  
typedef struct{
	char rua[20];
	char bairro[15];
	char cidade[15];
	int  numero;
	char complemento[15];
	char cep[10];
}end;

typedef struct{
	char 	nome[25];
	long long int CPF;
	char 	sexo;
	dtNasc  aniv;
	int 	tipo;
	char 	celular[13];
	end 	endereco;
	char	email[30];
	char 	sobre[50];
	int  	vivo;
} dados;
dados cadastro;
int main(){
	
	setlocale (LC_ALL,"portuguese");

	int  menu		();
	void inserir	();
	void consultar	();
	void listar		();
	void alterar	();	
	void excluir	();
	void finalizar	();
	
	FILE *arquivo = fopen ("cadastro.dat", "rb");
	
	if (arquivo == NULL){
	  	printf ("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
		printf ("    D A L I A   B E A C H W E A R    \n");
		printf ("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
		printf ("Boas Vindas à melhor praiana do rio! \n");
		printf ("Como é seu primeiro acesso, insira\n seu contato! \n");
		printf ("(Tecle algo...) \n");
		getch();
		system ("cls");
		fclose(arquivo);
		inserir ();
	}
	else{
		printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
		printf("    D A L I A   B E A C H W E A R    \n");
		printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
		printf("Bem vindo de volta! \n");
		printf("Tecle algo... \n");
		printf("--------------------------------------");
		getch();
	}
	fclose(arquivo);
	
	int opcao;
	do{
		system ("cls");
	  	opcao=menu();
	  	
		switch(opcao){
		  	case 1:
		  		inserir();
		  		break;	
		  	case 2:
		  		consultar();
		  		break;	
		  	case 3:
		  		listar();
		  		break;	
		  	case 4:
		  		alterar();
		  		break;
		  	case 5:
		  		excluir();
		  		break;
		  	case 9:
		  		finalizar();
		  		return 0;
		  		
		  	default:
		  		printf ("-------------------------------------\n");
		  		printf ("Opção invalida!\n");
		  		printf ("Tecle algo...");
				getch();
		}
      } while (1);
	
	return 0;
}

int menu(){
	
	int opcao;
	
	printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
	printf("    D A L I A   B E A C H W E A R    \n");
	printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
	printf("Como podemos atende-lo hj? \n");
	printf("-------------------------------------\n");
	printf("(1) Inserir dados de cliente; \n");
	printf("(2) Consultar dados cadastrados; \n");
	printf("(3) Listar clientes; \n");
	printf("(4) Alterar dados; \n");
	printf("(5) Excluir cadastro de cliente; \n");
	printf("(9) Finalizar programa. \n");
	printf("-------------------------------------\n");
	scanf("%d", &opcao);
	
	return opcao;
}

void inserir(){
	
	FILE *arquivo;
	int encontrado = 1;
	long long int CPFi;
		
	int  CPFexiste 	   (long long int CPF);
		
	fflush(stdin);
	system ("cls");
	
	printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
	printf("    D A L I A   B E A C H W E A R    \n");
	printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
	printf("Digite CPF: ");
	scanf("%lld", &CPFi);
	encontrado = CPFexiste(CPFi);
	
	while (encontrado == 1){
		system ("cls");
		printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
		printf("    D A L I A   B E A C H W E A R    \n");
		printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
		printf ("CPF já registrado! \nTente outro: ");
		scanf("%lld", &CPFi);
		encontrado = 0;
		encontrado = CPFexiste(CPFi);
	}
	
	cadastro.CPF=CPFi;
	while (getchar() != '\n');
	
	printf("\nNome: ");
	gets(cadastro.nome);
	
	printf("Sexo[M/F]: ");
	scanf("%c", &cadastro.sexo);
	
	
	printf("Quando vc nasceu? (XX/XX/XXXX) ");
	printf("\n- Dia: ");
	scanf("%d", &cadastro.aniv.dia);
	printf("- Mês: ");
	scanf("%d", &cadastro.aniv.mes);
	printf("- Ano: ");
	scanf("%d", &cadastro.aniv.ano);
	
	printf("(1 - Bom comprador|2 -Mal comprador)");
	printf("\nTipo de Cliente: ");
	scanf("%d", &cadastro.tipo);
	
	while (getchar() != '\n');
	
	printf("Celular: ");
	gets(cadastro.celular);
	
	printf("Email: ");
	gets(cadastro.email);
	
	printf("Cidade: ");
	gets(cadastro.endereco.cidade);
	
	printf("Bairro: ");
	gets(cadastro.endereco.bairro);
	
	printf("CEP: ");
	gets(cadastro.endereco.cep);
	
	printf("Rua: ");
	gets(cadastro.endereco.rua);
	
	printf("Numero: ");
	scanf("%d", &cadastro.endereco.numero);
	while (getchar() != '\n');
	
	printf("Complemento: ");
	gets(cadastro.endereco.complemento);
	
	printf("Observações gerais:\n ");
	gets(cadastro.sobre);
	
	cadastro.vivo=1;
	
	arquivo = fopen ("cadastro.dat", "a+b");
	
	if (arquivo == NULL){
	  	printf ("Arquivo nao encontrado. \n");
	  	printf ("Aperte uma tecla para continuar.");
	  	getch();
	  	return;
	}
	  
	fwrite (&cadastro, sizeof(dados), 1, arquivo);
	fclose(arquivo);
	
}

void consultar	(){
	system ("cls");
	fflush(stdin);
	
	int opcao;
	
	void consultaCPF         ();
	void consultaNome        ();
	void consultaTipo        ();
	void consultaIdade	     ();
	
	printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
	printf("    D A L I A   B E A C H W E A R    \n");
	printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
	printf("(1) CPF; \n");
	printf("(2) Nome; \n");
	printf("(3) Tipo; \n");
	printf("(4) Idade; \n");
	printf("-------------------------------------\n");
	scanf ("%d", &opcao);
	system ("cls");
	
	switch (opcao){
	  	case 1:
	  		consultaCPF();
	  		break;
	  	case 2:
	  		consultaNome();
	  		break;
	  	case 3:
	  		consultaTipo();
	  		break;
	  	case 4:
	  		consultaIdade();
	  		break;
	  	default:
	  		printf ("-------------------------------------\n");
	  		printf ("Opção inválida!");
	  		getch();
	}
	return;
}

void consultaCPF(){
	
	FILE *arquivo = fopen ("cadastro.dat", "rb");
	fseek(arquivo, SEEK_SET, 0);
	
	long long int cpfFind;
	int encontrado = 0;
	
	system ("cls");
	printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
	printf("    D A L I A   B E A C H W E A R    \n");
	printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
	printf ("CPF: ");
	scanf  ("%lld", &cpfFind);
	printf ("-------------------------------------\n");	

	while (1){
		
	  	fread (&cadastro, sizeof(dados), 1, arquivo);
		
		if (feof(arquivo)){
	  	  	break;
		}
		
		if (cpfFind==cadastro.CPF){
			if (cadastro.vivo==1){
			
				printf("Nome: %s\n", cadastro.nome);
				if(cadastro.sexo=='m'||cadastro.sexo=='M'){
					printf("Sexo: Masculino\n");
				}
				else{
					printf("Sexo: Feminino\n");
				}
				printf("Aniversário: %d/%d/%d\n",cadastro.aniv.dia,
				cadastro.aniv.mes,cadastro.aniv.ano);
				if(cadastro.tipo==1){
					printf("Tipo: %d - (Bom comprador)\n", cadastro.tipo);
				}
				else{
					printf("Tipo: %d - (Mal comprador)\n", cadastro.tipo);
				}
				printf("Obs.: %s\n", cadastro.sobre);
				printf("Celular: %s", cadastro.celular);
				printf("\nEmail: %s\n", cadastro.email);
				printf("Cidade: %s",cadastro.endereco.cidade);
				printf("\nBairro: %s", cadastro.endereco.bairro);
				printf("\nRua: %s",cadastro.endereco.rua);
				printf("\nNumero: %d",cadastro.endereco.numero);
				printf("\nComplemento: %s",cadastro.endereco.complemento);
				printf("\nCep: %s",cadastro.endereco.cep);
				
				encontrado=1;		
			}
		}
	}
	if (!encontrado){
	  	printf ("CPF não cadastrado :(\n");
	  	getch();
	}
	else{
	  	printf("\n-------------------------------------");
	  	printf ("\nVoltando ao menu!");
		getch();
	}
	  
	fclose(arquivo);
}

void consultaNome(){
	
	FILE *arquivo = fopen ("cadastro.dat", "rb");
	fseek(arquivo, SEEK_SET, 0);
	
	char nomeFind[25];
	int encontrado = 0;
	
	system ("cls");
	printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
	printf("    D A L I A   B E A C H W E A R    \n");
	printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
	printf ("Nome: ");
	while (getchar() != '\n');
	gets(nomeFind);
	printf ("-------------------------------------\n");	

	while (1){
		
	  	fread (&cadastro, sizeof(dados), 1, arquivo);
	  	
		if (feof(arquivo)){
	  	  	break;
		  }
		  
		if (!strcmp(nomeFind, cadastro.nome)){
			if (cadastro.vivo==1){
					
				printf("CPF: %lld\n", cadastro.CPF);
				if(cadastro.sexo=='m'||cadastro.sexo=='M'){
					printf("Sexo: Masculino\n");
				}
				else{
					printf("Sexo: Feminino\n");
				}
				printf("Data de Nascimento: %d/%d/%d\n",cadastro.aniv.dia,
				cadastro.aniv.mes,cadastro.aniv.ano);
				if(cadastro.tipo==1){
					printf("Tipo: %d - (Bom comprador)\n", cadastro.tipo);
				}
				else{
					printf("Tipo: %d - (Mal comprador)\n", cadastro.tipo);
				}
				printf("Obs.: %s\n", cadastro.sobre);
				printf("Celular: %s", cadastro.celular);
				printf("\nEmail: %s\n", cadastro.email);
				printf("Cidade: %s",cadastro.endereco.cidade);
				printf("\nBairro: %s", cadastro.endereco.bairro);
				printf("\nRua: %s",cadastro.endereco.rua);
				printf("\nNumero: %d",cadastro.endereco.numero);
				printf("\nComplemento: %s",cadastro.endereco.complemento);
				printf("\nCep: %s",cadastro.endereco.cep);
				
				encontrado=1;
			}
		}
	}
	if (encontrado==0){
	  	printf ("Nome não cadastrado\n");
	  	getch();
	}
	else{
	  	printf ("\nVoltando ao menu!");
		getch();
	}
	  
	fclose(arquivo);
}
	
void consultaTipo(){
	
	FILE *arquivo = fopen ("cadastro.dat", "rb");
	fseek(arquivo, SEEK_SET, 0);
	
	int tipoFind;
	int encontrado = 0;
	
	system ("cls");
	printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
	printf("    D A L I A   B E A C H W E A R    \n");
	printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
	printf ("Tipo [1/2]: ");
	while (getchar() != '\n');
	scanf("%d", &tipoFind);
	printf ("-------------------------------------\n");	

	while (1){
		
		fread (&cadastro, sizeof(dados), 1, arquivo);
		if (feof(arquivo)){
	  	  	break;
		}
		if (tipoFind==cadastro.tipo){
			if (cadastro.vivo==1){	
				printf("Nome: %s\n", cadastro.nome);
				printf("CPF: %lld\n", cadastro.CPF);
				if(cadastro.sexo=='m'||cadastro.sexo=='M'){
					printf("Sexo: Masculino\n");
				}
				else{
					printf("Sexo: Feminino\n");
				}
				printf("Data de Nascimento: %d/%d/%d\n",cadastro.aniv.dia,
				cadastro.aniv.mes,cadastro.aniv.ano);
				printf("Obs.: %s\n", cadastro.sobre);
				printf("Celular: %s", cadastro.celular);
				printf("\nEmail: %s", cadastro.email);
				printf("Cidade: %s",cadastro.endereco.cidade);
				printf("\nBairro: %s", cadastro.endereco.bairro);
				printf("\nRua: %s",cadastro.endereco.rua);
				printf("\nNumero: %d",cadastro.endereco.numero);
				printf("\nComplemento: %s",cadastro.endereco.complemento);
				printf("\nCep: %s",cadastro.endereco.cep);
				
				encontrado=1;
				getch();
			}
		}
	}
	if (!encontrado){
	  	printf ("Não há registros desse tipo\n");
	  	getch();
	}
	  
	fclose(arquivo);
}
 
void consultaIdade(){
 
	FILE *arquivo = fopen ("cadastro.dat", "rb");
	fseek(arquivo, SEEK_SET, 0);
	
	int idadeFind;
	int encontrado = 0;
	
	system ("cls");

	printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
	printf("    D A L I A   B E A C H W E A R    \n");
	printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
	printf("Idade: ");
	scanf("%d", &idadeFind);
	printf("-------------------------------------\n");	

	while (1){
	  	fread (&cadastro, sizeof(dados), 1, arquivo);
	  	
		if (feof(arquivo)){
	  	  	break;
		}
		if (idadeFind==(2022-cadastro.aniv.ano)){
			if (cadastro.vivo==1){
				printf("Nome: %s\n", cadastro.nome);
				printf("CPF: %lld\n", cadastro.CPF);
				if(cadastro.sexo=='m'||cadastro.sexo=='M'){
					printf("Sexo: M asculino\n");
				}
				else{
					printf("Sexo: Feminino\n");
				}
				printf("Data de Nascimento: %d/%d/%d\n",cadastro.aniv.dia,
				cadastro.aniv.mes,cadastro.aniv.ano);
				if(cadastro.tipo==1){
					printf("Tipo: %d - (Bom comprador)\n", cadastro.tipo);
				}
				else{
					printf("Tipo: %d - (Mal comprador)\n", cadastro.tipo);
				}
				printf("Obs.: %s\n", cadastro.sobre);
				printf("Celular: %s", cadastro.celular);
				printf("\nEmail: %s", cadastro.email);
				printf("Cidade: %s",cadastro.endereco.cidade);
				printf("\nBairro: %s", cadastro.endereco.bairro);
				printf("\nRua: %s",cadastro.endereco.rua);
				printf("\nNumero: %d",cadastro.endereco.numero);
				printf("\nComplemento: %s",cadastro.endereco.complemento);
				printf("\nCep: %s",cadastro.endereco.cep);
		
				encontrado=1;
				getch();		
			}
		}
	}
	if (!encontrado){
	  	printf ("Não há clientes com essa idade\n");
	  	getch();
	}
	  
	fclose(arquivo);
}

void listar(){
	
	
	system ("cls");
	FILE *arquivo = fopen ("cadastro.dat", "rb");
	fseek(arquivo, SEEK_SET, 0);
	
	int opcao;
	printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
	printf("    D A L I A   B E A C H W E A R    \n");
	printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
	printf("(1) Nome endereço e celular; \n");
	printf("(2) Nome e Observações; \n");
	printf("(3) Nome e email. \n");
	printf("-------------------------------------\n");
	scanf ("%d", &opcao);
	system("cls");
	
	switch(opcao){
		case 1:
			while (1){	
			  	
				fread (&cadastro, sizeof(dados), 1, arquivo);
			  	
			  	if (feof(arquivo)){
				  	break;
				}
			  	if (cadastro.vivo==1){
					printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
					printf("    D A L I A   B E A C H W E A R    \n");
					printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
				  	printf("Nome: %s\n", cadastro.nome);
					printf("Celular: %s", cadastro.celular);
					printf("Cidade: %s",cadastro.endereco.cidade);
					printf("\nBairro: %s", cadastro.endereco.bairro);
					printf("\nRua: %s",cadastro.endereco.rua);
					printf("\nNumero: %d",cadastro.endereco.numero);
					printf("\nComplemento: %s",cadastro.endereco.complemento);
					printf("\nCep: %s",cadastro.endereco.cep);
					printf("\n-------------------------------------\n");
					getch();
				}
				
			}
			fclose(arquivo);
			break;
			
		case 2:
			while (1){	
				fread (&cadastro, sizeof(dados), 1, arquivo);
			  	
			  	if (feof(arquivo)){
				  	break;
				}
			  	if (cadastro.vivo==1){
					printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
					printf("    D A L I A   B E A C H W E A R    \n");
					printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
				  	printf("Nome: %s\n", cadastro.nome);
					printf("Obs.: %s", cadastro.sobre);
					printf("\n-------------------------------------\n");
					getch();
				}
			}
			fclose(arquivo);
			break;
			
		case 3:
			while (1){	
			  	
				fread (&cadastro, sizeof(dados), 1, arquivo);
			  	
			  	if (feof(arquivo)){
				  	break;
				}
			  	if (cadastro.vivo==1){
					printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
					printf("    D A L I A   B E A C H W E A R    \n");
					printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
				  	printf("Nome: %s\n", cadastro.nome);
					printf("Email: %s", cadastro.email);
					printf("\n-------------------------------------\n");
					getch();
				}
			}
			fclose(arquivo);
			break;
		
			default:
					printf ("-------------------------------------\n");
			  		printf ("Opcao invalida\ntente novamente.\n");
					getch();
					system ("cls");		
			}	
	}			

void alterar	(){
	
	FILE *arquivo = fopen ("cadastro.dat", "r+b");
	fseek(arquivo, SEEK_SET, 0);
	long long int cpfFind;
	int encontrado = 0, opcao, posicao=0, tipoi;
	
	system ("cls");
	printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
	printf("    D A L I A   B E A C H W E A R    \n");
	printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
	printf ("CPF: ");
	scanf  ("%lld", &cpfFind);
	printf ("-------------------------------------\n");	
	
	while (1){
	  	fread (&cadastro, sizeof(dados), 1, arquivo);
	  	posicao++;
	  	
		if (feof(arquivo)){
	  	  	break;
		}
		if (cpfFind==cadastro.CPF){
			if (cadastro.vivo==1){
				encontrado=1;
				
				system("cls");
				printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
				printf("    D A L I A   B E A C H W E A R    \n");
				printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
				printf("Qual dado alterar?\n");
				printf("-------------------------------------\n");	
				printf("[1] - Tipo de Cliente; \n");
			  	printf("[2] - Celular; \n");
			  	printf("[3] - Observações; \n");
			  	printf("-------------------------------------\n");
			  	scanf ("%d", &opcao);
			  	
			  	system("cls");
			  	fseek(arquivo, sizeof(dados)*(posicao - 1), SEEK_SET);
				
				switch (opcao){
					
					case 1:
						printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
						printf("    D A L I A   B E A C H W E A R    \n");
						printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
						printf("Novo tipo de cliente: ");
						scanf("%d", &tipoi);
						cadastro.tipo=tipoi;
						fwrite(&cadastro, sizeof(dados), 1, arquivo);
						printf("-------------------------------------");	
						printf("\nFeito!");
						fclose(arquivo);
						break;
						
					case 2:
						printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
						printf("    D A L I A   B E A C H W E A R    \n");
						printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");	
						printf("Novo celular: ");
						while (getchar() != '\n');
						gets(cadastro.celular);
						fwrite(&cadastro, sizeof(dados), 1, arquivo);
						printf("-------------------------------------");	
						printf("\nFeito!");
						fclose(arquivo);
						break;
						
					case 3:
						printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
						printf("    D A L I A   B E A C H W E A R    \n");
						printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
						printf("Observação: ");
						while (getchar() != '\n');
						gets(cadastro.sobre);
						fwrite(&cadastro, sizeof(dados), 1, arquivo);
						printf("-------------------------------------");	
						printf("\nFeito!");
						fclose(arquivo);
						break;
	
				  	default:
				  		printf ("\n-------------------------------------\n");
				  		printf ("Opcão invalida.\n");
						getch();
						system ("cls");	
						fclose(arquivo);	
				}  
				break;
			}
		}
	}
	  
	if (!encontrado){
	  	printf ("-------------------------------------\n");	
	  	printf ("CPF não registrado \n");
	  	printf ("Voltando ao menu.");
	  	getch();
	}
	
	fclose(arquivo);
}

void excluir	(){
	
	FILE *arquivo = fopen ("cadastro.dat", "r+b");
	fseek(arquivo, 0, SEEK_SET); 
	
	long long int cpfFind;
	int encontrado = 0;
	char ok;
	int posicao=0;
	
	system ("cls");
	printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
	printf("    D A L I A   B E A C H W E A R    \n");
	printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
	printf ("CPF: \n");
	scanf  ("%lld", &cpfFind);
	

	while(1){		
	  	
		fread (&cadastro, sizeof(dados), 1, arquivo);
	  	posicao++;
	  	
		if (feof(arquivo)){
	  	  	break;
		}
		
		if (cpfFind==cadastro.CPF){
		  	encontrado = 1;
		  	
		  	printf ("Nome: %s \n", cadastro.nome);
			printf ("-------------------------------------\n");	
			printf ("Confirmar cancelamento [S/N]? ");
			ok=getche();
		  	
			if ((ok=='s')||(ok=='S')){
				
				fseek(arquivo, sizeof(dados)*(posicao - 1), SEEK_SET);
				cadastro.vivo=0;
				fwrite (&cadastro, sizeof(dados), 1, arquivo);
				fclose(arquivo);
				printf ("\nRegistro excluido!");
				getch();
				break;
			}  
			else{
				printf ("\nVoltando ao menu.");
				getch();
				break;
			}
			
		}
	}
	  
	if (!encontrado){
	  	printf ("-------------------------------------\n");	
	  	printf ("CPF não cadastrado\n");
	  	getch();
	}

	fclose(arquivo);
	system ("cls");
	
}

void finalizar	(){
	
	system ("cls");
	printf("=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=\n");
	printf("    D A L I A   B E A C H W E A R    \n");
	printf("#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n");
	printf("FIM!!!\n");
	printf("-------------------------------------");
	getch();
	
	FILE *arquivo = fopen ("cadastro.dat", "r+b");
	FILE *Narquivo = fopen ("Ncadastro.dat", "a+b");
	while (1){
	  	fread (&cadastro, sizeof(dados), 1, arquivo);
	  	
		if (feof(arquivo)){
	  	  	break;
		}
		
		if (cadastro.vivo == 1){
		  	fwrite (&cadastro, sizeof(dados), 1, Narquivo);
		}
	}
	fclose (arquivo);
	fclose (Narquivo);
	
	remove ("cadastro.dat");
	rename ("Ncadastro.dat","cadastro.dat");
	
}

int CPFexiste(long long int CPF){
	int encontrado=0;
	
	FILE *arquivo = fopen ("cadastro.dat", "rb");
	if (arquivo == NULL)
	  {
	  	encontrado = 0;
	  	return encontrado;
	  }
	
	rewind(arquivo);
	
	int k=0;
	
	while (k==0)
	  {
	  	fread (&cadastro, sizeof(dados), 1, arquivo);
	  	
	  	if (feof(arquivo))
	  	  {
	  	  	break;
		  }
		  
		if (cadastro.CPF == CPF)
		  {
		  	encontrado = 1;
		  	k++;
		  	break;
		  }
		else
		  {
		  	encontrado = 0;
		  }
	  }
	
	fclose(arquivo);
	return encontrado;
}
