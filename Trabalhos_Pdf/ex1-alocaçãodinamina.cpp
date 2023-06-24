#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	
	char destino[40];
	char origem[40];
	
	int tamd=0;
	int tamo =0;
	
	printf("Digite um destino:");
	fflush(stdin);
	fgets(destino,40,stdin);
	printf("Digite uma origem:");
	fflush(stdin);
	fgets(origem,40,stdin);
	printf("Tamanho da string : %d\n",strlen(destino));
	
	
	
	

	if(strcmp(destino,origem)==0){
		printf("São iguais");
	}
	else if (strcmp(destino,origem)>0){
		printf("destino menor que origem");
	}
	else if(strcmp(destino,origem)<0){
		printf("destino maior que origem");
	}
	
	strcat(destino,origem);	
	
	while (*(destino+tamd)!='\0'){
		printf("%c",*(destino+tamd));
		tamd++;
	}

	return 0;
}
