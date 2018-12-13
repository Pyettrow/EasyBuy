#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

int tamListaForn = 0;
int tamListaProd = 0;

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

typedef struct vetorFornecMaior{
    char nomeFornecedoresVet[50];
    int codFornecedorVet;
    int totalComprasVet;
    int avaliadoVet;
    int inativoVet;
}vetorFornecMaior;

typedef struct vetorProdMaior{
    int codProdutosVet;
	char nomeProdutosVet[50];
	float qtdCompradaVet;
    int avaliadoVet;
    int inativoVet;
}vetorProdMaior;

Fornecedores* headFor = NULL;
Produtos* headProd = NULL;

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

//Funções Ativar/Inativar
void ativaFornec();
void inativaFornec();
void ativaProd();
void inativaProd();

//Funções para compras
void compra();
void visuProdFornec(int escFor, int escProd, int escQtde, int func);//Func = 1 para visualizar| Func = 0 para somar quantidade comprada
int  somaTotalCompra(int escFor);
int  somaQuantidadeComprada(int escFor, int escProd, int escQtde);

//Funções Ordena
//void Quick(vetorFornecMaior *vetor[tamListaForn], int inicio, int fim);
void ordenaFurnecedor();
void ordenaPrduto();


int main() {
	setlocale(LC_ALL,"portuguese");

	struct Fornecedores *forn;
	int tamListaForn = 0;
	struct Produtos *prod;

	int esc = 0;

	while(esc != 7){
        //Printando o MENU
        printf("\t\t|---------------------------|\n");
        printf("\t\t|   Bem-Vindo ao EasyBuy    |\n");
        printf("\t\t|---------------------------|\n");
		printf("\t\t| 1) Cadastros.             |\n");
		printf("\t\t| 2) Alterações.            |\n");
		printf("\t\t| 3) Inativações.           |\n");
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
						system("pause");
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
						system("pause");
					}
					break;
				}
            case 3://Inativação de Produto e Cliente
                {
                    printf("\t\t|---------------------------------|\n");
                    printf("\t\t|    EasyBuy - Ativar/Inativar    |\n");
                    printf("\t\t|---------------------------------|\n");
					printf("\t\t| 1) Ativar/Inativar Fornecedor.  |\n");
					printf("\t\t| 2) Ativar/Inativar Produto.     |\n");
					printf("\t\t|---------------------------------|\n\n");
					printf("\t\t");
					scanf("%d",&esc);
					system("cls");
					if(esc == 1){
					    printf("\t\t|---------------------------------|\n");
                        printf("\t\t|    EasyBuy - Ativar/Inativar    |\n");
                        printf("\t\t|---------------------------------|\n");
                        printf("\t\t| 1) Ativar Fornecedor.           |\n");
                        printf("\t\t| 2) Inativar Fornecedor.         |\n");
                        printf("\t\t|---------------------------------|\n\n");
                        printf("\t\t");
                        scanf("%d",&esc);
                        if(esc == 1){
                            ativaFornec();
                        }else if(esc ==2){
                            inativaFornec();
                        }else{
                            printf("\t\tOpção inválida!");
                            system("pause");
                        }
					}else if(esc == 2){
						printf("\t\t|---------------------------------|\n");
                        printf("\t\t|    EasyBuy - Ativa/Inativar     |\n");
                        printf("\t\t|---------------------------------|\n");
                        printf("\t\t| 1) Ativa Fornecedor.            |\n");
                        printf("\t\t| 2) Inativar Fornecedor.         |\n");
                        printf("\t\t|---------------------------------|\n\n");
                        printf("\t\t");
                        scanf("%d",&esc);
                        if(esc == 1){
                            void ativaProd();
                        }else if(esc ==2){
                            inativaProd();
                        }else{
                            printf("\t\tOpção inválida!");
                            system("pause");
                        }
					}else{
						printf("Opção inválida!");
						system("pause");
					}
                    break;
                }
			case 4://Comprar produto
				{
					printf("\t\t|-------------------------------|\n");
                    printf("\t\t|       EasyBuy - Compra        |\n");
                    printf("\t\t|-------------------------------|\n");
					if(headFor == NULL){
                        printf("\n\t\tÉ necessário ter um foncedor cadastrado!\n\t\t");
                        system("pause");
					}else{
                        compra();
					}
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
						system("pause");
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
					if(esc == 1)
                    {
                        ordenaFurnecedor();
                        system("pause");
                        system("cls");
                    }
                    else if(esc == 2)
                    {
                        ordenaPrduto();
                        system("pause");
                        system("cls");
                    }break;
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

					printf("Opção inválida, informe o número certo!!");
					system("pause");
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
     int naoEx ;
     int tamanhoLista;
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

                    naoEx ++;
                }

                tamanhoLista++;

        } if(naoEx == tamanhoLista){
            printf("\t\tProduto inexistente!\n\t\tDigite um produto ja cadastrado:");
            scanf ("%d", &valor);
        }
    }
    system("pause");
}

//Ativar Fornecedor
ativaFornec(){
    Fornecedores *temp;
    int saida = 0, esc = 0;
    int tamLista = 0, cont = 0;
    printf("\t\tCódigo do fornecedor: ");
    scanf("%d",&esc);
    esc = verificaFornce(esc);
    while(saida != 1){
        for(temp = headFor; temp != NULL ; temp=temp->next){
            if(esc == temp->codFornecedores){
                temp->inativo = 0;
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
    printf("\t\tFornecedor ativado!\n\t\t");
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
    printf("\t\tFornecedor inativado!\n\t\t");
    system("pause");
}
//Ativar Produto
void ativaProd(){
    Produtos *temp;
    int saida = 0, esc = 0;
    int tamLista = 0, cont = 0;
    printf("\t\tCódigo do produto: ");
    scanf("%d",&esc);
    esc = verificaProd(esc);
    while(saida != 1){
        for(temp = headProd; temp != NULL ; temp=temp->next){
            if(esc == temp->codProdutos){
                temp->inativo = 0;
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
    printf("\t\tProduto ativado!\n");
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
    int escFor = 0, escProd = 0, cont = 0;;
    float escQtde = 0;
    printf("\t\t  Informe o codigo do fornecedor\n\t\t  para realizar a compra:\n");
    printf("\t\t");
    scanf("%d",&escFor);
    escFor = somaTotalCompra(escFor);
    if(escFor == 0){
        printf("\n\t\tFornecedor não possui itens ou não esta cadastrado.\n\t\t");
    }else if(escFor == -1){
    //Não faz nada
    }else{
        visuProdFornec(escFor, escProd, escQtde, 0);
        printf("\n\t\tInforme o codigo do produto que deseja comprar: ");
        scanf("%d",&escProd);
        printf("\t\tQtde: ");
        scanf("%f",&escQtde);
        escProd = somaQuantidadeComprada(escFor, escProd, escQtde);
        printf("\n\t\tCompra realizada com sucesso!\n\t\t");
    }
    printf("\n\t\t");
    system("pause");
}

//Função para somar total compra do fornecedor
int somaTotalCompra(int escFor){
    Fornecedores* temp;
    Produtos* tempProd;
    int totalComp = 0, cont = 0;
    int saida = 0;
    int aux = 0, tamLista = 0;
    while(saida != 1){
        for(temp = headFor; temp != NULL ; temp=temp->next){
            if((temp->codFornecedores == escFor) && (temp->inativo == 0)){
                for(tempProd = headProd ; tempProd != NULL ; tempProd=tempProd->next){
                    if(tempProd->codFornecedorProd == escFor){
                        cont++;
                    }
                }
                if(cont > 0){
                    totalComp = temp->totalCompras;
                    totalComp++;
                    temp->totalCompras = totalComp;
                    saida = 1;
                }else{
                    return 0;
                }
            }else{
                aux++;
            }
            tamLista++;
        }
        if(aux == tamLista){
            printf("\n\t\tO forneceodr não esta cadastrado!\n\t\tInforme um novmanete ou 0 para sair: ");
            scanf("%d", &escFor);
            if(escFor == 0){
                return -1;
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
    printf("\n\n\t\tProdutos cfe fornecedor:\n");
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

//Ordena Froncedores por total de compras
void ordenaFurnecedor(){
    int maior = 0, contFor = 0, x = 0, y = 0, maiorAux = 0, ajudaNaImpressoa = 0;
    int inicio = 0;
    Fornecedores *forn;


    for(forn = headFor ; forn != NULL ; forn=forn->next){
        if(forn->inativo == 0){
            tamListaForn++;
        }
    }

    vetorFornecMaior vetor[tamListaForn];

    for(forn = headFor ; forn != NULL ; forn=forn->next){
        vetor[contFor].codFornecedorVet = forn->codFornecedores;
        vetor[contFor].totalComprasVet = forn->totalCompras;
        strcpy(vetor[contFor].nomeFornecedoresVet, forn->nomeFornecedores);
        vetor[contFor].inativoVet = forn->inativo;
        vetor[contFor].avaliadoVet = 0;
        if(forn->totalCompras >= maior && forn->inativo == 0){
            maior = forn->totalCompras;
            inicio = contFor;
        }
        contFor++;
    }

    vetor[inicio].avaliadoVet = 3;

    printf("\n\t\tOrdem dos fornecedores:\n");
    while(y < tamListaForn){
        if(vetor[inicio].avaliadoVet == 3){
            printf("\n\t\tCod: %i\n",vetor[inicio].codFornecedorVet);
            printf("\t\tNome Fornecedor: %s\n",vetor[inicio].nomeFornecedoresVet);
            printf("\t\tTotal vendas: %i\n",vetor[inicio].totalComprasVet);
            printf("\t\t---------------------\n");
            vetor[inicio].avaliadoVet = 1;
            y++;
        }else{
            for(int z = 0 ; z < tamListaForn ; z++){
                if((vetor[z].totalComprasVet < maior) && (vetor[z].totalComprasVet >= maiorAux) && ((vetor[z].avaliadoVet == 0) && (vetor[z].inativoVet == 0))){
                        ajudaNaImpressoa = z;
                        maiorAux = vetor[z].totalComprasVet;
                }
            }
            maiorAux = 0;
            printf("\n\t\tCod: %i\n",vetor[ajudaNaImpressoa].codFornecedorVet);
            printf("\t\tNome Fornecedor: %s\n",vetor[ajudaNaImpressoa].nomeFornecedoresVet);
            printf("\t\tTotal vendas: %i\n",vetor[ajudaNaImpressoa].totalComprasVet);
            printf("\t\t---------------------\n");
            vetor[ajudaNaImpressoa].avaliadoVet = 1;
            y++;
        }
    }
}

//Ordena produto conforme a quantidade de compra
void ordenaPrduto(){
    int contProd = 0, x = 0, y = 0, ajudaNaImpressoa = 0;
    float maior = 0, maiorAux = 0;
    int inicio = 0;
    Produtos *prod;


    for(prod= headProd; prod!= NULL ; prod=prod->next){
        if(prod->inativo== 0){
            tamListaProd++;
        }
    }

    vetorProdMaior vetorProd[tamListaProd];

    for(prod= headProd; prod!= NULL ; prod=prod->next){
        vetorProd[contProd].codProdutosVet = prod->codFornecedorProd;
        vetorProd[contProd].qtdCompradaVet = prod->qtdComprada;
        strcpy(vetorProd[contProd].nomeProdutosVet, prod->nomeProdutos);
        vetorProd[contProd].inativoVet= prod->inativo;
        vetorProd[contProd].avaliadoVet= 0;
        if(prod->qtdComprada >= maior && prod->inativo == 0){
            maior = prod->qtdComprada;
            inicio = contProd;
        }
        contProd++;
    }

    vetorProd[inicio].avaliadoVet = 3;

    printf("\n\t\tOrdem dos fornecedores:\n");
    while(y < tamListaProd){
        if(vetorProd[inicio].avaliadoVet == 3){
            printf("\n\t\tCod: %i\n",vetorProd[inicio].codProdutosVet);
            printf("\t\tNome Produto: %s\n",vetorProd[inicio].nomeProdutosVet);
            printf("\t\tTotal compras: %.2f\n",vetorProd[inicio].qtdCompradaVet);
            printf("\t\t---------------------\n");
            vetorProd[inicio].avaliadoVet = 1;
            y++;
        }else{
            printf("\nentrei no else\n");
            for(int z = 0 ; z < tamListaForn ; z++){
                if((vetorProd[z].qtdCompradaVet < maior) && (vetorProd[z].qtdCompradaVet >= maiorAux) && ((vetorProd[z].avaliadoVet == 0) && (vetorProd[z].inativoVet == 0))){
                        ajudaNaImpressoa = z;
                        maiorAux = vetorProd[z].qtdCompradaVet;
                }
            }
            maiorAux = 0;
            printf("\n\t\tCod: %i\n",vetorProd[ajudaNaImpressoa].codProdutosVet);
            printf("\t\tNome Produto: %s\n",vetorProd[ajudaNaImpressoa].nomeProdutosVet);
            printf("\t\tTotal compras: %.2f\n",vetorProd[ajudaNaImpressoa].qtdCompradaVet);
            printf("\t\t---------------------\n");
            vetorProd[ajudaNaImpressoa].avaliadoVet = 1;
            y++;
        }
    }
}

//-----Consultas-----
//Procurar se fornecedor existe
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




