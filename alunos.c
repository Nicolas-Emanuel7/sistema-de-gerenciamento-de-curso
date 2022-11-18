#include <stdio.h>
#include <stdlib.h>

typedef	struct alunos{
		char nome[100];
		int matricula;
		char curso[100];
		float notas;
		struct alunos *next;		
	}Alunos;