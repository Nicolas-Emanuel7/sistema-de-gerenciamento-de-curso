#ifndef CURSO.H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 typedef struct alunos Alunos;
 
 typedef struct lista Lista;
 
 Lista* lista_cria();

 void lista_imprime(Lista*l);

 Lista* lista_insere(Lista* l, Alunos a);

 Lista* lista_retira(Lista* l, Alunos a)

 Lista * lista_busca(Alunos elemento, Lista* l)
 
 Alunos* realizar_matricula(void);

#endif