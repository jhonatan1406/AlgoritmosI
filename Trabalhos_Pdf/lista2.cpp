#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int codigo;
    char nome[200];
    int quantidade ;
    float preco;
} Tproduto;

typedef struct celula
{
    Tproduto item;
    struct celula * prox;
} Tcelula;


typedef struct
{
    Tcelula * primeiro;
    Tcelula * ultimo;
    int tamanho;

} Tlista;

void FLVazia (Tlista *lista )
{
    lista  ->primeiro= (Tcelula*) malloc (sizeof (Tcelula));
    lista ->ultimo = lista ->primeiro;
    lista ->primeiro->prox = NULL;
    lista->tamanho=0;
}

int Vazia (Tlista lista)
{
    return (lista.primeiro== lista.ultimo);
}

int Tamanho ( Tlista lista)
{
    return lista.tamanho;
}

void inserir (Tproduto x, Tlista *lista)
{
    lista ->ultimo->prox= (Tcelula*) malloc (sizeof ( Tcelula));
    lista->ultimo= lista->ultimo->prox;
    lista->ultimo->item= x;
    lista->ultimo->prox=NULL;
    lista->tamanho++;
}
void Ler (Tproduto *h){
    printf("nome:");
    fflush(stdin);
    fgets(h ->nome , 200, stdin);

    printf("Codigo:");
    fflush(stdin);
    scanf("%d",&h ->codigo);

    printf("preco:");
    fflush(stdin);
    scanf("%f",&h ->preco);

}
void ImprimirProduto ( Tproduto h){
	printf("\n====================\n");
    printf("nome:%s",h.nome);
    printf("Codigo:%d\n",h.codigo);
    printf("preco:%.2f\n",h.preco);
	printf("\n===================\n");
}

void Imprimir (Tlista Lista){
	
	Tcelula *aux;
	aux= Lista.primeiro->prox;
	while (aux != NULL){
		ImprimirProduto (aux->item );
		aux= aux->prox;
	}
} 
Tcelula  * Pesquisar (Tlista lista , Tproduto Item){	
	Tcelula * aux;
	aux =lista.primeiro;
	while (aux->prox != NULL){
		if(aux->prox->item.codigo==Item.codigo){
			return aux;
		}
		aux=aux->prox;
	}
	return NULL;
}


void Excluir (Tlista *Lista , Tproduto *Item){
	Tcelula *aux1 , *aux2;
	aux1=Pesquisar (*Lista , *Item);
	if(aux1!=NULL){
		aux2 = aux1->prox;
		aux1->prox = aux2->prox;
		*Item =aux2 ->item;
		if(aux1->prox==NULL){
			Lista->ultimo = aux1;
		}
		free(aux2);
		Lista->tamanho--;
	}
	else {
		Item->codigo=-1;	
	}
}
void Liberar ( Tlista * Lista ){
	
	Tproduto x;
	while (Lista->primeiro!=Lista->ultimo ){
		x=Lista->ultimo->item;
		Excluir (Lista,&x);
	}
	free(Lista->primeiro);
	printf("\nProdutos Liberados com sucesso !!");	
}

void LIBERAR( lista *Lista){
	while (!Vazia(*Lista)){
		Excluir (Lista, & Lista->primeiro->prox->item);
	}
	free (Lista->primeiro);
}
int main ()
{
    Tproduto x;
    Tlista L1;
    FLVazia(&L1);
    int i=0;
    Tcelula *ptr,*ptr2;
    printf("Vazia :%d\n", Vazia(L1));
   // inserir(x,&L1);
    printf("==============================\n");


    
    for ( i=0; i<2 ; i++){
        Ler(&x);
        printf("\n");
        inserir(x,&L1);
    }
    printf("\n===================\n");
    Imprimir(L1);
    printf("\n=======================\n");


    printf("\ntamanho da lista:%d",Tamanho(L1));
    printf("\n==================================\n");
	
	printf("\nDigite o codigo do item:");
	fflush (stdin);
	scanf("%d",&x.codigo);

	ptr=Pesquisar (L1,x);
	if(ptr!=NULL){
		printf("\n pesquisa com sucesso");
		ImprimirProduto(ptr->prox->item);
	}
	else {
	
	printf("\nn sucesso");
	}
	
	
	printf("\n Digite o codigo que queira excluir:");
	fflush(stdin);
	scanf("%d",&x.codigo);
	
	
	Excluir(&L1,&x);
	if(x.codigo<0){
		printf("O produto não existe!!");
	}
	else {
		printf("Produto excluido!!\n");
		ImprimirProduto(x);
	}
	Liberar(&L1);
	printf("\n ta vazia ? %d",Vazia(L1));
	
    return 0;
}
