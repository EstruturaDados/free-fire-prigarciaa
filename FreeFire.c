#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.

    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.

// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.

#define MAX_ITENS 10

// Estrutura que representa um item da mochila
struct Item {
    char nome[50];
    char tipo[30];
    int quantidade;
};

int main() {
    struct Item mochila[MAX_ITENS];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n===== MOCHILA DO SOBREVIVENTE – NIVEL NOVATO/ AVENTUREIRO =====\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item pelo nome\n");
        printf("5. Atualizar a quantidade de um item\n");
        printf("6. Mostrar total geral de itens\n");
        printf("7. Limpar mochila\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

        // ADICIONAR ITEM
        case 1:
            if (totalItens >= MAX_ITENS) {
                printf("\n Mochila cheia! Não eh possivel adicionar mais itens.\n");
            } else {
                printf("\n--- Adicionando novo item ---\n");
                printf("Nome do item: ");
                scanf(" %49[^\n]", mochila[totalItens].nome);

                printf("Tipo do item: ");
                scanf(" %29[^\n]", mochila[totalItens].tipo);

                printf("Quantidade: ");
                scanf("%d", &mochila[totalItens].quantidade);

                totalItens++;
                printf("\n Item adicionado com sucesso!\n");
            }
            break;

        // REMOVER ITEM
        case 2:
            if (totalItens == 0) {
                printf("\n A mochila está vazia! Nada para remover.\n");
            } else {
                char nomeRemover[50];
                int encontrado = 0;

                printf("\nNome do item a remover: ");
                scanf(" %49[^\n]", nomeRemover);

                for (int i = 0; i < totalItens; i++) {
                    if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                        // Substitui o item removido pelo último da lista
                        mochila[i] = mochila[totalItens - 1];
                        totalItens--;
                        encontrado = 1;
                        printf("\n Item removido com sucesso!\n");
                        break;
                    }
                }

                if (!encontrado) {
                    printf("\n Item não encontrado!\n");
                }
            }
            break;

        // LISTAR ITENS
        case 3:
            if (totalItens == 0) {
                printf("\n A mochila esta vazia!\n");
            } else {
                printf("\n===== ITENS NA MOCHILA =====\n");
                printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
                printf("---------------------------------------------\n");
                for (int i = 0; i < totalItens; i++) {
                    printf("%-20s %-15s %-10d\n",
                           mochila[i].nome,
                           mochila[i].tipo,
                           mochila[i].quantidade);
                }
            }
            break;

        // BUSCAR ITEM PELO NOME
        case 4:
               if (totalItens == 0) {
                printf("\n Mochila vazia! Nada para buscar.\n");
            } else {
                char nomeBusca[50];
                int achou = 0;

                printf("\nDigite o nome do item para buscar: ");
                scanf(" %49[^\n]", nomeBusca);

                for (int i = 0; i < totalItens; i++) {
                    if (strcmp(mochila[i].nome, nomeBusca) == 0) {
                        printf("\n Item encontrado!\n");
                        printf("Nome: %s\n", mochila[i].nome);
                        printf("Tipo: %s\n", mochila[i].tipo);
                        printf("Quantidade: %d\n", mochila[i].quantidade);
                        achou = 1;
                        break;
                    }
                }

                if (!achou)
                    printf("\n Item nao encontrado!\n");
            }
            break;

        // ATUALIZAR QUANTIDADE
        case 5:
            if (totalItens == 0) {
                printf("\n Não ha itens para atualizar.\n");
            } else {
                char nomeAtualizar[50];
                int achou = 0;

                printf("\nDigite o nome do item para atualizar: ");
                scanf(" %49[^\n]", nomeAtualizar);

                for (int i = 0; i < totalItens; i++) {
                    if (strcmp(mochila[i].nome, nomeAtualizar) == 0) {
                        printf("Nova quantidade: ");
                        scanf("%d", &mochila[i].quantidade);
                        printf("\n Quantidade atualizada com sucesso!\n");
                        achou = 1;
                        break;
                    }
                }

                if (!achou)
                    printf("\n Item nao encontrado!\n");
            }
            break;

        // TOTAL GERAL DE ITENS
        case 6: {
            int soma = 0;
            for (int i = 0; i < totalItens; i++)
                soma += mochila[i].quantidade;

            printf("\n Total geral de itens na mochila: %d\n", soma);
            break;
        }

        // LIMPAR MOCHILA
        case 7:
            totalItens = 0;
            printf("\n Mochila limpa com sucesso!\n");
            break;

        // SAIR
        case 8:
            printf("\nEncerrando o programa...\n");
            break;

        default:
            printf("\n Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 8);

    return 0;
}
