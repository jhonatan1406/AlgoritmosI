// fazendo Pilha.c
#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

// Corpo das funções que possuem assinatura em Pilha.h
void FPVazia(TPilha *Pilha){
	Pilha->topo = (TCelula*) malloc (sizeof (TCelula));
	Pilha->fundo = Pilha->topo;
	Pilha->topo->prox= NULL;
	Pilha->tamanho=0;
}
int PilhaVazia(TPilha Pilha){
	return (Pilha.topo==Pilha.fundo);
	
}
void Ler (TProduto *h){
    printf("nome:");
    fflush(stdin);
    fgets(h->nome , 200, stdin);

    printf("Codigo:");
    fflush(stdin);
    scanf("%d",&h ->codigo);

    printf("preco:");
    fflush(stdin);
    scanf("%f",&h ->preco);

}
void ImprimirProduto ( TProduto h){
	printf("\n====================\n");
    printf("nome:%s",h.nome);
    printf("Codigo:%d\n",h.codigo);
    printf("preco:%.2f\n",h.preco);
	printf("\n===================\n");
}
void Empilhar (TProduto x, TPilha *Pilha){
	TCelula *aux;
	aux = (TCelula*) malloc (sizeof (TCelula));
	Pilha->topo->item=x;
	aux->prox=Pilha->topo;
	Pilha->topo=aux;
	Pilha->tamanho++; 
}
void Desempilhar (TPilha *Pilha, TProduto *Item){
	TCelula *aux;
	
	if(PilhaVazia(*Pilha)){
		printf("Erro: Lista vazia");
		return ;
	}
	aux = Pilha->topo;
	Pilha->topo= aux->prox;
	*Item = aux->prox->item;
	free(aux);
	Pilha->tamanho--;
}
int PesquisarPilhaP(TPilha *Pilha, TProduto x){
    TPilha PAux;
    TProduto item;
    FPVazia(&PAux);
    int result = 0;

    while (!PilhaVazia(*Pilha)){
        Desempilhar(Pilha, &item);
        if(x.codigo == item.codigo){
            result = 1;
        }
        Empilhar(item, &PAux);
    }

    while(!PilhaVazia(PAux)){
        Desempilhar(&PAux, &item);
        Empilhar(item, Pilha);
        
    }
    free(PAux.fundo);
    return result;
}


void ImprimirPilha(TPilha Pilha){
    TPilha PAux;
    TProduto item;
    FPVazia(&PAux);

    while (!PilhaVazia(Pilha)){
        Desempilhar(&Pilha, &item);
        ImprimirProduto(item);
        Empilhar(item, &PAux);
    }

    while(!PilhaVazia(PAux)){
        Desempilhar(&PAux, &item);
        (item, &Pilha);
    }
    free(PAux.fundo);

}

void Crescente (TPilha *P1){
	TProduto y,x;
	TPilha aux1;
	int i=1, n;
	Desempilhar(P1,&y);
	n = P1->tamanho;
	

		while (n-i>0){
			
			Desempilhar(P1,&x);
			if(x.codigo<y.codigo){
				
				Empilhar(y,&aux1);
				y=x;
			}
			else {
				Empilhar(x,&aux1);
			}
			i++;
		}
		Empilhar (y,P1);
		while (!PilhaVazia(aux1)){
			Desempilhar (&aux1,&x);
			Empilhar (x,P1);
		}
		
	
	
	
}
void OrdemInvertida (TPilha *P1){
	
	TProduto y,x;
	TPilha aux1;
	n=P1->tamanho;
	int i=0;
	
	while (n-1){
		
		Desempilhar (P1,&y);

		while (n-i>0){
			
			Desempilhar(P1,&x);
			Empilhar(x,&aux1);
			i++;
		}
		Empilhar (y,P1);
		while (!PilhaVazia(aux1)){
			Desempilhar (&aux1,&x);
			Empilhar (x,P1);
		}
		
	}
	
	
}






void LiberarPilha(TPilha *Pilha){
    TProduto x;
    while (!PilhaVazia(*Pilha)){
        Desempilhar(Pilha, &x);
    }
    free(&Pilha->topo);
}
