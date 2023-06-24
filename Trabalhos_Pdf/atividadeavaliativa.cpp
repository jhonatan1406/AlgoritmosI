#include <stdio.h>
#include <stdlib.h>
typedef struct end{
	char rua [100];
	int numero;
	char bairro [100];
	char complemento [100];
	char cidade [100];
	char estado [100];
	int cep ;
}TEndereco;

typedef struct Livro{
	char ISBN[40];
	char titulo[100];
	int edicao;
	TEndereco endereco;
}TLivro;

 void Leitura (TLivro*l){
 	
 	printf ("digite a ISBN:");
 	fflush(stdin);
 	fgets(l->ISBN,100,stdin);
 	
	printf ("digite o Titulo:");
 	fflush(stdin);
 	fgets(l->titulo,100,stdin);
 	
	printf ("digite a edicao:");
 	fflush(stdin);
 	scanf ("%d",&l->edicao); 
 	
	printf ("digite sua rua :");
 	fflush(stdin);
 	fgets(l->endereco.rua,100,stdin);
	 	
 	printf ("digite seu numero:");
 	fflush(stdin);
 	scanf ("%d",l->endereco.numero);
 	
 	
 	printf ("digite seu bairro:");
 	fflush(stdin);
 	fgets(l->endereco.bairro,100,stdin);
 	
 	
 	printf ("digite seu complemento:");
 	fflush(stdin);
 	fgets(l->endereco.complemento,100,stdin);
 	
 	printf ("digite seu cidade:");
 	fflush(stdin);
 	fgets(l->endereco.cidade,100,stdin);
 	
 	
 	printf ("digite seu cep:");
 	fflush(stdin);
 	scanf("%d",&l->endereco.cep);
 	
 	
 	printf ("digite seu estado:");
 	fflush(stdin);
 	fgets(l->endereco.estado,100,stdin);
 	
 }
 void Imprimir(TLivro*l){
 
    printf("ISBN:%s\n",l->ISBN);
    printf("titulo:%s\n",l->titulo);
    printf("edicao:%d\n",l->edicao);
    printf("rua:%s\n",l->endereco.rua);
    printf("numero:%d\n",l->endereco.numero);
    printf("bairro:%s\n",l->endereco.bairro);
    printf("complemento:%s\n",l->endereco.complemento);
    printf("cidade:%s\n",l->endereco.cidade);
    printf("cep:%d\n",l->endereco.cep);
    printf("estado:%s\n",l->endereco.estado);
}

int main (){
	
	TLivro *ptr;
	ptr= (TLivro*)calloc(10,sizeof(TLivro));
	int i=0;
	int j=0;
	
	for(i=0;i<10;i++){
		Leitura(ptr+i);
		Imprimir(ptr+i);
	}
	free(ptr);
	return 0;
}
