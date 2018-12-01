#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

//Usar metodo QuickShort para fazer relatorios.

//Declaração de Struct
typedef struct Fornecedores{
	int codFornecedores;
	char nomeFornecedores[50];
	int totalCompras;
	struct Fornecedores* next;
	int inativo;
}Fornecedores;

typedef struct Produtos{
	int codFornecedorProd;
	int codProdutos;
	char nomeProdutos[50];
	float precoUni;
	float qtdComprada;
	struct Produtos* next;
	int inativo;
}Produtos;

//Declaração das funções
//Funções para cadastro
void cadastroForn();
void cadastroProd();
int verificaFornce(int escFornec);
void listaFornecedor();
void listaProduto();
void alterarForn();
void alterarProd();

//Funções de consulta
int verificaProd();

//Funções Inativar
void inativaFornec();
void inativaProd();

//Funções para compras
void compra();
void visuProdFornec(int escFor, int escProd, int escQtde, int func);//Func = 1 para visualizar| Func = 0 para somar quantidade comprada
int  somaTotalCompra(int escFor);
int  somaQuantidadeComprada(int escFor, int escProd, int escQtde);


Fornecedores* headFor = NULL;
Produtos* headProd = NULL;

int main() {
	setlocale(LC_ALL,"portuguese");

//	struct Fornecedores *forn;
//	struct Produtos *prod;

	int esc = 0;

	while(esc != 7){
        //Printando o MENU
        printf("\t\t|---------------------------|\n");
        printf("\t\t|   Bem-Vindo ao EasyBuy    |\n");
        printf("\t\t|---------------------------|\n");
		printf("\t\t| 1) Cadastros.             |\n");
		printf("\t\t| 2) Alterações.            |\n");
		printf("\t\t| 3) Inativar cadastro.     |\n");
		printf("\t\t| 4) Comprar.               |\n");
		printf("\t\t| 5) Visualizar listas.     |\n");
		printf("\t\t| 6) Relatório.             |\n");
		printf("\t\t| 7) Sair.                  |\n");
		printf("\t\t|---------------------------|\n\n");
		printf("\t\t");
		scanf("%d",&esc);
		system("cls");
		switch(esc){
			case 1: //Cadastro de cliente e produto
				{
					printf("\t\t|---------------------------|\n");
                    printf("\t\t|     EasyBuy - Cadastro    |\n");
                    printf("\t\t|---------------------------|\n");
					printf("\t\t| 1) Cadastrar Fornecedor.  |\n");
					printf("\t\t| 2) Cadastrar Produto.     |\n");
					printf("\t\t|---------------------------|\n\n");
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
			case 2://Alterar de cliente e produtos
				{
					printf("\t\t|---------------------------|\n");
                    printf("\t\t|   EasyBuy - Alterações    |\n");
                    printf("\t\t|---------------------------|\n");
					printf("\t\t| 1) Alterar Fornecedor.    |\n");
					printf("\t\t| 2) Alterar Produto.       |\n");
					printf("\t\t|---------------------------|\n\n");
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
            case 3://Inativação de Produto e Cliente
                {
                    printf("\t\t|---------------------------|\n");
                    printf("\t\t|   EasyBuy - Inativação    |\n");
                    printf("\t\t|---------------------------|\n");
					printf("\t\t| 1) Inativar Fornecedor.   |\n");
					printf("\t\t| 2) Inativar Produto.      |\n");
					printf("\t\t|---------------------------|\n\n");
					printf("\t\t");
					scanf("%d",&esc);
					if(esc == 1){
						inativaFornec();
					}else if(esc == 2){
						inativaProd();
					}else{
						printf("Opção inválida!");
					}
                    break;
                }
			case 4://Comprar produto
				{
					printf("\t\t|-------------------------------|\n");
                    printf("\t\t|       EasyBuy - Compra        |\n");
                    printf("\t\t|-------------------------------|\n");
					compra();
					printf("\t\t");
					break;
				}
			case 5://Visualizar produto e fornecedor
				{
					printf("\t\t|-------------------------------|\n");
                    printf("\t\t|       EasyBuy - Listas        |\n");
                    printf("\t\t|-------------------------------|\n");
					printf("\t\t| 1) Visualizar fornecedores.   |\n");
					printf("\t\t| 2) Visualizar produtos.       |\n");
					printf("\t\t|-------------------------------|\n");
					printf("\t\t");
					scanf("%d",&esc);
					if(esc == 1){
						listaFornecedor();
					}else if(esc == 2){
					    system("cls");
						listaProduto();
						system("pause");
					}else{
						printf("Opção inválida!");
					}
					break;
				}
			case 6:
				{
					printf("\t\t|---------------------------------|\n");
                    printf("\t\t|       EasyBuy - Relatórios      |\n");
                    printf("\t\t|---------------------------------|\n");
					printf("\t\t| 1) Fornecedores ordenados pelo  |\n\t\t|     Total de Compras.           |\n");
					printf("\t\t| 2) Produto, ordenados pelo      |\n\t\t|     Preço Unitário.             |\n");
					printf("\t\t|---------------------------------|\n");
					printf("\t\t");
					scanf("%d",&esc);
					break;
					if(esc == 1)
                    {
                        system("cls");

                    }
				}
			case 7:
				{
					printf("\n\n\t\tObrigado por utilizar o sistema EasyBuy!\n\n\t\t\t\t^-^\n\n");
					system("pause");
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
	printf("\t\tO codigo do fornecedo é: %d\n",temp->codFornecedores);
	temp->totalCompras = 0;
	temp->inativo = 0;
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
	int escFornec = 0;
	Produtos *temp;
	temp = (Produtos*)malloc(sizeof(Produtos));
	temp->codProdutos = cont;
	printf("\t\tInforme o nome do produto: \n\t\t");
	getchar();
	gets(temp->nomeProdutos);
	printf("\t\tInforme o preço unitário: \n\t\t");
	scanf("%f",&temp->precoUni);
	if(headFor == NULL){
        printf("\t\tNenhum fornecedor cadastrado\n\t\tNecessario fazer cadastro.\n\n\t\tApós o cadastro informar o código do fornecedor.\n\t\t");
        system("pause");
        system("cls");
        printf("\t\t|--------------------------------------|\n");
        printf("\t\t|     EasyBuy - Cadastro Fornecedor    |\n");
        printf("\t\t|--------------------------------------|\n");
        cadastroForn();
        system("cls");
        printf("\t\t|--------------------------------|\n");
        printf("\t\t|   EasyBuy - Cadastro Produto   |\n");
        printf("\t\t|--------------------------------|\n");
	}
	printf("\n\t\tInforme o codigo do fornecedor: ");
    scanf("%d",&escFornec);
	escFornec = verificaFornce(escFornec);
	temp->codFornecedorProd = verificaFornce(escFornec);
	temp->next = NULL;
	temp->inativo = 0;
	if(headProd == NULL){
		headProd = temp;
	}else{
		Produtos *aux = headProd;
		while(aux->next != NULL){
			aux = aux->next;
		}
		aux->next = temp;
	}
	printf("\t\tCodigo do produto é: %d\n",temp->codProdutos);
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
        if(temp->inativo == 0){
            printf("\t\tSituaçaõ: Ativo \n");
        }else{
            printf("\t\tSituaçaõ: Inativo \n");
        }
        printf("\t\tQtde de compras: %d\n",temp->totalCompras);
        printf("\t\t---------------\n");
    }
    system("pause");
}

//Função para visualizar produtos
void listaProduto(){
	Produtos* temp;
    for(temp = headProd; temp != NULL ; temp=temp->next){
        printf("\t\t-----------------------\n");
        printf("\t\tCod: %d \n",temp->codProdutos);
        printf("\t\tNome: %s \n",temp->nomeProdutos);
        printf("\t\tPreço: R$%.2f \n",temp->precoUni);
        printf("\t\tQtde comprada: %.2f \n",temp->qtdComprada);
        if(temp->inativo == 0){
            printf("\t\tSituaçaõ: Ativo \n");
        }else{
            printf("\t\tSituaçaõ: Inativo \n");
        }
        printf("\t\tCod. do fornecedor: %d \n",temp->codFornecedorProd);
        printf("\t\t-----------------------\n");
    }
}

//Função para alterar fornecedor
void alterarForn(){
    int valor,saida = 0;
    system("cls");
    Fornecedores* temp;
    printf("\t\tDigite o código do fornecedor que deseja alterar: \n");
    scanf ("%d", &valor);
    while(saida != 1){
        for(temp = headFor; temp != NULL ; temp=temp->next){
            if(temp->codFornecedores == valor){
                system("cls");
                printf("\t\tDigite o novo nome do fornecedor: \n");
                getchar();
                gets(temp->nomeFornecedores);
                saida = 1;
                system("cls");

            }
            else
            {
                printf("\t\tFornecedor inexistente!\n\t\tDigite um fornecedor ja cadastrado:");
                scanf ("%d", &valor);
            }

        }
    }
}

//Função para alterar cadastro de produto
void alterarProd(){
    int valor, saida = 0;
    system("cls");
    Produtos* temp;
    printf("\t\tDigite o código do produto que deseja alterar: \n\t\t");
    scanf ("%d", &valor);
    while(saida != 1){
        for(temp = headProd; temp != NULL ; temp=temp->next){
            if(temp->codProdutos == valor){
                system("cls");
                printf("\t\tDigite o novo nome do produto: \n\t\t");
                getchar();
                gets(temp->nomeProdutos);
                printf("\t\tInforme o novo preço unitario do produto: \n\t\t");
                scanf("%f",&temp->precoUni);
                saida = 1;
                system("cls");
            }
            else
                {
                    printf("\t\tProduto inexistente!\n\t\tDigite um produto ja cadastrado:");
                    scanf ("%d", &valor);
                }
        }
    }
    system("pause");
}

//Inativar Fornecedor
void inativaFornec(){
    Fornecedores *temp;
    int saida = 0, esc = 0;
    int tamLista = 0, cont = 0;
    printf("\t\tCódigo do fornecedor: ");
    scanf("%d",&esc);
    esc = verificaFornce(esc);
    while(saida != 1){
        for(temp = headFor; temp != NULL ; temp=temp->next){
            if(esc == temp->codFornecedores){
                temp->inativo = 1;
                saida = 1;
            }else{
                cont++;
            }
            tamLista++;
        }
        if(tamLista == cont){
            printf("\t\tNenhum fornecedor encotrado\n\t\tInforme outro codigo: ");
            scanf("%d",&esc);
        }
    }
    printf("\t\tFornecedor inativado\n!");
    system("pause");
}

//Inativar Produto
void inativaProd(){
    Produtos *temp;
    int saida = 0, esc = 0;
    int tamLista = 0, cont = 0;
    printf("\t\tCódigo do produto: ");
    scanf("%d",&esc);
    esc = verificaProd(esc);
    while(saida != 1){
        for(temp = headProd; temp != NULL ; temp=temp->next){
            if(esc == temp->codProdutos){
                temp->inativo = 1;
                saida = 1;
            }else{
                cont++;
            }
            tamLista++;
        }
        if(tamLista == cont){
            printf("\t\tNenhum produto encotrado\n\t\tInforme outro codigo: ");
            scanf("%d",&esc);
        }
    }
    printf("\t\tProduto inativado!\n");
    system("pause");
}

//Função para compra
void compra(){
    Fornecedores *tempFornec;
    Produtos *tempProd;
    int escFor = 0, escProd = 0;
    float escQtde = 0;
    printf("\t\t  Informe o codigo do fornecedor\n\t\t  para realizar a compra:\n");
    printf("\t\t");
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

//Função para somar total compra do fornecedor
int somaTotalCompra(int escFor){
    Fornecedores* temp;
    int totalComp = 0;
    int saida = 0;
    while(saida != 1){
        for(temp = headFor; temp != NULL ; temp=temp->next){
            if(temp->codFornecedores == escFor){
                totalComp = temp->totalCompras;
                totalComp++;
                temp->totalCompras = totalComp;
                saida = 1;
            }else{
                printf("\n\t\tFornecedor inexistente\n\t\tInforme um fonecedor válido: \n\t\t");
                scanf("%d",&escFor);
            }
        }
    }
    return escFor;
}

//Função para somar quanitdade de compra e validar produto
int  somaQuantidadeComprada(int escFor, int escProd, int escQtde){
    Produtos *temp;
    int tamLista = 0, naoEx = 0, saida = 0;
    float aux = 0;
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
            printf("\t\tProduto inexistente!\n\t\tInforme um produto válido: ");
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
            printf("\t\tPreço: R$%.2f \n",temp->precoUni);
            printf("\t\tCod. do fornecedor: %d \n",temp->codFornecedorProd);
            printf("\t\t-----------------------\n");
        }
    }
}


//-----Consultas-----
//Procurar se fornecedor existe ---- ARRUMAR ---
int verificaFornce(int escFornec){
    Fornecedores *temp;
    int saida = 0;
    int cont = 0, tamLista = 0;
    while(saida != 1){
        for(temp = headFor; temp != NULL ; temp=temp->next){
            if(escFornec == temp->codFornecedores){
                saida = 1;
            }else{
                cont++;
            }
            tamLista++;
        }
        if(tamLista == cont){
            printf("\t\tFornecedor não cadastrado\n\t\tInforme um fornecedor existente: ");
            scanf("%d",&escFornec);
        }
    }
    return escFornec;
}

//Produra se produto existe
int verificaProd(int escProd){
   Produtos *temp;
    int saida = 0;
    int cont = 0, tamLista = 0;
    while(saida != 1){
        for(temp = headProd; temp != NULL ; temp=temp->next){
            if(escProd == temp->codProdutos){
                saida = 1;
            }else{
                cont++;
            }
            tamLista++;
        }
        if(tamLista == cont){
            printf("\t\tProduto não cadastrado\n\t\tInforme um produto existente: ");
            scanf("%d",&escProd);
        }
    }
    return escProd;
}




