#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"

typedef struct curso{
    int codigo;
    Alunos *lista_de_alunos;
    char nome[50];
    int vagas;
    int matriculados;
}Curso;

void LimpaBuffer(void) {
    int valorLido; /* valorLido deve ser int! */
    do {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}

Alunos* realizar_matricula(void){
	  	
		   Alunos* alunos = (Alunos*)malloc(sizeof(Alunos));
		   
		   printf("digite seu nome\n");
		   scanf("%s", alunos->nome);
		   printf("\n");
		   
		   printf("digite sua matricula\n");
		   scanf("%d" , &alunos->matricula);
		   printf("\n");

           printf("digite seu curso\n");
		   scanf("%s" , alunos->curso);
		   printf("\n"); 
		   
		   printf("digite sua nota\n");
		   scanf("%f" , &alunos->notas);
	       printf("\n");
	  
	  	FILE* arq = fopen ("matricula.txt", "a");
	  	 if(arq ==NULL){
        printf("Erro ao abrir o arquivo: ");
        exit(1);
    }
    	 fprintf(arq, "nome: %s\n matricula %d\n nota: %.2f\n\n", alunos->nome, alunos->curso, alunos->matricula, alunos->notas);
    	 
    fclose(arq);
    return alunos;
	}

    void inserir_matricula(Alunos *novo_aluno, Curso *curso){
            
            if(curso->vagas == 0){
                printf("\nNão há mais vagas no curso de %s", curso->nome);              
            }

            if(curso->lista_de_alunos == NULL){
                curso->lista_de_alunos = novo_aluno;
                curso->lista_de_alunos->next = NULL;
                curso->matriculados++;
                curso->vagas--;
            } else if(curso->lista_de_alunos != NULL){
                novo_aluno->next = curso->lista_de_alunos;
                curso->lista_de_alunos = novo_aluno;
                curso->matriculados++;
                curso->vagas--;
            }              
    }
    
int remover(int mat, Curso *c){

    if(c->lista_de_alunos == NULL){
        printf("\nNão existem pessoas matriculadas no curso\n");
        return 0;
    }

    Alunos *i;
    i = c->lista_de_alunos;

    if(i->matricula == mat){
            c->lista_de_alunos = c->lista_de_alunos->next;
            i = NULL;
            c->vagas++;
            c->matriculados--;
            return 1;
        }
    Alunos *a;
    a = c->lista_de_alunos;
    while(i->matricula != mat){

        i = i->next;
        if(i == NULL){
            printf("\nMatricula não encontrada\n\n");
            break;
        }

        if(i->matricula == mat){
            a->next = i->next;
            c->vagas++;
            c->matriculados--;
            i = NULL;
            break;
        }
        a = i;

    }
    return 1;
}

Alunos *busca(int mat, Curso *c){
    if(c->lista_de_alunos == NULL){
        printf("\nNão existem pessoas matriculadas no curso");
    
    }else if(c->lista_de_alunos != NULL){
    Alunos *i = (Alunos*)malloc(sizeof(Alunos));
    i = c->lista_de_alunos;
    while(i->matricula != mat){
        i = i->next;
        if(i == NULL){
            printf("\nMatricula não encontrada\n\n");
            break;
        }
    }
    return i;
}
    
}

int imprime (Curso *c){
    Alunos *aux = c->lista_de_alunos;
if(aux == NULL){
    printf("\nAs matriculas estão vazias\n\n");
    return 0;
}
    while(aux != NULL){
        printf("\nNome: %s\nCurso: %s\nMatricula: %d\nNota: %.2f\n\n", aux->nome, aux->curso, aux->matricula, aux->notas);
        aux = aux->next;
        if(aux == NULL){
            break;
        }
    }
    return 1;
}

int editar(Curso *c){
    int mat;

    printf("\nInsira a matricula a ser editada: ");
    scanf("%i", &mat);

    Alunos *alunos = busca(mat,c);
    if(alunos == NULL){
        return 0;
    }
    printf("\nInsira o dados a serem editados na matricula:");
    printf("\ndigite seu nome:");
		   scanf(" %s", alunos->nome);
		   printf("\n");
		   
		   printf("\ndigite sua matricula:");
		   scanf("%d" , &alunos->matricula);
		   printf("\n");
		   
		   printf("\ndigite o curso que deseja:");
		   scanf(" %s", alunos->curso);
		   printf("\n"); 
		   
		   printf("\ndigite sua nota:");
		   scanf("%f" , &alunos->notas);
	       printf("\n");

    return 1;
    
}