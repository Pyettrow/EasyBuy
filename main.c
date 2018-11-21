#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

//Declara��o de Struct
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
	float qtdComprada;
	struct Produtos* next;
}Produtos;

//Declara��o das fun��es
//Fun��es para cadastro
void cadastroForn();
void cadastroProd();
void listaFornecedor();
void listaProduto();
void alterarForn();
void alterarProd();

//Fun��es para compras
void compra();
void visuProdFornec(int escFor, int escProd, int escQtde, int func);//Func = 1 para visualizar| Func = 0 para somar quantidade comprada
int  somaTotalCompra(int escFor);
int  somaQuantidadeComprada(int escFor, int escProd, int escQtde);


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
		printf("\t\t2) Altera��es\n");
		printf("\t\t3) Comprar\n");
		printf("\t\t4) Visualizar listas\n");
		printf("\t\t5) Relat�rio\n");
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
						printf("Op��o inv�lida!");
					}
					break;
				}
			case 2://Alterar de cliente e produtos
				{
					printf("\t\tEasyBuy - Altera��es\n\n");
					printf("\t\t1) Alterar Fornecedor\n");
					printf("\t\t2) Alterar Produto\n");
					printf("\t\t");
					scanf("%d",&esc);
					if(esc == 1){
						alterarForn();
					}else if(esc == 2){
						alterarProd();
					}else{
						printf("Op��o inv�lida!");
					}
					break;
				}
			case 3://Comprar produto
				{
					printf("\t\tEasyBuy - Compra\n\n");
					compra();
					printf("\t\t");
					break;
				}
			case 4://Visualizar produto e fornecedor
				{
					printf("\t\tEasyBuy - Listas\n\n");
					printf("\t\t1) Visualizar fornecedores\n");
					printf("\t\t2) Visualizar produtos\n\t\t");
					scanf("%d",&esc);
					if(esc == 1){
						listaFornecedor();
					}else if(esc == 2){
					    system("cls");
						listaProduto();
						system("pause");
					}else{
						printf("Op��o inv�lida!");
					}
					break;
				}
			case 5:
				{
					printf("\t\tEasyBuy - Relat�rio\n\n");
					printf("\t\t1) Fornecedores ordenados pelo Total de Compras\n");
					printf("\t\t2) Produto, ordenados pelo Pre�o Unit�rio\n");
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
					printf("Op��o inv�lida!!");
					break;
				}
		}
		system("cls");
		esc = 0;
	}
}

//Fun��o para cadastrar fornecedor
void cadastroForn(){
	static int cont = 1;
	Fornecedores* temp;
	temp = (Fornecedores*)malloc(sizeof(Fornecedores));
	printf("\t\tInforme o nome do fornecdor: ");
	getchar();
	gets(temp->nomeFornecedores);
	temp->codFornecedores = cont;
	printf("\t\tO codigo do fornecedo �: %d\n",temp->codFornecedores);
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

//Fun��o para cadastrar produto
void cadastroProd(){
	static int cont = 1;
	Produtos *temp;
	temp = (Produtos*)malloc(sizeof(Produtos));
	temp->codProdutos = cont;
	printf("\t\tCodigo do produto �: %d\n",temp->codProdutos);
	printf("\t\tInforme o nome do produto: \n\t\t");
	getchar();
	gets(temp->nomeProdutos);
	printf("\t\tInforme o pre�o unit�rio: \n\t\t");
	scanf("%f",&temp->precoUni);
	printf("\t\tInforme o c�digo do fornecedor desse produto: \n\t\t");
	scanf("%d",&temp->codFornecedorProd);
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

//Fun��o para visualizar fornecedor
void listaFornecedor(){
	system("cls");
	Fornecedores* temp;
    for(temp = headFor; temp != NULL ; temp=temp->next){
        printf("\t\tCod: %d \n",temp->codFornecedores);
        printf("\t\tNome: %s \n",temp->nomeFornecedores);
        printf("\t\tQtde de compras: %d\n",temp->totalCompras);
        printf("\t\t---------------\n");
    }
    system("pause");
}

//Fun��o para visualizar produtos
void listaProduto(){
	Produtos* temp;
    for(temp = headProd; temp != NULL ; temp=temp->next){
        printf("\t\t-----------------------\n");
        printf("\t\tCod: %d \n",temp->codProdutos);
        printf("\t\tNome: %s \n",temp->nomeProdutos);
        printf("\t\tPre�o: R$%.2f \n",temp->precoUni);
        printf("\t\tQtde comprada: %d \n",temp->qtdComprada);
        printf("\t\tCod. do fornecedor: %d \n",temp->codFornecedorProd);
        printf("\t\t-----------------------\n");
    }
}

//Fun��o para alterar fornecedor
void alterarForn(){
    int valor;
    system("cls");
    Fornecedores* temp;
    printf("\t\tDigite o c�digo do fornecedor que deseja alterar: \n");
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

//Fun��o para alterar cadastro de produto
void alterarProd(){
    int valor;
    system("cls");
    Produtos* temp;
    printf("\t\tDigite o c�digo do produto que deseja alterar: \n\t\t");
    scanf ("%d", &valor);
    for(temp = headProd; temp != NULL ; temp=temp->next){
        if(temp->codProdutos == valor){
            system("cls");
            printf("\t\tDigite o novo nome do produto: \n\t\t");
            getchar();
            gets(temp->nomeProdutos);
            printf("\t\tInforme o novo pre�o unitario do produto: \n\t\t");
            scanf("%f",&temp->precoUni);
            system("cls");
        }
    }
    system("pause");
}

//Fun��o para compra
void compra(){
    Fornecedores *tempFornec;
    Produtos *tempProd;
    int totalComp = tempFornec->totalCompras;
    int escFor = 0, escProd = 0;
    float escQtde = 0;
    printf("\n\t\tInforme o codigo do fornecedor\n\t\tpara realizar a compra: ");
    scanf("%d",&escFor);
    escFor = somaTotalCompra(escFor);
    visuProdFornec(escFor, escProd, escQtde, 0);
    printf("\t\tInforme o codigo do produto que deseja comprar: ");
    scanf("%d",&escProd);
    printf("\t\tQtde: ");
    scanf("%f",&escQtde);
    escProd = somaQuantidadeComprada(escFor, escProd, escQtde);
    printf("\n\t\tCompra realizada com sucesso!\n\t\t");
    system("pause");
}

//Fun��o para somar total compra do fornecedor
int somaTotalCompra(int escFor){
    Fornecedores* temp;
    int saida = 0;
    while(saida != 1){
        for(temp = headFor; temp != NULL ; temp=temp->next){
            if(temp->codFornecedores == escFor){
                temp->totalCompras = temp->totalCompras + 1;
                saida = 1;
            }else{
                printf("\n\t\tFornecedor inexistente\n\t\tInforme um fonecedor v�lido: \n\t\t");
                scanf("%d",&escFor);
            }
        }
    }
    return escFor;
}

//Fun��o para somar quanitdade de compra e validar produto
int  somaQuantidadeComprada(int escFor, int escProd, int escQtde){
    Produtos *temp;
    int aux = 0, tamLista = 0, naoEx = 0, saida = 0;
    while(saida != 1){
        for(temp = headProd; temp != NULL ; temp=temp->next){
            if((escFor == temp->codFornecedorProd) && (escProd == temp->codProdutos)){
                aux = temp->qtdComprada;
                aux = aux + escQtde;
                temp->qtdComprada = aux;
                saida = 1;
            }else{
                naoEx++;
            }
        tamLista++;
        }
        if(naoEx == tamLista){
            printf("Produto inexistente!\n\t\tInforme um produto v�lido: ");
            scanf("%d",&escProd);
        }
    }
    return escProd;
}

//Visualiza produto conforme fonecedor
void visuProdFornec(int escFor, int escProd, int escQtde, int func){
    Produtos* temp;
    for(temp = headProd; temp != NULL ; temp=temp->next){
        if(escFor == temp->codFornecedorProd){
            printf("\t\t-----------------------\n");
            printf("\t\tCod: %d \n",temp->codProdutos);
            printf("\t\tNome: %s \n",temp->nomeProdutos);
            printf("\t\tPre�o: R$%.2f \n",temp->precoUni);
            printf("\t\tCod. do fornecedor: %d \n",temp->codFornecedorProd);
            printf("\t\t-----------------------\n");
        }
    }
}












