#include <stdio.h>
#include <stdarg.h>
#include <windows.h>
#include "alunos.c"

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


void LimpaBuffer(void) {
    int valorLido; /* valorLido deve ser int! */
    do {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}

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
    Lista* Lista_matricula = NULL;
    int 

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
                Alunos* alunos = realizar_matricula();
                inserir_matricula(Lista_matricula, alunos );
                break;

            /*case OPCAO2:
                Beep(1000,500);
                Lista* lista_retira(Lista* l, Alunos a)
                
                break; 

            case OPCAO3:
                Beep(1000,500);

                Lista_listar(Lista* lista_matricula);
                
                break;

            case OPCAO4:
                Beep(1000,500);
                
                break;
                
            case OPCAO5:
                Beep(1000,500);
                
                break;
                
            case OPCAO6:
                Beep(1000,500);
                
                break;
                
            case OPCAO7:
                Beep(1000,500);
                
                break;
			*/
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
