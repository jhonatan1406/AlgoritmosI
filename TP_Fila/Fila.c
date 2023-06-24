//Fila.c fazendo
#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

// Corpo das funções que possuem assinatura em Fila.h

void FFVazia (TLista *Fila )
{
    Fila->frente= (Tcelula*) malloc (sizeof (Tcelula));
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

void ImprimirProdutoF( TProduto h){
	printf("\n====================\n");
    printf("nome:%s",h.nome);
    printf("Codigo:%d\n",h.codigo);
    printf("preco:%.2f\n",h.preco);
	printf("\n===================\n");
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
    return result;
}

void ImprimirFila(TFila *Fila){
    TFila FAux;
    TProduto x;
    FFVazia(&FAux);

    while (!FilaVazia(*Fila)){
        Desenfileirar(Fila, &x);
        ImprimirProduto(x);
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
			Enfileirar (y,F2);
		}
	}
	while (!FilaVazia(F2)){
		Desenfileirar(&F2,&y);
		Enfileirar(y,Fila1);
	}
	
}


void LiberarFila(TFila *Fila){
    TProduto x;
    while(!FilaVazia(*Fila)){
        Desenfileirar(Fila, &x);
    }
    free(&Fila->frente);
}



