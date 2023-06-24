// ListaTADfila 

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int codigo;
    char nome[200];
    int quantidade ;
    float preco;
} TProduto;

typedef struct celula
{
    TProduto item;
    struct celula * prox;
} TCelula;


typedef struct
{
    TCelula * frente;
    TCelula * tras;
    int tamanho;

} TFila;


void FFVazia (TFila *Fila )
{
    Fila->frente= (TCelula*) malloc (sizeof (TCelula));
    Fila ->tras = Fila ->frente;
    Fila ->frente->prox = NULL;
    Fila->tamanho=0;
}
int FilaVazia (TFila Fila)
{
    return (Fila.frente== Fila.tras);
}
int Tamanho ( TFila Fila)
{
    return Fila.tamanho;
}
void Ler (TProduto *h){
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
void Enfileirar(TProduto x, TFila *Fila){
    Fila -> tras -> prox = (TCelula *) malloc(sizeof(TCelula));
    Fila -> tras = Fila -> tras -> prox;
    Fila -> tras -> item = x;
    Fila -> tras -> prox = NULL;
    Fila -> tamanho++;
}

void Desenfileirar(TFila *Fila, TProduto *Item){
    TCelula *aux;
    if (!FilaVazia(*Fila)) {
       aux = Fila -> frente -> prox;
        Fila -> frente -> prox = aux -> prox;
        *Item = aux -> item;
        free(aux);
        if (Fila -> frente -> prox == NULL)
            Fila -> tras = Fila -> frente;
        Fila->tamanho--;
    }
    else
        printf("\nERRO: FILA VAZIA!");
}


TProduto PesquisarFila(TFila *Fila, TProduto x){
    TFila FAux;
    TProduto item, y;
    FFVazia(&FAux);
    int flag=0;
    

    while (!FilaVazia(*Fila)){
        Desenfileirar(Fila, &item);
        if(x.codigo == item.codigo){
             flag=1;
             y=item;
        }
        Enfileirar(item, &FAux);
    }

    while (!FilaVazia(FAux)){
        Desenfileirar(&FAux, &item);
        Enfileirar(item, Fila);
        
    }
    free(&FAux.frente);
    if(flag==1){
    	return y;
    	
	}
	else{
		y.codigo=-1;
		return y;
	}
}
void ImprimirProdutoF( TProduto h){
	printf("\n====================\n");
    printf("nome:%s",h.nome);
    printf("Codigo:%d\n",h.codigo);
    printf("preco:%.2f\n",h.preco);
	printf("\n===================\n");
}
void ImprimirFila(TFila *Fila){
    TFila FAux;
    TProduto x;
    FFVazia(&FAux);

    while (!FilaVazia(*Fila)){
        Desenfileirar(Fila, &x);
        ImprimirProdutoF(x);
        Enfileirar(x, &FAux);
    }

    while (!FilaVazia(FAux)){
        Desenfileirar(&FAux, &x);
        Enfileirar(x, Fila);
    }
    free(&FAux.frente);
}
void Excluir ( TFila *Fila1, TProduto x){
	TFila F2;
	FFVazia(&F2);
	TProduto y;
	while (!FilaVazia(*Fila1)){
		Desenfileirar(Fila1,&y);
		if(y.codigo!=x.codigo){
			Enfileirar (y,&F2);
		}
	}
	while (!FilaVazia(F2)){
		Desenfileirar(&F2,&y);
		Enfileirar(y,Fila1);
	}
	
}
int Compara (TFila *F1, TFila *F2){
	TFila aux1,aux2;
	TProduto y,x;
	int cont=0;
	FFVazia(&aux1);
	FFVazia(&aux1);
	if(F1->tamanho!=F2->tamanho){
		return 0;
	}
	while (!FilaVazia(*F1)){
		Desenfileirar(F1,&x);
		while (!FilaVazia(*F2)){
			Desenfileirar(F2,&y);
			if(x.codigo==y.codigo){
				cont++;
			}
			Enfileirar(y,&aux2);
		}
		Enfileirar (x, &aux1);
		while (!FilaVazia(aux2)){
			Desenfileirar(&aux2,&y);
			Enfileirar(y,F2);
		}
	}
	while (!FilaVazia(aux1)){
		
		Desenfileirar(&aux1,&x);
		Enfileirar (x,F1);
		
	}

	
	if(cont==F1->tamanho){
		return 1;
	}
	else{
		return 0;
	}
	
}
void ExcluirN (TFila *F1, int Codigo){
	
	TFila aux1;
	FFVazia (&aux1);
	TProduto x;
	
	while (!FilaVazia (*F1)){
		Desenfileirar(F1,&x);
		if(x.codigo!=Codigo){
			Enfileirar (x,&aux1);
		}
		else {
			printf("Produto excluido:");
			ImprimirProdutoF(x);
		}
	}
	while (!FilaVazia(aux1)){
		
		Desenfileirar(&aux1,&x);
		Enfileirar (x,F1);
		
	}
	
}

void Intersecao (TFila *F1,TFila *F2,TFila *F3){
	TFila aux1,aux2;
	TProduto y,x;
	FFVazia(&aux1);
	FFVazia(&aux2);
	while (!FilaVazia(*F1)){
		Desenfileirar(F1,&x);
		while (!FilaVazia(*F2)){
			Desenfileirar(F2,&y);
			if(x.codigo==y.codigo){
				Enfileirar(x,F3);
			}
			
			Enfileirar(y,&aux2);
		}
		Enfileirar (x, &aux1);
		while (!FilaVazia(aux2)){
			Desenfileirar(&aux2,&y);
			Enfileirar(y,F2);
		}
	}
	while (!FilaVazia(aux1)){
		
		Desenfileirar(&aux1,&x);
		Enfileirar (x,F1);
		
	}

}



void LiberarFila(TFila *Fila){
    TProduto x;
    while(!FilaVazia(*Fila)){
        Desenfileirar(Fila, &x);
    }
    free(&Fila->frente);
}
int main (){
	TProduto x,y;
	TFila f1,f2,f3;
	FFVazia (&f1);
	FFVazia (&f2);
	FFVazia (&f3);
	int cont=0;
	
	Ler(&x);
	Enfileirar(x,&f1);
	Ler(&x);
	Enfileirar(x,&f1);
	Ler(&x);
	Enfileirar(x,&f1);
	
	
	Ler(&y);
	Enfileirar(y,&f2);
	Ler(&y);
	Enfileirar(y,&f2);
	Ler(&y);
	Enfileirar(y,&f2);
	
	printf("digite o codigo queira excluir");
	scanf("%d",&x.codigo);
	Excluir(&f1,x);
	ImprimirFila(&f1);
	cont =Compara(&f1,&f2);
	if(cont==1){
		printf("\nsao iguais!");
	}
	else {
		printf("\n difirentes!!");
	}
	printf("\nFazendo interseção!!");
	
	Intersecao(&f1,&f2,&f3);
	
	ImprimirFila(&f3);
	printf("\nImprimindo fila 2!!");
	ImprimirFila(&f2);
	LiberarFila(&f1);
	LiberarFila(&f2);
	LiberarFila(&f3);
	
	return 0;
}




