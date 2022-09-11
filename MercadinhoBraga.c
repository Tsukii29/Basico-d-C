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
	char rua[25];
	char bairro[20];
	char cidade[20];
	int  numero;
	char complemento[25];
	char cep[20];
}end;

typedef struct{
	char 	nome[25];
	long long int CPF;
	char	email[35];
	char 	sexo;
	dtNasc  aniv;
	int 	tipo;
	char 	celular[15];
	end 	endereco;
	char 	sobre[50];
	int  	vivo;
} dados;
dados cadastro;
int main(){
	
	setlocale (LC_ALL,"portuguese");
	system("color 70");

	int  menu		();
	void inserir	();
	void consultar	();
	void listar		();
	void alterar	();	
	void excluir	();
	void finalizar	();
	
	FILE *arquivo = fopen ("cadastro.dat", "rb");
	if (arquivo == NULL){
		
		printf("=====================================\n");
		printf("   M E R C A D I N H O   B R A G A   \n");
		printf("=====================================\n");
		printf("Boas Vindas à nossa conveniência :)\n");
		printf("Como é seu primeiro acesso, por favor,\ninsira seu contato! \n");
		printf("(Tecle algo para continuar) \n");
		printf("-------------------------------------");
		printf("\n#####   #####    ####    #####   #### ");
		printf("\n##  ##  ##  ##  ##  ##  ##      ##  ##");
		printf("\n#####   #####   ######  ## ###  ######");
		printf("\n##  ##  ## ##   ##  ##  ##  ##  ##  ##");
		printf("\n#####   ##  ##  ##  ##   ####   ##  ##\n");
		getch();
		system("cls");
		fclose(arquivo);
		inserir();
	}
	
	else{
		
		printf("=====================================\n");
		printf("   M E R C A D I N H O   B R A G A   \n");
		printf("=====================================\n");
		printf("Como é bom te ter de volta! \n");
		printf("Tecle algo para continuar... \n");
		printf("-------------------------------------");
		printf("\n#####   #####    ####    #####   #### ");
		printf("\n##  ##  ##  ##  ##  ##  ##      ##  ##");
		printf("\n#####   #####   ######  ## ###  ######");
		printf("\n##  ##  ## ##   ##  ##  ##  ##  ##  ##");
		printf("\n#####   ##  ##  ##  ##   ####   ##  ##\n");
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
		  		printf ("Opa, parece que esta opção é invalida :(\n");
		  		printf ("Tecle algo para tentar novamente.");
				getch();
		}
      } while (1);
	
	return 0;
}
//menu
int menu(){
	
	int opcao;
	
	printf("=====================================\n");
	printf("   M E R C A D I N H O   B R A G A  \n");
	printf("=====================================\n");
	printf("       O que deseja fazer hj? \n");
	printf("-------------------------------------\n");
	printf("[1] - Inserir cadastro; \n");
	printf("[2] - Consultar cadastro; \n");
	printf("[3] - Listar cadastros; \n");
	printf("[4] - Alterar cadastro; \n");
	printf("[5] - Excluir cadastro; \n");
	printf("[9] - Finalizar execução. \n");
	printf("-------------------------------------\n");
	scanf("%d", &opcao);
	
	return opcao;
}
//inserir
void inserir(){
	
	FILE *arquivo;
	int encontrado = 1;
	long long int CPFi;
	char sexoi;
	int tipoi;
	
	int  CPFexiste 	   (long long int CPF);
	int TesteTipo	   (int tipo, int linha);
	char TesteSexo     (char Sexo, int linha);
	void TabelaTipo    ();
	void TabelaSexo    ();
	void ApagarTabela  ();
	
	fflush(stdin);
	system ("cls");
	
	printf("=====================================\n");
	printf("   M E R C A D I N H O   B R A G A   \n");
	printf("============= cadastro ==============\n");
	printf("Digite o CPF: ");
	scanf("%lld", &CPFi);
	encontrado = CPFexiste(CPFi);
	
	while (encontrado == 1){
		system ("cls");
		printf("=====================================\n");
		printf("   M E R C A D I N H O   B R A G A   \n");
		printf("============= cadastro ==============\n");
		printf ("Parece que esse CPF já existe! \nTente outro: ");
		scanf("%lld", &CPFi);
		encontrado = 0;
		encontrado = CPFexiste(CPFi);
	}
	
	cadastro.CPF=CPFi;
	while (getchar() != '\n');
	printf("-------------------------------------\n");
	
	printf("Nome: ");
	gets(cadastro.nome);
	
	TabelaSexo();
	gotoxy(0,6);
	printf("Sexo Biológico: ");
	scanf("%c", &sexoi);
	sexoi= TesteSexo(sexoi, 6);
	ApagarTabela();
	gotoxy(0,7);
	
	printf("Quando vc nasceu? ");
	
	gotoxy(35,8);
	printf("XX");
	gotoxy(0,7);
	printf("\n- Dia: ");
	scanf("%d", &cadastro.aniv.dia);
	gotoxy(35,8);
	printf("  ");
	
	gotoxy(35,9);
	printf("XX");
	gotoxy(0,9);
	printf("- Mês: ");
	scanf("%d", &cadastro.aniv.mes);
	gotoxy(35,9);
	printf("   ");
	
	gotoxy(33,10);
	printf("XXXX");
	gotoxy(0,10);
	printf("- Ano: ");
	scanf("%4d", &cadastro.aniv.ano);
	gotoxy(33,10);
	printf("     ");
	
	TabelaTipo();
	gotoxy(0,11);
	printf("Tipo de Cliente: ");
	scanf("%d", &tipoi);
	
	tipoi=TesteTipo(tipoi, 11);
	
	ApagarTabela();
	gotoxy(0,12);
	
	while (getchar() != '\n');
	
	printf("Celular: ");
	gets(cadastro.celular);
	
	printf("Email: ");
	gets(cadastro.email);
	
	printf("E quanto ao seu endereço? ");
	
	printf("\nCidade: ");
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
	
	printf("Alguma observação?\n ");
	gets(cadastro.sobre);
	
	cadastro.tipo=tipoi;
	cadastro.sexo=sexoi;
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
//consultar e suas rotinas
void consultar	(){
	system ("cls");
	fflush(stdin);
	
	int opcao;
	
	void consultaCPF         ();
	void consultaNome        ();
	void consultaTipo        ();
	void consultaIdade	     ();
	
	printf("=====================================\n");
	printf("   M E R C A D I N H O   B R A G A   \n");
	printf("============= consulta ==============\n");
	printf("Como vc gostaria de fazer a consulta?\n");
	printf("[1] - CPF; \n");
	printf("[2] - Nome; \n");
	printf("[3] - Tipo; \n");
	printf("[4] - Idade; \n");
	printf("[0] - Cancelar.");
	printf("\n-------------------------------------\n");
	scanf ("%d", &opcao);
	printf ("%d", opcao);
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
	  	case 0: 
	  			system("cls");
			  	printf("=====================================\n");
				printf("   M E R C A D I N H O   B R A G A   \n");
				printf("============= consulta ==============\n");
				printf("Cancelando a operação... ");
			  	getch();
			  	return;
	  	
	  	default:
	  		printf ("-------------------------------------\n");
	  		printf ("Opção inválida, aperte uma tecla para sair...");
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
	printf("=====================================\n");
	printf("   M E R C A D I N H O   B R A G A   \n");
	printf("============= consulta ==============\n");
	printf ("Digite o CPF desejado: ");
	scanf  ("%lld", &cpfFind);
	printf ("-------------------------------------\n");	

	while (1){
		
	  	fread (&cadastro, sizeof(dados), 1, arquivo);
		
		if (feof(arquivo)){
	  	  	break;
		}
		
		if (cpfFind==cadastro.CPF){
			if (cadastro.vivo==1){
			
				system("cls");
				printf("=====================================\n");
				printf("   M E R C A D I N H O   B R A G A   \n");
				printf("============= consulta ==============\n");
				printf("Dados do CPF %lld: \n", cpfFind);
				printf("-------------------------------------\n");	
				printf("Nome: %s\n", cadastro.nome);
				if(cadastro.sexo=='M'){
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
				printf("--------------contatos---------------\n");
				printf("Celular: %s", cadastro.celular);
				printf("\nEmail: %s\n", cadastro.email);
				printf("--------------endereço---------------\n");
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
	  	printf ("Parece que esse CPF não esta\ncadastrado :(\n");
	  	getch();
	}
	else{
	  	printf("\n-------------------------------------");
	  	printf ("\nAperte uma tecla para voltar ao menu!");
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
	printf("=====================================\n");
	printf("   M E R C A D I N H O   B R A G A   \n");
	printf("============= consulta ==============\n");
	printf ("Digite o nome desejado: ");
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
				system("cls");
				printf("=====================================\n");
				printf("   M E R C A D I N H O   B R A G A   \n");
				printf("============= consulta ==============\n");
				printf("Dados do %s: \n", cadastro.nome);
				printf("-------------------------------------\n");	
				printf("CPF: %lld\n", cadastro.CPF);
				if(cadastro.sexo=='M'){
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
				printf("--------------contatos---------------\n");
				printf("Celular: %s", cadastro.celular);
				printf("\nEmail: %s\n", cadastro.email);
				printf("--------------endereço---------------\n");
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
	  	printf ("Parece que ngm com esse nome esta\ncadastrado :(\n");
	  	getch();
	}
	else{
	  	printf ("\nAperte uma tecla para voltar ao menu!");
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
	printf("=====================================\n");
	printf("   M E R C A D I N H O   B R A G A   \n");
	printf("============= consulta ==============\n");
	printf ("Digite o tipo desejado: ");
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
				system("cls");
				printf("=====================================\n");
				printf("   M E R C A D I N H O   B R A G A   \n");
				printf("============= consulta ==============\n");
				printf("Cadastros do Tipo %d: \n", cadastro.tipo);
				printf("-------------------------------------\n");	
				printf("Nome: %s\n", cadastro.nome);
				printf("CPF: %lld\n", cadastro.CPF);
				if(cadastro.sexo=='M'){
					printf("Sexo: M asculino\n");
				}
				else{
					printf("Sexo: Feminino\n");
				}
				printf("Data de Nascimento: %d/%d/%d\n",cadastro.aniv.dia,
				cadastro.aniv.mes,cadastro.aniv.ano);
				printf("Obs.: %s\n", cadastro.sobre);
				printf("--------------contatos---------------\n");
				printf("Celular: %s", cadastro.celular);
				printf("\nEmail: %s", cadastro.email);
				printf("\n--------------endereço---------------\n");
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
	  	printf ("Parece que não há desse tipo :(\n");
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

	printf("=====================================\n");
	printf("   M E R C A D I N H O   B R A G A   \n");
	printf("============= consulta ==============\n");
	printf("Digite a idade desejada: ");
	scanf("%d", &idadeFind);
	printf("-------------------------------------\n");	

	while (1){
	  	fread (&cadastro, sizeof(dados), 1, arquivo);
	  	
		if (feof(arquivo)){
	  	  	break;
		}
		if (idadeFind==(2022-cadastro.aniv.ano)){
			if (cadastro.vivo==1){
				system("cls");
				printf("=====================================\n");
				printf("   M E R C A D I N H O   B R A G A   \n");
				printf("============= consulta ==============\n");
				printf("Dados da idade %d: \n", (2022-cadastro.aniv.ano));
				printf("-------------------------------------\n");	
				printf("Nome: %s\n", cadastro.nome);
				printf("CPF: %lld\n", cadastro.CPF);
				if(cadastro.sexo=='M'){
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
				printf("--------------contatos---------------\n");
				printf("Celular: %s", cadastro.celular);
				printf("\nEmail: %s", cadastro.email);
				printf("\n--------------endereço---------------\n");
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
	  	printf ("Parece que não há cadastro para essa idade :(\n");
	  	getch();
	}
	  
	fclose(arquivo);
}
//listar (rotinas imbutidas)
void listar(){
	
	
	system ("cls");
	FILE *arquivo = fopen ("cadastro.dat", "rb");
	fseek(arquivo, SEEK_SET, 0);
	
	int opcao;
	printf("=====================================\n");
	printf("   M E R C A D I N H O   B R A G A   \n");
	printf("============= listagem ==============\n");
	printf("   Como deseja listar os cadastros?\n");
	printf("-------------------------------------\n");
	printf("[1] - Nome endereço e celular; \n");
	printf("[2] - Nome e Observações; \n");
	printf("[3] - Nome e email; \n");
	printf("[0] - Cancelar.\n");
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
					printf("=====================================\n");
					printf("   M E R C A D I N H O   B R A G A   \n");
					printf("============= listagem ==============\n");
				  	printf("Nome: %s\n", cadastro.nome);
					printf("--------------contatos---------------\n");
					printf("Celular: %s", cadastro.celular);
					printf("\n--------------endereço---------------\n");
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
					printf("=====================================\n");
					printf("   M E R C A D I N H O   B R A G A   \n");
					printf("============= listagem ==============\n");
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
					printf("=====================================\n");
					printf("   M E R C A D I N H O   B R A G A   \n");
					printf("============= listagem ==============\n");
				  	printf("Nome: %s\n", cadastro.nome);
					printf("--------------contatos---------------\n");
					printf("Email: %s", cadastro.email);
					printf("\n-------------------------------------\n");
					getch();
				}
			}
			fclose(arquivo);
			break;
			
			case 0: 
				system("cls");
			  	printf("=====================================\n");
				printf("   M E R C A D I N H O   B R A G A   \n");
				printf("============= listagem ==============\n");
				printf("Cancelando a operação... ");
			  	getch();
			  	fclose(arquivo);
			  	return;
		
			default:
					printf ("-------------------------------------\n");
			  		printf ("Parece que esta opcao é invalida :(\ntente novamente.\n");
					getch();
					system ("cls");		
			}	
	}			
//alterar (rotinas imbutidas)
void alterar	(){
	
	FILE *arquivo = fopen ("cadastro.dat", "r+b");
	fseek(arquivo, SEEK_SET, 0);
	int TesteTipo(int tipo, int linha);
	long long int cpfFind;
	int encontrado = 0, opcao, posicao=0, tipoi;
	
	system ("cls");
	printf("=====================================\n");
	printf("   M E R C A D I N H O   B R A G A   \n");
	printf("============= alterar ===============\n");
	printf ("Digite o CPF desejado: ");
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
				printf("=====================================\n");
				printf("   M E R C A D I N H O   B R A G A   \n");
				printf("============= alterar ===============\n");
				printf("Qual dado do %s deseja alterar?\n",cadastro.nome);
				printf("-------------------------------------\n");	
				printf("[1] - Tipo de Cliente; \n");
			  	printf("[2] - Celular; \n");
			  	printf("[3] - Observações; \n");
			  	printf("[0] - Cancelar.\n");
			  	printf("-------------------------------------\n");
			  	scanf ("%d", &opcao);
			  	
			  	system("cls");
			  	fseek(arquivo, sizeof(dados)*(posicao - 1), SEEK_SET);
				
				switch (opcao){
					
					case 1:
						printf("=====================================\n");
						printf("   M E R C A D I N H O   B R A G A   \n");
						printf("============= alterar ===============\n");
						printf("Digite o tipo de cliente: ");
						scanf("%d", &tipoi);
						tipoi=TesteTipo(tipoi,3);
						cadastro.tipo=tipoi;
						fwrite(&cadastro, sizeof(dados), 1, arquivo);
						printf("-------------------------------------");	
						printf("\nTipo alterado!");
						fclose(arquivo);
						break;
						
					case 2:
						printf("=====================================\n");
						printf("   M E R C A D I N H O   B R A G A   \n");
						printf("============= alterar ===============\n");
						printf("Digite outro celular: ");
						while (getchar() != '\n');
						gets(cadastro.celular);
						fwrite(&cadastro, sizeof(dados), 1, arquivo);
						printf("-------------------------------------");	
						printf("\nCelular alterado!");
						fclose(arquivo);
						break;
						
					case 3:
						printf("=====================================\n");
						printf("   M E R C A D I N H O   B R A G A   \n");
						printf("============= alterar ===============\n");
						printf("Digite outra observação: ");
						while (getchar() != '\n');
						gets(cadastro.sobre);
						fwrite(&cadastro, sizeof(dados), 1, arquivo);
						printf("-------------------------------------");	
						printf("\nObservações alteradas!");
						fclose(arquivo);
						break;
						
					case 0: 
				  		printf("=====================================\n");
						printf("   M E R C A D I N H O   B R A G A   \n");
						printf("============= alterar ===============\n");
						printf("Cancelando a operação... ");
				  		getch();
				  		fclose(arquivo);
				  		return;
	
				  	default:
				  		printf ("\n-------------------------------------\n");
				  		printf ("Parece que esta opcao é invalida :(\ntente novamente.\n");
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
	  	printf ("Parece que este CPF não esta no sistema \n");
	  	printf ("Voltando ao menu.");
	  	getch();
	}
	
	fclose(arquivo);
}
//exclusão lógica
void excluir	(){
	
	FILE *arquivo = fopen ("cadastro.dat", "r+b");
	fseek(arquivo, 0, SEEK_SET); 
	
	long long int cpfFind;
	int encontrado = 0;
	char ok;
	int posicao=0;
	
	system ("cls");
	printf("=====================================\n");
	printf("   M E R C A D I N H O   B R A G A   \n");
	printf("============= exclusão ==============\n");
	printf ("Digite o CPF para cancelamento: \n");
	scanf  ("%lld", &cpfFind);
	

	while(1){		
	  	
		fread (&cadastro, sizeof(dados), 1, arquivo);
	  	posicao++;
	  	
		if (feof(arquivo)){
	  	  	break;
		}
		
		if (cpfFind==cadastro.CPF){
		  	encontrado = 1;
		  	
		  	system ("cls");
		  	printf("=====================================\n");
			printf("   M E R C A D I N H O   B R A G A   \n");
			printf("============= exclusão ==============\n");
			printf ("CPF: %lld \n", cpfFind);
		  	printf ("Nome: %s \n", cadastro.nome);
			printf ("-------------------------------------\n");	
			printf ("Confirmar cancelamento [S/N]? ");
			ok=getche();
		  	
			if ((ok=='s')||(ok=='S')){
				
				fseek(arquivo, sizeof(dados)*(posicao - 1), SEEK_SET);
				cadastro.vivo=0;
				fwrite (&cadastro, sizeof(dados), 1, arquivo);
				fclose(arquivo);
				printf ("\nContato excluido com sucesso!");
				getch();
				break;
			}  
			else{
				printf ("\nVoltando ao menu!");
				getch();
				break;
			}
			
		}
	}
	  
	if (!encontrado){
	  	printf ("-------------------------------------\n");	
	  	printf ("Parece que esse CPF n esta no sistema\n");
	  	getch();
	}

	fclose(arquivo);
	system ("cls");
	
}
//Finalização do programa e exclusão física
void finalizar	(){
	
	system ("cls");
	printf("=====================================\n");
	printf("   M E R C A D I N H O   B R A G A   \n");
	printf("=============== fim! ================\n");
	printf("    Obrigado pela preferência!!!\n");
	printf("-------------------------------------");
	printf("\n#####   #####    ####    #####   #### ");
	printf("\n##  ##  ##  ##  ##  ##  ##      ##  ##");
	printf("\n#####   #####   ######  ## ###  ######");
	printf("\n##  ##  ## ##   ##  ##  ##  ##  ##  ##");
	printf("\n#####   ##  ##  ##  ##   ####   ##  ##\n");
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
//Testes
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

int TesteTipo(int tipo, int linha){	
	while (!((tipo==1)||(tipo==2)))
	  {
		gotoxy(0, linha);
		printf ("Tipo de cliente inválido... \n ");
		getch();
		gotoxy(0, linha);
		printf ("                                ");
		gotoxy(0, linha);
		printf ("Tipo de cliente: ");
		while (getchar() != '\n');
		scanf("%d", &tipo);
  	  }
  	  
  	  return tipo;
}

char TesteSexo(char sexo, int linha){
	while (!((sexo=='m')||(sexo=='M')||(sexo=='f')||(sexo=='F')))
	  {
		gotoxy(0, linha);
		printf ("Opcão de sexo inválida...\n ");
		getch();
		gotoxy(0, linha);
		printf ("                             ");
		gotoxy(0, linha);
		while (getchar() != '\n');
		printf ("Sexo biológico: ");
		scanf("%c", &sexo);
	  }
	
	if (sexo=='m')
	sexo='M';
	
	if (sexo=='f')
	sexo='F';
	
	return sexo;
}
//Tabelas
void TabelaTipo(){
	
	short x, y;
	gotoxy (40, 0);
	printf ("==================\n");
	gotoxy (40, 1);
	printf ("Tipos de cliente: \n");
	gotoxy (40, 2);
	printf ("------------------\n");
	gotoxy (40, 3);
	printf ("[1] Bom Comprador;\n");
	gotoxy (40, 4);
	printf ("[2] Mal Comprador; \n");
	gotoxy (40, 5);
	printf ("==================\n");
	
}

void TabelaSexo(){
	
	short x, y;
	gotoxy (40, 0);
	printf ("==================\n");
	gotoxy (40, 1);
	printf ("Sexo Biológico: \n");
	gotoxy (40, 2);
	printf ("------------------\n");
	gotoxy (40, 3);
	printf ("[m] Masculino;\n");
	gotoxy (40, 4);
	printf ("[f] Feminino; \n");
	gotoxy (40, 5);
	printf ("==================\n");
	
}

void ApagarTabela(){
	
	for(short i=0;i<=7;i++){
	  	gotoxy (40,i);
	  	printf ("                            ");
	}
}

void gotoxy(short x, short y){
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

