#ifndef ALUNOS_H
#define ALUNOS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 typedef struct alunos Alunos;
 
 typedef struct lista Lista;
 
 Lista* lista_cria();

 Alunos* realizar_matricula(void);

 Lista* inserir_matricula(Lista* Lista_matricula, Alunos* nome);

#endif