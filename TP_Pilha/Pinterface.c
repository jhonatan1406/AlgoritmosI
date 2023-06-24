#include <stdio.h>
#include <stdlib.h>

#include "Pinterface.h"

void MSG_MENU( )
{
    system("clear");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. INSERIR");
    printf("  \n\t2. PESQUISAR");
    printf("  \n\t3. EXCLUIR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t5. SAIR");
}
void MENU(TPilha *Pilha1){
    TProduto produto;
    TCelula *ptr;
    int p=0;
    int opcao=0;
    int i;
    do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                Ler(&produto);
                Empilhar (produto,Pilha1);
                break;
            case 2:
                printf("\nDigite o codigo do item:");
				fflush (stdin);
				scanf("%d",&produto.codigo);

				p=PesquisarPilha(*Pilha1,produto);
				if(p==1){
				printf("\n pesquisa com sucesso!!\n");
				ImprimirProdutoP(ptr->prox->item);
				}
				else {
	
				printf("\n não sucesso");
				}
                break;
            case 3:
            	printf("\n Digite o codigo do produto que queira excluir:");
				fflush(stdin);
				scanf("%d",&produto.codigo);
	
	
				Desempilhar(Pilha1,&produto);
				if(produto.codigo<0){
				printf("O produto não existe!!");
				}
				else {
				printf("Produto excluido!!\n");
				ImprimirProdutoP(produto);
				}
                break;
            case 4:
            	if (Pilha1->tamanho=0){
            		printf("Pilha vazia");
            		
				}
				else{
					
					ImprimirPilha(*Pilha1);
				}
                system("PAUSE");
                break;
            case 5:
                system("clear");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
                LiberarPilha(Pilha1);
                system("PAUSE");
                break;
            default:
                system("clear");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 5);
}

