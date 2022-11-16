#include<stdio.h>
#include<stdlib.h>
#include "alunos.h"


	typedef struct alunos{
		char nome[100];
		int matricula;
		char curso[100];
		float notas;		
	}Alunos;

    typedef struct lista{
	int info;
	struct lista*next;
}Lista;


Lista* lista_cria(void){
	return NULL;
}
	 
	  Alunos* realizar_matricula(void){
	  	
		   Alunos* alunos = (Alunos*)malloc(sizeof(Alunos));
		   
		   printf("digite seu nome\n");
		   scanf("%s", alunos->nome);
		   printf("\n");
		   
		   printf("digite sua matricula\n");
		   scanf("%d" ,& alunos->matricula);
		   printf("\n");
		   
		   printf("digite o curso que deseja\n");
		   scanf("%s", alunos->curso);
		   printf("\n");
		   
		   printf("digite sua nota\n");
		   scanf("%f" ,& alunos->notas);
	       printf("\n");
	  
	  	FILE* arq = fopen ("matricula.txt", "a");
	  	 if(arq ==NULL){
        printf("Erro ao abrir o arquivo: ");
        exit(1);
    }
    	 fprintf(arq, "nome: %s\n curso: %s\n matricula %d\n nota: %f\n\n", alunos->nome, alunos->curso, alunos->matricula, alunos->notas);
    	 
    fclose(arq);
    return alunos;
	}

	 Lista* inserir_matricula(Lista* Lista_matricula, Alunos* nome){

    Lista* nova_matricula = (Lista*)malloc(sizeof(Lista));
    nova_matricula->info = nome;
    nova_matricula->next = Lista_matricula;
    return nova_matricula;
}

/*função para o contador percorrer a todos os nos da lista e passar a info como pararametro para exibir
a lista*/
Lista* Lista_listar(Lista* lista_matricula){
    Lista*contador;
    for(contador=lista_matricula; contador!=NULL; contador=contador->next){
        printf("----matricula----\n");

        exibe_matricula(contador->info);
        
        printf("----------------\n");
       
    }
}

/* função para exibir os elementos da matricula */

Lista* exibe_matricula(Alunos* Lista_matricula){

    FILE* arq = fopen ("matricula.txt", "r");

	fprintf(arq, "nome: %s\n curso: %s\n matricula: %d\n nota: %f\n\n",
	Lista_matricula->nome, Lista_matricula->curso, Lista_matricula->matricula, Lista_matricula->notas);
    
	fclose(arq);

	return alunos;
}

    void lst_listar(Lista* Lista_matricula){
		Lista*contador;
		for(contador=Lista_matricula; contador!=NULL; contador=contador->next){
			printf("Matricula\n");
			exibe_matricula(contador->info);
			printf("------------\n");
		}
	}

	Lista* lista_busca(Lista* Lista_matricula){

		char
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
