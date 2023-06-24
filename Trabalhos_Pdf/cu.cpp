#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct{

    int dia, mes, ano;

}Data;

typedef struct{

    Data nasc;

    char nome[40];
    char curso[40];
    int idade;
    double notas[2];

}Aluno;

int main(){


        int discentes, i, j;

        printf("Digite o número de discentes: ");
        scanf("%d", &discentes);

        Aluno Alunos[discentes];

        for(i=0;i<discentes;i++){


            printf("\nDigite o nome do ALUNO(A) [%d]: ", i+1);
            fflush(stdin);
            fgets (Alunos[i].nome,100,stdin);
            
            printf("Digite o curso do ALUNO(A) [%d]: ", i+1);
            fflush(stdin);
            fgets (Alunos[i].nome,100,stdin);

            printf("Digite a idade do ALUNO(A) [%d]: ", i+1);
            fflush(stdin);
            scanf("%d", &Alunos[i].idade);

            for(j=0;j<=2;j++){


                printf("Digite a nota %d do ALUNO(A) [%d]: ", j+1, i+1);
                scanf("%d", &Alunos[i].notas[j]);

            }

            printf("Digite a data de nascimento do ALUNO(A) [%d] no formato dd mm aaaa:", i+1);
            scanf("%d %d %d", &Alunos[i].nasc.dia, &Alunos[i].nasc.mes, &Alunos[i].nasc.ano);

        }


	return 0;

}
