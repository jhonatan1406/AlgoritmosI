#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
//structs : TProduto , TCelula , TLista
// asssiantura das funções: LEr,ImprimirProduto,FLVazia, Inserir, Pesquisar, EXcluir , Imrimir

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



void FFVazia(TFila *Fila);

int FilaVazia(TFila Fila);

void Enfileirar(TProduto x, TFila *Fila);

void Desenfileirar(TFila *Fila, TProduto *Item);

void ImprimirProdutoF (TProduto x);

int PesquisarFila(TFila Fila, TProduto x);

void ImprimirFila(TFila Fila);

void Excluir(TFila *F1,TProduto x);

void LiberarFila(TFila* Fila);

#endif // FILA_H_INCLUDED
