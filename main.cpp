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
