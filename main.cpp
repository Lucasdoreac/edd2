#include <stdio.h>  // Para funções de entrada/saída como printf e scanf
#include <string.h> // Para funções de manipulação de strings como strcmp e strcspn
// Definição de constantes para facilitar a manutenção
#define MAX_NOTAS 3    // Número fixo de notas por aluno, conforme o vídeo no final
#define MAX_NOME 30    // Tamanho máximo do nome do aluno
#define MAX_ALUNOS 100 // Capacidade máxima do vetor de alunos
/*
// Estrutura para Endereço (Desafio/Homework proposto no vídeo)
// Não está totalmente implementada no código principal, mas mostra a ideia.
typedef struct Endereco {
    char logradouro[50];
    char bairro[30];
    char cidade[30];
    char numero[10]; // Número como string para permitir "s/n" ou blocos
    // char cep[10]; // Poderia ser adicionado
} Endereco;
*/
// Estrutura para Aluno
typedef struct Aluno {
    char nome[MAX_NOME];
    int idade;
    float notas[MAX_NOTAS]; // Vetor de notas
    /*
    // Inclusão de endereços como structs aninhadas (Desafio/Homework)
    Endereco residencial;
    Endereco comercial;
    */
} Aluno;
int main() {
    // Declaração de um vetor de estruturas Aluno
    Aluno vetorAluno[MAX_ALUNOS];
    int quantidadeDeAlunos;
    int i, j; // Variáveis de controle de loops
    int posicaoParaImprimir;
    char resposta[5]; // Para armazenar a resposta 's' ou 'n' para continuar
    printf("\n");
    printf(" Exercício utilizando estruturas (struct) em C/C++     \n");
    printf("\n\n");
    // PARTE 1: Capturar a quantidade de alunos (com validação básica)
    do {
        printf("Informe a quantidade de alunos (máximo %d): ", MAX_ALUNOS);
        scanf("%d", &quantidadeDeAlunos);
        // Limpar o buffer de entrada após scanf para consumir o '\n'
        while (getchar() != '\n');
        if (quantidadeDeAlunos <= 0 || quantidadeDeAlunos > MAX_ALUNOS) {
            printf("Quantidade inválida. Digite um valor entre 1 e %d.\n", MAX_ALUNOS);
        }
    } while (quantidadeDeAlunos <= 0 || quantidadeDeAlunos > MAX_ALUNOS);
    printf("\n--- Entrada de Dados dos Alunos ---\n");
    // PARTE 2: Alimentar o vetor de alunos (Entrada de dados)
    for (i = 0; i < quantidadeDeAlunos; i++) {
        printf("\nAluno #%d:\n", i + 1);
        // Nome do aluno (com tratamento para espaços, conforme explicado no vídeo)
        printf("Informe o nome do aluno: ");
        // O espaço antes de %[^\n] consome qualquer whitespace anterior (incluindo \n)
        // %*c consome o caractere de nova linha que fica no buffer
        scanf(" %[^\n]%*c", vetorAluno[i].nome);
        // Idade do aluno
        printf("Informe a idade de %s: ", vetorAluno[i].nome);
        scanf("%d", &vetorAluno[i].idade);
        while (getchar() != '\n'); // Limpar o buffer
        // Notas do aluno (vetor de notas dentro da struct Aluno)
        for (j = 0; j < MAX_NOTAS; j++) {
            printf("Informe a %da nota de %s: ", j + 1, vetorAluno[i].nome);
            scanf("%f", &vetorAluno[i].notas[j]);
            while (getchar() != '\n'); // Limpar o buffer
        }
        /*
        // --- Entrada de dados para Endereço (Desafio/Homework) ---
        // Exemplo:
        // printf("Informe o Logradouro Residencial: ");
        // scanf(" %[^\n]%*c", vetorAluno[i].residencial.logradouro);
        // ... e assim por diante para todos os campos dos endereços
        */
    }
    printf("\n--- Consulta de Registros dos Alunos ---\n");
    // PARTE 3: Resgatar e imprimir os dados (Saída de dados)
    do {
        printf("\nInforme a posição (índice) do registro a imprimir (1 a %d): ", quantidadeDeAlunos);
        scanf("%d", &posicaoParaImprimir);
        while (getchar() != '\n'); // Limpar o buffer
        // Ajustar para índice base 0, já que arrays em C começam em 0
        int indiceReal = posicaoParaImprimir - 1;
        if (indiceReal >= 0 && indiceReal < quantidadeDeAlunos) {
            printf("\n--- Dados do Aluno #%d ---\n", posicaoParaImprimir);
            printf("Nome: %s\n", vetorAluno[indiceReal].nome);
            printf("Idade: %d\n", vetorAluno[indiceReal].idade);
            printf("Notas:\n");
            for (j = 0; j < MAX_NOTAS; j++) {
                printf("  Nota %d: %.2f\n", j + 1, vetorAluno[indiceReal].notas[j]);
            }
            /*
            // --- Saída de dados para Endereço (Desafio/Homework) ---
            // Exemplo:
            // printf("\nEndereço Residencial:\n");
            // printf("  Logradouro: %s\n", vetorAluno[indiceReal].residencial.logradouro);
            // printf("  Bairro: %s\n", vetorAluno[indiceReal].residencial.bairro);
            // printf("  Cidade: %s\n", vetorAluno[indiceReal].residencial.cidade);
            // printf("  Número: %s\n", vetorAluno[indiceReal].residencial.numero);
            // printf("\nEndereço Comercial:\n");
            // ...
            */
        } else {
            printf("Posição inválida. Digite um número entre 1 e %d.\n", quantidadeDeAlunos);
        }
        // Pergunta se deseja imprimir outro registro
        printf("\nDeseja imprimir outro registro? (S/N): ");
        scanf(" %4s", resposta); // O espaço inicial consome o '\n' pendente
        while (getchar() != '\n'); // Limpar o buffer restante
    } while (strcmp(resposta, "s") == 0 || strcmp(resposta, "S") == 0);
    printf("\nPrograma finalizado. Até mais!\n");
    return 0;
}
