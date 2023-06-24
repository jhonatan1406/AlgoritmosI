#include <stdio.h>
#include <stdlib.h>

#include "Finterface.h"

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
void MENU(TFila *Fila1){
    TProduto produto;
    Tcelula *ptr;
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
                Enfileirar (produto,lista1);
                break;
            case 2:
                printf("\nDigite o codigo do item:");
				fflush (stdin);
				scanf("%d",&produto.codigo);

				ptr=PesquisarFila (*lista1,produto);
				if(ptr->item.codigo >=0){
				printf("\n pesquisa com sucesso!!\n");
				ImprimirProdutoF(ptr->item);
				}
				else {
	
				printf("\n não sucesso");
				}
                break;
            case 3:
            	printf("\n Digite o codigo do produto que queira excluir:");
				fflush(stdin);
				scanf("%d",&produto.codigo);
	
	
				Desenfileirar(Fila1,&produto);
				if(produto.codigo<0){
				printf("O produto não existe!!");
				}
				else {
				printf("Produto excluido!!\n");
				ImprimirProduto(produto);
				}
                break;
            case 4:
            	if (Fila1->tamanho=0){
            		printf("Lista vazia");
            		
				}
				else{
					
					ImprimirFila(Fila1);
				}
                system("PAUSE");
                break;
            case 5:
                system("clear");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
                LiberarFila(Fila1);
                system("PAUSE");
                break;
            default:
                system("clear");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 5);
}

