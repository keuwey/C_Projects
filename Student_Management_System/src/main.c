#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char cpf[12];
    int matricula;
    char nome[60];
    int idade;
    char curso[50];
} Aluno;

char arquivo[12] = "arquivo.txt";

int cadastrarAluno(const Aluno *a) {
    FILE *pont_arq = fopen(arquivo, "a");
    if (!pont_arq) return 1;
    fprintf(pont_arq, "%s,%d,%s,%d,%s\n", a->cpf, a->matricula, a->nome, a->idade, a->curso);
    fclose(pont_arq);
    return 0;
}

int listarAluno(int matricula) {
    FILE *pont_arq = fopen(arquivo, "r");
    if (!pont_arq) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }
    char linha[256];
    int encontrado = 0;

    while (fgets(linha, sizeof(linha), pont_arq)) {
        Aluno a;
        if (sscanf(linha, "%11[^,],%d,%59[^,],%d,%49[^\n]", a.cpf, &a.matricula, a.nome, &a.idade, a.curso) ==
            5) {
            if (a.matricula == matricula) {
                printf("\nAluno encontrado:\n");
                printf("CPF: %s\n", a.cpf);
                printf("Matrícula: %d\n", a.matricula);
                printf("Nome: %s\n", a.nome);
                printf("Idade: %d\n", a.idade);
                printf("Curso: %s\n\n", a.curso);
                encontrado = 1;
                break;
            }
        }
    }

    if (!encontrado) {
        printf("Aluno com matrícula %d não encontrado.\n", matricula);
    }

    fclose(pont_arq);
    return 0;
}

int main() {
    int escolha;
    char buffer[128];

    while (1) {
        printf("O que deseja?\n\n");
        printf("cadastrar aluno: 1\n");
        printf("Listar aluno: 2\n");
        printf("Sair: 3\n");
        if (!fgets(buffer, sizeof buffer, stdin)) break;
        escolha = atoi(buffer);

        switch (escolha) {
            case 1:
                Aluno aluno = {0};

                printf("CPF (somente numeros): ");
                if (fgets(buffer, sizeof buffer, stdin)) {
                    buffer[strcspn(buffer, "\n")] = '\0';
                    strncpy(aluno.cpf, buffer, sizeof aluno.cpf - 1);
                    aluno.cpf[sizeof aluno.cpf - 1] = '\0';
                }

                printf("Matrícula: ");
                if (fgets(buffer, sizeof buffer, stdin)) aluno.matricula = atoi(buffer);

                printf("Nome: ");
                if (fgets(buffer, sizeof buffer, stdin)) {
                    buffer[strcspn(buffer, "\n")] = '\0';
                    strncpy(aluno.nome, buffer, sizeof aluno.nome - 1);
                    aluno.nome[sizeof aluno.nome - 1] = '\0';
                }

                printf("Idade: ");
                if (fgets(buffer, sizeof buffer, stdin)) aluno.idade = atoi(buffer);

                printf("Curso: ");
                if (fgets(buffer, sizeof buffer, stdin)) {
                    buffer[strcspn(buffer, "\n")] = '\0';
                    strncpy(aluno.curso, buffer, sizeof aluno.curso - 1);
                    aluno.curso[sizeof aluno.curso - 1] = '\0';
                }

                if (cadastrarAluno(&aluno) != 0) {
                    printf("Erro ao cadastrar aluno.\n");
                    return 1;
                }

                printf("Aluno cadastrado com sucesso.\n");

                break;

            case 2:
                int matricula;
                printf("Digite a matricula para a busca:\n");
                if (fgets(buffer, sizeof buffer, stdin)) matricula = atoi(buffer);
                listarAluno(matricula);
                break;

            case 3:
                return 0;
        }
    }

    return 0;
}