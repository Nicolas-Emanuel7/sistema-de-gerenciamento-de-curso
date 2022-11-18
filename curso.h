#include "curso.c"

typedef struct curso Curso;
Alunos* realizar_matricula(void);
void inserir_matricula(Alunos aluno, Curso lista);
int editar(Curso *c);
Alunos *busca(int mat, Curso *c);
int remover(int mat, Curso *c);
int imprime (Curso *c);