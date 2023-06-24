//Lista TADFILA TADPilha
//Jhonatan Figueiredo ALmeida
//FILA

/*1. Crie uma fun¸c˜ao Liberar para Filas obedecendo o padr˜ao de acesso FIFO, ou seja, os
elementos s´o podem ser acessados desenfileirando-os da Fila. Para isso,utilize um la¸co de
repeti¸c˜ao em que a condi¸c˜ao de parada seja “equanto a fila n˜ao estiver vazia...”.
*/
void LiberarFila(TFila *Fila){
    TProduto x;
    while(!FilaVazia(*Fila)){
        Desenfileirar(Fila, &x);
    }
    free(&Fila->frente);
}

/*2. Fa¸ca uma funçãoao que verifica se duas Filas apresentam os mesmos elementos, por exemplo,
sejam F1 = {1, 2, 3, 4, 5} e F2 = {3, 4, 1, 5, 2}, ent˜ao F1 == F2, pois são o mesmo conjunto,
apesar da ordem dos elementos serem diferentes. Obede¸ca a forma de acesso aos elementos
da Fila, ou seja, os elementos somente s˜ao acessados via FIFO. Para isso, utilize Filas
auxiliares para armazenar os elementos enquanto vocˆe os desenfileira de uma Fila original.*/
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

/*3. Fa¸ca uma fun¸c˜ao que receba como parˆametro uma Fila simplesmente encadeada e um
parˆametro n e remova o n-´esimo item dessa Fila. Siga a forma de acesso via FIFO e utilize
Filas auxiliares quando necess´ario.*/
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
/*4. Implemente uma fun¸c˜ao que receba como parˆametro trˆes Filas simplesmente encadeadas e
que realiza a interse¸c˜ao (opera¸c˜ao de conjunto) dos elementos das duas primeiras Filas na
terceira. Por exemplo, sejam as filas F1 = {1, 2, 3, 4, 5} e F2 = {6, 7, 8, 4, 5}, o resultado da
interse¸c˜ao entre as duas filas na terceira fila ser´a F3 = {4, 5}.*/
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

/*5. Desenvolva uma fun¸c˜ao que receba como parˆametro trˆes Filas e fa¸ca com que o resultado da
diferen¸ca (opera¸c˜ao de diferen¸ca entre conjuntos) dos elementos da primeira com a segunda
seja colocado na terceira Fila. Por exemplo, sejam as filas F1 = {1, 2, 3, 4, 5} e F2 =
{6, 7, 8, 4, 5}, o resultado da diferen¸ca entre as duas filas na terceira fila ser´a F3 = {1, 2, 3}.*/

void Diferença (TFila *F1,TFila *F2,TFila *F3){
	TFila aux1,aux2;
	TProduto y,x;
	FFVazia(&aux1);
	FFVazia(&aux2);
	while (!FilaVazia(*F1)){
		Desenfileirar(F1,&x);
		while (!FilaVazia(*F2)){
			Desenfileirar(F2,&y);
			if(x.codigo!=y.codigo){
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

// FILA
/*1. Crie uma fun¸c˜ao que inverta a ordem dos elementos em uma pilha: (a) usando duas pilhas
auxiliares; (b) usando uma fila auxiliar; (c) usando uma pilha auxiliar e vari´aveis auxiliares.
N˜ao ´e permitido o uso de vetores*/

A)
void Inversocomaux (Pilha *P1){
	
	
	TPilha aux1,aux2;
	
	FPVazia(&aux1);
	FPVazia(&aux2);
	TProduto x;
	
	while (!PilhaVazia(*P1)){
		Desempilhar(P1,&x);
		Empilhar(x,&aux1)
		
	}
	while (!PilhaVazia(aux1)){
		Desempilhar(&aux1,&x);
		Empilhar(x,&aux2);
	}
	while (!PilhaVazia(aux2)){
		Desempilhar(&aux2,&x);
		Empilhar (x,P1);
	}
	
	
}


B)
void InverFila (Pilha *P1){
	
	
	TFila F1;
	FFVazia(&F1);
	TProduto x;
	
	while (!PilhaVazia(*P1)){
		Desempilhar(P1,&x);
		Enfileirar(x,&F1)
		
	}
	while (!FilaVazia(F1)){
		Desemfileirar(&F1,&x);
		Empilhar(x,P1);
	}
	
}
C)
void OrdemInvertida (TPilha *P1){
	
	TProduto y,x;
	TPilha aux1;
	n=P1->tamanho;
	int i=0;
	
	while (n-1>0){
		
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


/*2. Crie uma fun¸c˜ao que transfere os elementos da primeira pilha para a segunda sem utilizar
uma pilha auxiliar e que mantenha a mesma ordem dos elemento da pilha original. N˜ao ´e
permitido o uso de vetores, utilize apenas algumas vari´aveis auxiliares.*/


void TransfereElemento (TPilha *P1){
	
	TProduto x;
	TPiha aux1;
	OrdemInvertida (P1);
	
	while (!PihaVazia(*P1)){
		Desempilhar(P1,&x);
		Empilhar(x,&aux1)
	}
	while (!PilhaVazia(aux1)){
		Desempilhar(&aux1,&x);
		Empilhar(x,P1);
	}
	
}







