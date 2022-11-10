#include<stdio.h>
#include<stdlib.h>
#include "alunos.h"


	struct alunos{
		char nome[100];
		int matricula;
		char curso[100];
		float notas;		
	};
	
	struct lista{
		Alunos* info;
		struct lista* next;
	};
	
	Lista* lista_cria(){
		return NULL;
	}
	 
	  Alunos* realizar_matricula(void){
	  	
		   Alunos* alunos = (Alunos*)malloc(sizeof(Alunos));
		   
		   printf("digite seu nome\n");
		   scanf("%[^\n]", alunos->nome);
		   printf("\n");
		   
		   printf("digite sua matricula\n");
		   scanf("%d" ,& alunos->matricula);
		   printf("\n");
		   
		   printf("digite o curso que deseja\n");
		   scanf("%[^\n]", alunos->curso);
		   printf("\n");
		   
		   printf("digite sua nota\n");
		   scanf("%f" ,& alunos->notas);
	       printf("\n");
	  
	  	FILE* arquivo = fopen ("matricula.txt", "a");
	  	 if(arquivo ==NULL){
        printf("Erro ao abrir o arquivo: ");
        exit(1);
    }
    	 fprintf(arquivo, "nome: %s\n curso: %s\n matricula %d\n nota: %f\n\n", alunos->nome, alunos->curso, alunos->matricula, alunos->notas);
    	 
    fclose(arquivo);
    return alunos;
}

	  /*Alunos* excluir_matricula(void){
	  	
		   Alunos* alunos = (Alunos*)malloc(sizeof(Alunos));
		   
		   printf("digite o nome\n");
		   scanf("%[^\n]", alunos->nome);
		   
		   printf("digite a matricula\n");
		   scanf("%d" & alunos->matricula);
		   
		   printf("digite o curso que deseja\n");
		   scanf("%[^\n]" alunos->curso);
		   
	  
	  
	  	FILE* arquivo = fopen ("matricula.txt", "a");
	  	 if(arquivo ==NULL){
        printf("Erro ao abrir o arquivo: ");
        exit(1);
    }
    	 fprintf(arquivo, "Nome: %s\nCurso: %s\nmatricula %d\nNota: %f\n", alunos->nome, alunos->curso, alunos->matricula, alunos->notas);
    	 
    fclose(arquivo);
    return alunos;
}
*/
