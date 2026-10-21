/*bibliotecas necessárias para usar funções de teclado/tela (stdio.h),
 alocação de memória (stdlib.h) e manipulação de texto (string.h).*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Limites definidos para fazer o programa*/
#define MAX_ESTUDANTES 10
#define NUM_NOTAS 3
#define TAM_NOME 50
/*Bloco responsável por ler o nome do estudante com segurança
remove a quebra de linha que o teclado envia
 e garante que o usuário digite um nome válido.*/
 void lerNomeEstudante(char nome[], int tamanhoMaximo) {
    int valido = 0;

    do {
        printf("Digite o nome do estudante: ");
        if (fgets(nome, tamanhoMaximo, stdin) != NULL) {
            /* Remove a quebra de linha do final da palavra lida */
            size_t tam = strlen(nome);
            if (tam > 0 && nome[tam - 1] == '\n') {
                nome[tam - 1] = '\0';
                tam--;
            }

            /* Verifica se o nome não ficou vazio */
            if (tam > 0) {
                valido = 1;
            } else {
                printf("Erro: O nome nao pode ser vazio. Tente novamente.\n");
            }
        }
    } while (!valido);
}

/*Esta função percorre a matriz de notas linha por linha.
 Para cada aluno, ela soma as 3 notas, calcula a média dividindo por 3
  e escreve o resultado diretamente no vetor de médias alocado na memória.
*/
void calcularMedias(float notas[][NUM_NOTAS], int qtdEstudantes, float *medias) {
    for (int i = 0; i < qtdEstudantes; i++) {
        float soma = 0.0f;
        for (int j = 0; j < NUM_NOTAS; j++) {
            soma += notas[i][j];
        }
        /* Guarda a média calculada no vetor dinâmico do chamador */
        medias[i] = soma / NUM_NOTAS;
    }
}

/*Função pra fazer a tabela com nomes, medias e as situações
também mostrando quem obteve a maior media(considera empates)*/
void exibirResumoTurma(char nomes[][TAM_NOME], float notas[][NUM_NOTAS], float *medias, int qtdEstudantes) {
    float somaTotalMedias = 0.0f;
    float maiorMedia = -1.0f;

    printf("\n===============================================================================\n");
    printf("%-20s | %-6s | %-6s | %-6s | %-6s | %-15s\n", "Estudante", "Nota 1", "Nota 2", "Nota 3", "Media", "Situacao");
    printf("===============================================================================\n");

    for (int i = 0; i < qtdEstudantes; i++) {
        somaTotalMedias += medias[i];

        if (medias[i] > maiorMedia) {
            maiorMedia = medias[i];
        }

        /* Aplica a regra do projeto para determinar a situação */
        const char *situacao = (medias[i] >= 6.0f) ? "Atingiu a meta" : "Abaixo da meta";

        printf("%-20s | %6.2f | %6.2f | %6.2f | %6.2f | %-15s\n",
               nomes[i], notas[i][0], notas[i][1], notas[i][2], medias[i], situacao);
    }

    printf("===============================================================================\n");

    /* Média geral da sala */
    float mediaGeral = somaTotalMedias / qtdEstudantes;
    printf("\nMedia geral da turma: %.2f\n", mediaGeral);

    /* Exibe o nome do estudante com a maior média (ou todos em caso de empate) */
    printf("Estudante(s) com a maior media (%.2f):\n", maiorMedia);
    for (int i = 0; i < qtdEstudantes; i++) {
        if (medias[i] == maiorMedia) {
            printf("- %s\n", nomes[i]);
        }
    }
    printf("\n");
}
/*Programa principal que recebe a entrada e valida a quantidade de alunos*/
int main() {
    int qtdEstudantes;

    printf("--- SISTEMA DE BOLETIM ESCOLAR ---\n\n");

    /* Pergunta a quantidade de estudantes e valida o intervalo [1, 10] */
    do {
        printf("Digite a quantidade de estudantes (1 a %d): ", MAX_ESTUDANTES);
        if (scanf("%d", &qtdEstudantes) != 1) {
            while (getchar() != '\n'); /* Limpa o buffer se o usuário digitar letras */
            qtdEstudantes = 0;
        }
        if (qtdEstudantes < 1 || qtdEstudantes > MAX_ESTUDANTES) {
            printf("Quantidade invalida! Por favor, insira um valor entre 1 e %d.\n", MAX_ESTUDANTES);
        }
    } while (qtdEstudantes < 1 || qtdEstudantes > MAX_ESTUDANTES);

    while (getchar() != '\n'); /* Limpa a quebra de linha da entrada */

    /*Criação da matriz de caracteres para nome e a decimal para nota
    em um laço, cadastra o nome do aluno e le as suas 3 notas
    e filtra elas para apenas aceitar de 0 a 10*/
    /* Matrizes principais com capacidade fixa */
    char nomes[MAX_ESTUDANTES][TAM_NOME];
    float notas[MAX_ESTUDANTES][NUM_NOTAS];

    /* Leitura dos dados de cada estudante */
    for (int i = 0; i < qtdEstudantes; i++) {
        printf("\n--- Cadastro do Estudante %d de %d ---\n", i + 1, qtdEstudantes);
        lerNomeEstudante(nomes[i], TAM_NOME);

        for (int j = 0; j < NUM_NOTAS; j++) {
            float notaDigitada;
            int notaValida = 0;

            /* Valida se a nota está no intervalo [0.0, 10.0] */
            do {
                printf("Digite a %dª nota (0.0 a 10.0): ", j + 1);
                if (scanf("%f", &notaDigitada) == 1) {
                    if (notaDigitada >= 0.0f && notaDigitada <= 10.0f) {
                        notas[i][j] = notaDigitada; // Salva na matriz
                        notaValida = 1;
                    } else {
                        printf("Nota invalida! O valor deve estar no intervalo de 0.0 a 10.0.\n");
                    }
                } else {
                    printf("Entrada invalida! Digite um numero decimal.\n");
                    while (getchar() != '\n');
                }
            } while (!notaValida);
        }
        while (getchar() != '\n');
    }
    /*Alocação dinâmica do vetor de medias com calloc,
    ajustado para o numero de alunos informados e verificação para
    ver se a memoria foi alocada corretamente, chama as funções para
    processar e exibir os dados e libera a memoria com free()*/
    /* Alocação dinâmica de memória para guardar o vetor de médias */
    float *medias = (float *)calloc(qtdEstudantes, sizeof(float));

    /* Verificação de segurança da alocação */
    if (medias == NULL) {
        printf("Erro fatal: Falha na alocacao de memoria para o vetor de medias.\n");
        return 1;
    }

    /* Processamento e cálculo das médias via ponteiro */
    calcularMedias(notas, qtdEstudantes, medias);

    /* Chamada da função para imprimir a tabela do boletim */
    exibirResumoTurma(nomes, notas, medias, qtdEstudantes);

    /* Liberação obrigatória da memória alocada dinamicamente */
    free(medias);
    medias = NULL;

    return 0;
}


