#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int codigo;
    char nome[200];
    int quantidade ;
    float preco;
	
	
}TProduto;

typedef struct celula {
	TProduto item;
	struct celula *prox;
	
}TCelula;
typedef struct {
	TCelula *fundo;
	TCelula *topo;
	int tamanho;
}TPilha;

void FPVazia(TPilha *Pilha);

int PilhaVazia(TPilha Pilha);

void Ler (TProduto *h);

void Empilhar(TProduto x, TPilha *Pilha);

void Desempilhar(TPilha *Pilha, TProduto *item);

int PesquisarPilha(TPilha Pilha, TProduto x);

void ImprimirProdutoP( TProduto h);

void DiferencaPilha(TPilha Pilha, TPilha PAux1, TPilha PAux2);

void ImprimirPilha(TPilha Pilha);

void LiberarPilha(TPilha *Pilha);

#endif //PILHA_H_INCLUDED
