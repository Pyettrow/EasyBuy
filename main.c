#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
/*#include<iostream>*/

typedef struct Fornecedores{
	int codFornecedores;
	char nomeFornecedores[50];
	int totalCompras;
	struct Fornecedores* next;
}Fornecedores;

typedef struct Produtos{
	int codFornecedorProd;
	int codProdutos;
	char nomeProdutos[50];
	float precoUni;
	int qtdComprada;
	struct Produtos* next;
}Produtos;

//Declaração das funções
void cadastroForn();
void cadastroProd();
void listaFornecedor();
void listaProduto();
void alterarForn();
void alterarProd();


Fornecedores* headFor = NULL;
Produtos* headProd = NULL;

int main() {
	setlocale(LC_ALL,"portuguese");

	struct Fornecedores *forn;
	struct Produtos *prod;

	int esc = 0;

	printf("\t\tBem-Vindo ao EasyBuy\n\n");
	while(esc !=5 ){
		//Printando o MENU
		printf("\t\t1) Cadastros\n");
		printf("\t\t2) Alterações\n");
		printf("\t\t3) Comprar\n");
		printf("\t\t4) Visualizar listas\n");
		printf("\t\t5) Relatório\n");
		printf("\t\t6) Sair\n");
		printf("\t\t");
		scanf("%d",&esc);
		system("cls");
		switch(esc){
			case 1: //Cadastro de cliente e produto
				{
					printf("\t\tEasyBuy - Cadastros\n\n");
					printf("\t\t1) Cadastrar Fornecedor\n");
					printf("\t\t2) Cadastrar Produto\n");
					printf("\t\t");
					scanf("%d",&esc);
					if(esc == 1){
						cadastroForn();
					}else if(esc == 2){
						cadastroProd();
					}else{
						printf("Opção inválida!");
					}
					break;
				}
			case 2://Alterações de cliente e produtos
				{
					printf("\t\tEasyBuy - Alterações\n\n");
					printf("\t\t1) Alterar Fornecedor\n");
					printf("\t\t2) Alterar Produto\n");
					printf("\t\t");
					scanf("%d",&esc);
					if(esc == 1){
						alterarForn();
					}else if(esc == 2){
						alterarProd();
					}else{
						printf("Opção inválida!");
					}
					break;
				}
			case 3:
				{
					printf("\t\tEasyBuy - Compra\n\n");
					//Informações para a compra
					printf("\t\t");
					break;
				}
			case 4:
				{
					printf("\t\tEasyBuy - Listas\n\n");
					printf("\t\t1) Visualizar fornecedores\n");
					printf("\t\t2) Visualizar produtos\n\t\t");
					scanf("%d",&esc);
					if(esc == 1){
						listaFornecedor();
					}else if(esc == 2){
						listaProduto();
					}else{
						printf("Opção inválida!");
					}
					break;
				}
			case 5:
				{
					printf("\t\tEasyBuy - Relatório\n\n");
					printf("\t\t1) Fornecedores ordenados pelo Total de Compras\n");
					printf("\t\t2) Produto, ordenados pelo Preço Unitário\n");
					printf("\t\t");
					scanf("%d",&esc);
					break;
				}
			case 6:
				{
					exit(0);
					break;
				}
			default:
				{
					printf("Opção inválida!!");
					break;
				}
		}
		system("cls");
		esc = 0;
	}
}

//Função para cadastrar fornecedor
void cadastroForn(){
	static int cont = 1;
	Fornecedores* temp;
	temp = (Fornecedores*)malloc(sizeof(Fornecedores));
	printf("\t\tInforme o nome do fornecdor: ");
	getchar();
	gets(temp->nomeFornecedores);
	temp->codFornecedores = cont;
	printf("\t\tO codigo do fornecedo é: %i\n",temp->codFornecedores);
	temp->next = NULL;
	if(headFor == NULL){
		headFor = temp;
	}else{
	    Fornecedores* aux = headFor;
        while(aux->next != NULL){
            aux = aux->next;
        }
		aux->next = temp;
	}
	cont++;
	printf("\t\t");
	system("pause");
}

//Função para cadastrar produto
void cadastroProd(){
	static int cont = 1;
	Produtos *temp;
	temp = (Produtos*)malloc(sizeof(Produtos));
	temp->codProdutos = cont;
	printf("\t\tCodigo do produto é: %d\n",temp->codProdutos);
	printf("\t\tInforme o nome do produto: \n\t\t");
	getchar();
	gets(temp->nomeProdutos);
	printf("\t\tInforme o preço unitário: \n\t\t");
	scanf("%f",&temp->precoUni);
	printf("\t\tInforme o código do fornecedor desse produto: \n\t\t");
	scanf("%i",&temp->codFornecedorProd);
	temp->next = NULL;
	if(headProd == NULL){
		headProd = temp;
	}else{
		Produtos *aux = headProd;
		while(aux->next != NULL){
			aux = aux->next;
		}
		aux->next = temp;
	}
	cont++;
	printf("\t\t");
	system("pause");
}

//Função para visualizar fornecedor
void listaFornecedor(){
	system("cls");
	Fornecedores* temp;
    for(temp = headFor; temp != NULL ; temp=temp->next){
        printf("\t\tCod: %d \n",temp->codFornecedores);
        printf("\t\tNome: %s \n",temp->nomeFornecedores);
        printf("\t\t---------------\n");
    }
    system("pause");
}

//Função para visualizar produtos
void listaProduto(){
	system("cls");
	Produtos* temp;
    for(temp = headProd; temp != NULL ; temp=temp->next){
        printf("\t\tCod: %d \n",temp->codProdutos);
        printf("\t\tNome: %s \n",temp->nomeProdutos);
        printf("\t\tPreço: R$%.2f \n",temp->precoUni);
        printf("\t\tCódigo do fornecedor do produto: %i \n",temp->codFornecedorProd);
        printf("\t\t---------------\n");
    }
    system("pause");
}

//Função para alterar fornecedor
void alterarForn(){
    int valor;
    system("cls");
    Fornecedores* temp;
    printf("\t\tDigite o código do fornecedor que deseja alterar: \n");
    scanf ("%d", &valor);
    for(temp = headFor; temp != NULL ; temp=temp->next){
        if(temp->codFornecedores == valor){
            system("cls");
            printf("\t\tDigite o novo nome do fornecedor: \n");
            getchar();
            gets(temp->nomeFornecedores);
            system("cls");
        }
    }
}

//Função para alterar cadastro de produto
void alterarProd(){
    int valor;
    system("cls");
    Produtos* temp;
    printf("\t\tDigite o código do produto que deseja alterar: \n\t\t");
    scanf ("%d", &valor);
    for(temp = headProd; temp != NULL ; temp=temp->next){
        if(temp->codProdutos == valor){
            system("cls");
            printf("\t\tDigite o novo nome do produto: \n\t\t");
            getchar();
            gets(temp->nomeProdutos);
            printf("\t\tInforme o novo preço unitario do produto: \n\t\t");
            scanf("%f",&temp->precoUni);
            system("cls");
        }
    }
    system("pause");
}

