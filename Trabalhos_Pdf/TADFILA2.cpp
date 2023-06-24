//   LISTA TADFILA
// jhonatan Figueiredo Almeida  20.1.8164

/*1. Escreva uma fun��o que verifica se duas listas simplesmente encadeadas s�o iguais.*/
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
	// retorna 1 se forem iguais !!
}

/*2. Construa uma fun��o que concatena duas listas passadas como par�metro.*/


void JuntarLista (Tlista *L1, Tlista *L2){
	L1->ultimo->prox= L2->primeiro->prox;	
	// Junta por endere�o de memoria 
}

/*3. Construa uma fun��o que recebe como par�metro tr�s listas L1, L2 e L3. A fun��o dever�
dividir a lista L1 em duas outras listas (dividir pela metade) que dever�o ser retornadas
nas listas L2 e L3. Por exemplo, seja L1 = {A, B, C, D, E}, ent�o, L2 e L3 dever�o ficar
como: L2 = {A, B, C} e L3 = {D, E}*/


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
/*4. Fa�a uma fun��o que insere elementos em ordem crescente de nomes em uma lista simplesmente encadeada. 
Para isso, pense nos tr�s casos a seguir: (a) quando a lista estiver vazia,
utilize a fun��o Insere padr�o (que sempre insere um elemento no final da lista), constru�da
em sala de aula, para inserir o elemento, veja que se ela est� vazia basta inserir o primeiro
elemento sem se importar com a ordem da lista; (b) se o elemento a ser inserido na lista
for maior do que o �ltimo elemento existente na lista, utilize a fun��o Insere padr�o, pois,
se ele j� � maior do que o �ltimo, significa que ele dever� entrar no final da lista; (c) este
caso somente acontece quando os casos (a) e (b) n�o acontecem, assim, voc� deve percorrer
a lista comparando o elemento a ser inserido com os que j� existem na lista, enquanto o elemento a ser inserido 
for maior do que o elemento comparado, continue percorrendo a lista,
caso ele seja menor ou igual, ent�o voc� encontrou o ponto de inser��o do novo elemento.*/

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
/*5. Fa�a uma fun��o que receba como par�metro uma lista simplesmente encadeada e imprima
os dados da i-�sima c�lula dessa lista. Tenha certeza de que a c�lula existe. Por exemplo,
se a lista for L1 = (A, B, C, D, E) e i = 3, voc� dever� realizar uma varredura na lista de
modo que avance apenas i vezes e consiga acessar a terceira c�lula e imprimir o elemento
C.*/

void PesquisaCelula (Tlista *L, int j){
	// Poderia colocar para o usurio digitar O J aqui na fun��o , ficaria assim:
	/*printf("\nDigite um numero da lista que desja ver :");
	scanf("%d",&j);
	e n�o precisaria de passsar o j*/
	
	Tcelula *aux1 = L->primeiro ->prox;
	int i=1;
	// Fiz IF caso o usuario seja "Inteligente" e digite numero que n�o tenha na lista
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
		printf("para de ser Trouxa, n�o tem esse item!!");
	}
	
	
	
} 

/*6. Baseado na l�gica da quest�o anterior, fa�a uma fun��o que receba como par�metro uma
lista simplesmente encadeada e remova a i-�sima c�lula dessa lista.*/


void RemoverItem(Tlista *L1, int j){
	Tcelula *aux1 = L1->primeiro,*aux2,*aux3;
	int i=1;
	while (aux1->prox!=NULL && i<=j){
		if(i==j){
			aux2=aux1->prox;
			aux3->prox= aux2;
			break;// para o loop, n�o alocar endere�o o aux3
		}
		aux3=aux1;
		aux1=aux1->prox;
		i++;
		free(aux1);
	}
}
// RemoveItem2 esta mais "simples"
void RemoverItem2(Tlista *L1, int j){
	Tcelula *aux1 = L1->primeiro,*aux2,*aux3;
	int i=1;
	0
	while (i<=j){
		aux3=aux1;
		aux1=aux1->prox;
		i++;
	}
		aux2=aux1->prox;
		aux3->prox= aux2;
}

