#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

void JuntarLista (Tlista *L1, Tlista *L2){
	L1->ultimo->prox= L2->primeiro->prox;	
}

void Divide( Tlista L1, Tlista *L2 ,Tlista *L3){
	
	Tcelula *aux;
	FLVazia (L2);
	FLVazia (L3);
	
	
	int primeirametade= L1.tamanho/2;
	
	aux = L1.primeiro->prox;
	for (int i=0; i<primeirametade ;i++){
		inserir(aux->item,L2);
		aux =aux->prox;
	}
	while (aux!=NULL){
		inserir(aux->item,L3);
		aux = aux->prox;
	}
}
int ListasIguais (Tlista L1, Tlista L2){
	if(L1.tamanho != L2.tamanho){
		return 0;
	}
	else{
		Tcelula *aux1 = L1.primeiro->prox;
		Tcelula *aux2 = L2.primeiro->prox;
		
		while (aux1!=NULL){
			if(aux1->item.codigo != aux2->item.codigo){
				return 0;
			}
			aux1=aux1->prox;
			aux2= aux2->prox;
		}
	}
	return 1;
}

void PesquisaCelula (Tlista *L, int j){
	Tcelula *aux1 = L->primeiro ->prox;
	int i=1;
	if(j<=L->tamanho){
	
		while (aux1 !=NULL){
			if(i==j){
				printf("\nItem encontrado:");
				ImprimirProduto(aux1->item);
			
			
			}
			aux1=aux1->prox;
			i++;
		}
	}
	else {
		printf("para de ser burro, não tem esse item!!");
	}
	
	
	
} 

void IncrementaOrdem ( Tlista *L2){
	
	Tproduto x;
	printf("Digite um item que deseja inserir em ordem !");
	Ler (&x);
	if(Vazia(*L2) || (strcmp(L2->ultimo->item.nome,x.nome) <=0) ){
		inserir(x,L2);
	}
	else{
		Tcelula *aux1 = L2->primeiro, *aux2,*aux3;
		while ((strcmp(aux1->prox->item.nome,x.nome))<=0){
			aux1=aux1->prox;
		}
		aux2=aux1->prox;
		aux3=(Tcelula*)malloc(sizeof(Tcelula));
		aux3->item=x;
		aux1->prox=aux3;
		aux3->prox= aux2;
	}	
	
}
void RemoverItem(Tlista *L1, int j){
	Tcelula *aux1 = L1->primeiro,*aux2,*aux3;
	int i=1;
	while (aux1->prox!=NULL && i<=j){
		if(i==j){
			aux2=aux1->prox;
			aux3->prox= aux2;
			break;
		}
		aux3=aux1;
		aux1=aux1->prox;
		i++;
		free(aux1);
	}
}
void Remover2(Tlista *L1, int j){
	Tcelula *aux1 = L1->primeiro,*aux2,*aux3;
	int i=1;
	
	while (i<=j){
		aux3=aux1;
		aux1=aux1->prox;
		i++;
	}
		aux2=aux1->prox;
		aux3->prox= aux2;
		printf("\n");
}


int main (){
	
	Tlista l1,l2;
	Tproduto x;
	FLVazia(&l1);
	FLVazia(&l2);
	
	Ler(&x);
	inserir(x,&l1);
		
	Ler(&x);
	inserir(x,&l1);
	
	Ler(&x);
	inserir(x,&l1);
	
		Ler(&x);
	inserir(x,&l1);
	
		Ler(&x);
	inserir(x,&l1);
	/*JuntarLista(&l1,&l2);
	Imprimir(l1);
		
	Divide(l1,&l4,&l5);

	Imprimir (l4);
	Imprimir (l5);
	int i=0;
	
	printf("\nDigite um numero da lista que desja ver :");
	scanf("%d",&i);
	PesquisaCelula(&l1,i);*/
	
	//IncrementaOrdem(&l1);
	
	RemoverItem(&l1,3);
	Imprimir (l1);
	return 0;
}
