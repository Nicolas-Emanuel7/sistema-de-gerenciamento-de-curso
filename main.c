#include <stdio.h>
#include <stdarg.h>
#include <windows.h>
#include "curso.h"
#include "locale.h"

#define TITULO_OPCAO1 "Realizar Matricula"
#define TITULO_OPCAO2 "Excluir Matricula"
#define TITULO_OPCAO3 "Listar Matriculados"
#define TITULO_OPCAO4 "Buscar curso"
#define TITULO_OPCAO5 "Editar Matricula"
#define TITULO_OPCAO6 "Consultar vagas disponiveis para um curso"
#define TITULO_OPCAO7 "Consultar quantitativo de alunos em um curso"
#define TITULO_OPCAO8 "Sair"

#define N_OPCOES 8
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'
#define OPCAO8 '8'

int LeOpcao(int menorValor, int maiorValor) {
    int op;
    while (1) {
        printf("\nDigite sua opcao: ");
        op = getchar();
        if (op >= menorValor && op <= maiorValor) {
            LimpaBuffer();
            break;
        }
        else {
            printf("\nOpcao invalida. Tente novamente.");
            printf("\nA opcao deve estar entre %c e %c. \n",
                   menorValor, maiorValor);
            LimpaBuffer();
        }
    }
    return op;
}


void ApresentaMenu(int nItens, int menorOpcao, ...) {
    int i;
    va_list argumentos;
    /* Inicia lista de argumentos vari�veis */
    va_start(argumentos, menorOpcao);

    for(i = 0; i < nItens; ++i) {
        printf("%c-%s\n", menorOpcao++, va_arg(argumentos, char *));
    }
    va_end(argumentos);/* Encerra processamento de argumentos */
}

int main(void) {
    unsigned char op;
    setlocale(LC_ALL,"");
    Curso bti = (Curso)malloc(sizeof(Curso));
    Curso cet = (Curso)malloc(sizeof(Curso));
    bti->lista_de_alunos = NULL;
    cet->lista_de_alunos = NULL;
    
    bti->codigo = 28091;
    bti->matriculados = 0;
    bti->vagas = 50;
    strcpy(bti->nome,"bti");
    cet->codigo = 29091;
    cet->matriculados = 0;
    cet->vagas = 80;
    strcpy(cet->nome,"cet");
    unsigned int saida = 0;

    do {
        ApresentaMenu(N_OPCOES, OPCAO1,
                      TITULO_OPCAO1, TITULO_OPCAO2,
                      TITULO_OPCAO3, TITULO_OPCAO4,
					  TITULO_OPCAO5, TITULO_OPCAO6,
					  TITULO_OPCAO7, TITULO_OPCAO8);
        op = LeOpcao(OPCAO1, OPCAO1 + N_OPCOES - 1);
        switch(op) {
            case OPCAO1:
                Beep(1000,500); /* Emite um beep */
                int option;
                Alunos* alunos;
                printf("\nQual curso será realizado a matricula?");
                printf("\n 1 - bti \n 2 - cet\n");
                scanf("%i", &option);
                if(option == 1){

                alunos = realizar_matricula();
                inserir_matricula(alunos,bti);

                } else if (option == 2){

                alunos = realizar_matricula();
                inserir_matricula(alunos,cet);

                }
                
                break;

            case OPCAO2:
                Beep(1000,500);
                int mat;
                printf("\nInsira uma matricula a ser removida: ");
                scanf("%i", &mat);
                printf("\nEm qual curso desejar realizar a remoção?");
                
                printf("\n1 - bti \n2 - cet\n");
                
                scanf("%i", &option);
                if(option == 1){
                    
                    if(remover(mat,bti)){
                
                printf("\nRemovido com sucesso!\n");
                    }
                } else if (option == 2){

                if(remover(mat,cet)){
                
                printf("\nRemovido com sucesso!\n");
                    }
                }
                
                
                break; 

            case OPCAO3:
            Beep(1000,500);
               printf("\nEm qual curso desejar realizar a listagem?");
                
                printf("\n1 - bti \n2 - cet\n");
                
                scanf("%i", &option);
                if(option == 1){

                imprime(bti);
                } else if (option == 2){

                imprime(cet);
                
                }
                
                break;

            case OPCAO4:
                Beep(1000,500);
                

                printf("\nInsira uma matricula a ser buscada: ");
                scanf("%i", &mat);
                printf("\nEm qual curso desejar realizar a busca?");
                
                printf("\n 1 - bti \n 2 - cet\n");
                
                scanf("%i", &option);
                if(option == 1){

                alunos = busca(mat,bti);

                if(alunos != NULL){
                printf("\nAluno encontrado\n");
                printf("\nNome: %s\n Curso: %s\n Matricula %d\n Nota: %.2f\n\n", alunos->nome, alunos->curso, alunos->matricula, alunos->notas);
                    }
                } else if (option == 2){

                alunos = busca(mat,cet);

                if(alunos != NULL){
                printf("\nAluno encontrado\n");
                printf("\nNome: %s\n Curso: %s\n Matricula %d\n Nota: %.2f\n\n", alunos->nome, alunos->curso, alunos->matricula, alunos->notas);
                        }
                    }

                break;
                
            case OPCAO5:
                Beep(1000,500);
                 
                printf("\nEm qual curso desejar realizar a edição?");
                
                printf("\n 1 - bti \n 2 - cet\n");
                
                scanf("%i", &option);
                if(option == 1){
                
                editar(bti);
                printf("\nMatricula editada com sucesso!\n\n");
                } else if (option == 2){

                editar(cet);
                printf("\nMatricula editada com sucesso!\n\n");

                }
                break;
                
            case OPCAO6:
                Beep(1000,500);
                printf("\nEm qual curso desejar verificar as vagas disponiveis?");
                
                printf("\n 1 - bti \n 2 - cet\n");
                
                scanf("%i", &option);
                if(option == 1){
                
                printf("\nQuantidade de vagas disponiveis em %s: %i\n\n",bti->nome, bti->vagas);
                } else if (option == 2){

                printf("\nQuantidade de vagas disponiveis em %s: %i\n\n",cet->nome, cet->vagas);

                }
                break;
                
            case OPCAO7:
               Beep(1000,500);
                printf("\nEm qual curso desejar verificar a quantidade de alunos?");
                
                printf("\n 1 - bti \n 2 - cet\n");
                
                scanf("%i", &option);
                if(option == 1){
                
                printf("\nQuantidade de alunos em %s: %i\n\n",bti->nome, bti->matriculados);
                } else if (option == 2){

                printf("\nQuantidade de alunos em %s: %i\n\n",cet->nome, cet->matriculados);

                }
                break;
			
			case OPCAO8:
                Beep(1000,500);
                saida = 1;
                printf("Obrigado por usar este programa.");
                break; 

            default:
                printf("Este programa possui um bug.");
                return 1;
        }
    } while(!saida);
    return 0;
}
