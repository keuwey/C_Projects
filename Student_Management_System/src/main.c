#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char cpf[12];   // ID
    int matricula;  // Registration Number
    char nome[60];  // Name
    int idade;      // Age
    char curso[50]; // Course Name
} Student;

char file[9] = "file.txt";

int registerStudent(const Student *student) {
    FILE *file_ptr = fopen(file, "a");
    if (!file_ptr) return 1;
    fprintf(file_ptr, "%s,%d,%s,%d,%s\n", student->cpf, student->matricula, student->nome, student->idade, student->curso);
    fclose(file_ptr);
    return 0;
}

int listStudent(int matricula) {
    FILE *file_ptr = fopen(file, "r");
    if (!file_ptr) {
        printf("Could not open file.\n");
        return 1;
    }
    char line[256];
    int found = 0;

    while (fgets(line, sizeof(line), file_ptr)) {
        Student student;
        if (sscanf(line, "%11[^,],%d,%59[^,],%d,%49[^\n]", student.cpf, &student.matricula, student.nome,
                   &student.idade, student.curso) == 5) {
            if (student.matricula == matricula) {
                printf("\nStudent found:\n");
                printf("CPF: %s\n", student.cpf);
                printf("Registration Number: %d\n", student.matricula);
                printf("Name: %s\n", student.nome);
                printf("Age: %d\n", student.idade);
                printf("Course: %s\n\n", student.curso);
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("Student with the registration number %d not found.\n", matricula);
    }

    fclose(file_ptr);
    return 0;
}

int main() {
    int choice;
    char buffer[128];

    while (1) {
        printf("What do you want?\n\n");
        printf("Register a student: 1\n");
        printf("List a student: 2\n");
        printf("Exit: 3\n");
        if (!fgets(buffer, sizeof buffer, stdin)) break;
        choice = atoi(buffer);

        switch (choice) {
            case 1:
                Student student = {0};

                printf("CPF (Only numbers): ");
                if (fgets(buffer, sizeof buffer, stdin)) {
                    buffer[strcspn(buffer, "\n")] = '\0';
                    strncpy(student.cpf, buffer, sizeof student.cpf - 1);
                    student.cpf[sizeof student.cpf - 1] = '\0';
                }

                printf("Registration number: ");
                if (fgets(buffer, sizeof buffer, stdin)) student.matricula = atoi(buffer);

                printf("Name: ");
                if (fgets(buffer, sizeof buffer, stdin)) {
                    buffer[strcspn(buffer, "\n")] = '\0';
                    strncpy(student.nome, buffer, sizeof student.nome - 1);
                    student.nome[sizeof student.nome - 1] = '\0';
                }

                printf("Age: ");
                if (fgets(buffer, sizeof buffer, stdin)) student.idade = atoi(buffer);

                printf("Course name: ");
                if (fgets(buffer, sizeof buffer, stdin)) {
                    buffer[strcspn(buffer, "\n")] = '\0';
                    strncpy(student.curso, buffer, sizeof student.curso - 1);
                    student.curso[sizeof student.curso - 1] = '\0';
                }

                if (registerStudent(&student) != 0) {
                    printf("Error registering student.\n");
                    return 1;
                }

                printf("Student successfully registered.\n");

                break;

            case 2:
                int matricula;
                printf("Enter the registration number to search:\n");
                if (fgets(buffer, sizeof buffer, stdin)) matricula = atoi(buffer);
                listStudent(matricula);
                break;

            case 3:
                return 0;
        }
    }

    return 0;
}