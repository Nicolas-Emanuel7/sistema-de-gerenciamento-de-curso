#ifndef CURSO.H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alunos.h"

 Lista* lista_cria();

 Alunos* realizar_matricula(void);

 Lista* inserir_matricula(Lista* Lista_matricula, Alunos* nome);

 void exibe_matricula(Alunos* Lista_matricula);

#endif