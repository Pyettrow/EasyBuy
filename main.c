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
int verificaFornce(int escFornec);
void listaFornecedor();
void listaProduto();
void alterarForn();
void alterarProd();

//Fun��es para compras
void compra();
void visuProdFornec(int escFor, int escProd, int escQtde, int func);//Func = 1 para visualizar| Func = 0 para somar quantidade comprada
int  somaTotalCompra(int escFor);
int  somaQuantidadeComprada(int escFor, int escProd, int escQtde);

//Fun��es Ordena
int organizaFornec();

Fornecedores* headFor = NULL;
Produtos* headProd = NULL;

int main() {
	setlocale(LC_ALL,"portuguese");

	struct Fornecedores *forn;
	struct Produtos *prod;

	int esc = 0;

	while(esc !=5 ){
        //Printando o MENU
        printf("\t\t|---------------------------|\n");
        printf("\t\t|   Bem-Vindo ao EasyBuy    |\n");
        printf("\t\t|---------------------------|\n");
		printf("\t\t| 1) Cadastros.             |\n");
		printf("\t\t| 2) Altera��es.            |\n");
		printf("\t\t| 3) Comprar.               |\n");
		printf("\t\t| 4) Visualizar listas.     |\n");
		printf("\t\t| 5) Relat�rio.             |\n");
		printf("\t\t| 6) Sair.                  |\n");
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
						printf("Op��o inv�lida!");
					}
					break;
				}
			case 2://Alterar de cliente e produtos
				{
					printf("\t\t|---------------------------|\n");
                    printf("\t\t|   EasyBuy - Altera��es    |\n");
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
						printf("Op��o inv�lida!");
					}
					break;
				}
			case 3://Comprar produto
				{
					printf("\t\t|-------------------------------|\n");
                    printf("\t\t|       EasyBuy - Compra        |\n");
                    printf("\t\t|-------------------------------|\n");
					compra();
					printf("\t\t");
					break;
				}
			case 4://Visualizar produto e fornecedor
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
						printf("Op��o inv�lida!");
					}
					break;
				}
			case 5:
				{
					printf("\t\t|---------------------------------|\n");
                    printf("\t\t|       EasyBuy - Relat�rios      |\n");
                    printf("\t\t|---------------------------------|\n");
					printf("\t\t| 1) Fornecedores ordenados pelo  |\n\t\t|     Total de Compras.           |\n");
					printf("\t\t| 2) Produto, ordenados pelo      |\n\t\t|     Pre�o Unit�rio.             |\n");
					printf("\t\t|---------------------------------|\n");
					printf("\t\t");
					scanf("%d",&esc);
					if(esc == 1)
                    {
                        system("cls");
                        organizaFornec();
                    }
                    else if(esc == 2)
                    {
                        system("cls");
                    }break;
				}
			case 6:
				{
					printf("\n\n\t\tObrigado por utilizar o sistema EasyBuy!\n\n\t\t\t\t^-^\n\n");
					system("pause");
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
	temp->totalCompras = 0;
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
	int escFornec = 0;
	Produtos *temp;
	temp = (Produtos*)malloc(sizeof(Produtos));
	temp->codProdutos = cont;
	printf("\t\tInforme o nome do produto: \n\t\t");
	getchar();
	gets(temp->nomeProdutos);
	printf("\t\tInforme o pre�o unit�rio: \n\t\t");
	scanf("%f",&temp->precoUni);
	printf("\t\tInforme o c�digo do fornecedor desse produto: \n\t\t");
	scanf("%d",&escFornec);
	temp->codFornecedorProd = verificaFornce(escFornec);
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
	printf("\t\tCodigo do produto �: %d\n",temp->codProdutos);
	cont++;
	printf("\t\t");
	system("pause");
}

//Procurar se fornecedor existe
int verificaFornce(int escFornec){
    Fornecedores *temp;
    int saida = 0;
    while(saida != 1){
        for(temp = headFor; temp != NULL ; temp=temp->next){
            if(escFornec = temp->codFornecedores){
                saida = 1;
            }else{
                printf("\t\tFornecedor n�o cadastrado\n\t\tInforme um fornecedor existente: ");
                scanf("%d",&escFornec);
            }
        }
    }
    return escFornec;
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
        printf("\t\tQtde comprada: %.2f \n",temp->qtdComprada);
        printf("\t\tCod. do fornecedor: %d \n",temp->codFornecedorProd);
        printf("\t\t-----------------------\n");
    }
}

//Fun��o para alterar fornecedor
void alterarForn(){
    int valor,saida = 0;
    system("cls");
    Fornecedores* temp;
    printf("\t\tDigite o c�digo do fornecedor que deseja alterar: \n");
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

//Fun��o para alterar cadastro de produto
void alterarProd(){
    int valor, saida = 0;
    system("cls");
    Produtos* temp;
    printf("\t\tDigite o c�digo do produto que deseja alterar: \n\t\t");
    scanf ("%d", &valor);
    while(saida != 1){
        for(temp = headProd; temp != NULL ; temp=temp->next){
            if(temp->codProdutos == valor){
                system("cls");
                printf("\t\tDigite o novo nome do produto: \n\t\t");
                getchar();
                gets(temp->nomeProdutos);
                printf("\t\tInforme o novo pre�o unitario do produto: \n\t\t");
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

//Fun��o para compra
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

//Fun��o para somar total compra do fornecedor
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
            printf("\t\tProduto inexistente!\n\t\tInforme um produto v�lido: ");
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

//Ordena Froncedores por total de compras
int organizaFornec()
{
    Fornecedores *temp;


    int totalFornec = 0, inicio = 0, fim = 0;


    for (temp = headFor; temp != NULL; temp = temp->next)
    {
        totalFornec = totalFornec + 1;
        fim = fim + 1;
    }
    int vetor[totalFornec];

    int pivo, aux, i, j, meio;

   i = inicio;
   j = fim;

   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];

   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;

      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
         printf("Trocou %d por %d \n", vetor[j], vetor[i]);
      }
   }while(j > i);

   if(inicio < j) organizaFornec(vetor, inicio, j);
   if(i < fim) organizaFornec(vetor, i, fim);

}











