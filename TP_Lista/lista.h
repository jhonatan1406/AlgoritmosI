// lista.h


#ifndef HEADER_LISTA
#define HEADER_LISTA

#include <stdlib.h>
#include <stdio.h>

//structs : TProduto , TCelula , TLista
// asssiantura das funções: LEr,ImprimirProduto,FLVazia, Inserir, Pesquisar, EXcluir , Imrimir
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
void FLVazia (Tlista *lista );
int Vazia (Tlista lista);
int Tamanho ( Tlista lista);
void inserir (Tproduto x, Tlista *lista);
void Ler (Tproduto *h);
void ImprimirProduto ( Tproduto h);
void Imprimir (Tlista Lista);
Tcelula  * Pesquisar (Tlista lista , Tproduto Item);
void Excluir (Tlista *Lista , Tproduto *Item);
void Liberar (Tlista *Lista);

#endif
