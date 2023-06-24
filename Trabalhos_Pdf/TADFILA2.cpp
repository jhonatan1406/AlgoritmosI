//   LISTA TADFILA
// jhonatan Figueiredo Almeida  20.1.8164

/*1. Escreva uma função que verifica se duas listas simplesmente encadeadas são iguais.*/
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

/*2. Construa uma função que concatena duas listas passadas como parâmetro.*/


void JuntarLista (Tlista *L1, Tlista *L2){
	L1->ultimo->prox= L2->primeiro->prox;	
	// Junta por endereço de memoria 
}

/*3. Construa uma função que recebe como parâmetro três listas L1, L2 e L3. A função deverá
dividir a lista L1 em duas outras listas (dividir pela metade) que deverão ser retornadas
nas listas L2 e L3. Por exemplo, seja L1 = {A, B, C, D, E}, então, L2 e L3 deverão ficar
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
/*4. Faça uma função que insere elementos em ordem crescente de nomes em uma lista simplesmente encadeada. 
Para isso, pense nos três casos a seguir: (a) quando a lista estiver vazia,
utilize a função Insere padrão (que sempre insere um elemento no final da lista), construída
em sala de aula, para inserir o elemento, veja que se ela está vazia basta inserir o primeiro
elemento sem se importar com a ordem da lista; (b) se o elemento a ser inserido na lista
for maior do que o último elemento existente na lista, utilize a função Insere padrão, pois,
se ele já é maior do que o último, significa que ele deverá entrar no final da lista; (c) este
caso somente acontece quando os casos (a) e (b) não acontecem, assim, você deve percorrer
a lista comparando o elemento a ser inserido com os que já existem na lista, enquanto o elemento a ser inserido 
for maior do que o elemento comparado, continue percorrendo a lista,
caso ele seja menor ou igual, então você encontrou o ponto de inserção do novo elemento.*/

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
/*5. Faça uma função que receba como parâmetro uma lista simplesmente encadeada e imprima
os dados da i-ésima célula dessa lista. Tenha certeza de que a célula existe. Por exemplo,
se a lista for L1 = (A, B, C, D, E) e i = 3, você deverá realizar uma varredura na lista de
modo que avance apenas i vezes e consiga acessar a terceira célula e imprimir o elemento
C.*/

void PesquisaCelula (Tlista *L, int j){
	// Poderia colocar para o usurio digitar O J aqui na função , ficaria assim:
	/*printf("\nDigite um numero da lista que desja ver :");
	scanf("%d",&j);
	e não precisaria de passsar o j*/
	
	Tcelula *aux1 = L->primeiro ->prox;
	int i=1;
	// Fiz IF caso o usuario seja "Inteligente" e digite numero que não tenha na lista
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
		printf("para de ser Trouxa, não tem esse item!!");
	}
	
	
	
} 

/*6. Baseado na lógica da questão anterior, faça uma função que receba como parâmetro uma
lista simplesmente encadeada e remova a i-ésima célula dessa lista.*/


void RemoverItem(Tlista *L1, int j){
	Tcelula *aux1 = L1->primeiro,*aux2,*aux3;
	int i=1;
	while (aux1->prox!=NULL && i<=j){
		if(i==j){
			aux2=aux1->prox;
			aux3->prox= aux2;
			break;// para o loop, não alocar endereço o aux3
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

