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

// Enum de raridade
typedef enum {
    COMUM = 0,
    INCOMUM,
    RARO,
    EPICO,
    LENDARIO
} Raridade;


// Estrutura que representa um item da mochila
struct Item {
    char nome[50];
    char tipo[30];
    int quantidade;
    Raridade raridade;
};

// Função para exibir raridade como texto
const char* textoRaridade(int r) {
    switch (r) {
        case COMUM: return "Comum";
        case INCOMUM: return "Incomum";
        case RARO: return "Raro";
        case EPICO: return "Epico";
        case LENDARIO: return "Lendario";
        default: return "Desconhecido";
    }
}

// Função de ordenação por nome
void ordenarPorNome(struct Item mochila[], int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (strcmp(mochila[j].nome, mochila[j + 1].nome) > 0) {
                struct Item temp = mochila[j];
                mochila[j] = mochila[j + 1];
                mochila[j + 1] = temp;
            }
        }
    }
}

// Função de ordenação por tipo
void ordenarPorTipo(struct Item mochila[], int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (strcmp(mochila[j].tipo, mochila[j + 1].tipo) > 0) {
                struct Item temp = mochila[j];
                mochila[j] = mochila[j + 1];
                mochila[j + 1] = temp;
            }
        }
    }
}


int main() {
    struct Item mochila[MAX_ITENS];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n===== MOCHILA DO SOBREVIVENTE – NIVEL NOVATO, AVENTUREIRO E MESTRE =====\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item pelo nome\n");
        printf("5. Atualizar a quantidade de um item\n");
        printf("6. Mostrar total geral de itens\n");
        printf("7. Limpar mochila\n");
        printf("8. Ordenar por nome\n");
        printf("9. Ordenar por tipo\n");
        printf("10. Filtrar por raridade\n");
        printf("11. Salvar mochila em arquivo\n");
        printf("12. Carregar mochila do arquivo\n");
        printf("13. Sair\n");
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

                printf("Raridade (0-Comum, 1-Incomum, 2-Raro, 3-Epico, 4-Lendario): ");
                scanf("%d", (int*)&mochila[totalItens].raridade);

                totalItens++;
                printf("\n Item adicionado com sucesso!\n");
            }
            break;

        // REMOVER ITEM
        case 2: {
            char nome[50];
            printf("\nNome do item a remover: ");
            scanf(" %49[^\n]", nome);

            int achou = 0;
            for (int i = 0; i < totalItens; i++) {
                if (strcmp(mochila[i].nome, nome) == 0) {
                    mochila[i] = mochila[totalItens - 1];
                    totalItens--;
                    achou = 1;
                    printf("Item removido!\n");
                    break;
                }
            }

            if (!achou)
                printf("Item não encontrado!\n");

            break;
        }
            
        // LISTAR ITENS
        case 3:
    if (totalItens == 0) {
        printf("\n A mochila está vazia!\n");
    } else {
        printf("\n===== ITENS NA MOCHILA =====\n");
        printf("%-20s %-15s %-12s %-10s\n",
               "Nome", "Tipo", "Quantidade", "Raridade");
        printf("---------------------------------------------------------\n");

        for (int i = 0; i < totalItens; i++) {
            printf("%-20s %-15s %-12d %-10s\n",
                   mochila[i].nome,
                   mochila[i].tipo,
                   mochila[i].quantidade,
                   textoRaridade(mochila[i].raridade));
        }
    }
    break;

        // BUSCAR ITEM PELO NOME
        case 4: {
            char nome[50];
            printf("\nDigite o nome do item para buscar: ");
            scanf(" %49[^\n]", nome);
               

            int achou = 0;
            for (int i = 0; i < totalItens; i++) {
                    if (strcmp(mochila[i].nome, nome) == 0) {
                        printf("\nItem encontrado!\n");
                        printf("Nome: %s\n", mochila[i].nome);
                        printf("Tipo: %s\n", mochila[i].tipo);
                        printf("Quantidade: %d\n", mochila[i].quantidade);
                        printf("Raridade: %s\n", textoRaridade(mochila[i].raridade));
                        achou = 1;
                        break;
                    }
                }

                if (!achou)
                    printf("\n Item nao encontrado!\n");
            }
            break;

        // ATUALIZAR QUANTIDADE
        case 5: {
            char nome[50];
            printf("\nNome do item: ");
            scanf(" %49[^\n]", nome);
            
            int achou = 0;
            for (int i = 0; i < totalItens; i++) {
                if (strcmp(mochila[i].nome, nome) == 0) {
                        printf("Nova quantidade: ");
                        scanf("%d", &mochila[i].quantidade);
                        printf("\n Quantidade atualizada com sucesso!\n");
                        achou = 1;
                        break;
                    }
                }
                if (!achou)
                    printf("\n Item nao encontrado!\n");
            
            break;
        }

        // TOTAL GERAL DE ITENS
        case 6: {
            int soma = 0;
            for (int i = 0; i < totalItens; i++)
                soma += mochila[i].quantidade;

            printf("\n Total geral de itens na mochila: %d itens\n", soma);
            break;
        }

        // LIMPAR MOCHILA
        case 7:
            totalItens = 0;
            printf("\n Mochila limpa com sucesso!\n");
            break;

        // ORDENAR POR NOME
        case 8:
            ordenarPorNome(mochila, totalItens);
            printf("\nOrdenado por nome!\n");
            break;
        
        // ORDENAR POR TIPO
        case 9: 
            ordenarPorTipo(mochila, totalItens);
            printf("\nOrdenar por tipo!\n");
            break;
        
        // FILTRAR POR RARIDADE
        case 10: {
            int raridadeEscolhida;

            printf("\nEscolha uma raridade (0 a 4): ");
            scanf("%d", &raridadeEscolhida);

            printf("\nItens da raridade %s:\n", textoRaridade(raridadeEscolhida));

            for (int indiceItem = 0; indiceItem < totalItens; indiceItem++) {
                if (mochila[indiceItem].raridade == raridadeEscolhida) {
                    printf("- %s (%s) x%d\n",
                            mochila[indiceItem].nome,
                            mochila[indiceItem].tipo,
                            mochila[indiceItem].quantidade);
                }
            }
            break;
        }   
        
        // SALVAR EM ARQUIVO
        case 11: {
            FILE *arquivoMochila = fopen("mochila.txt", "w");
            if (!arquivoMochila) {
                printf("Erro ao criar arquivo!\n");
                break;
            }

            fprintf(arquivoMochila, "%d\n", totalItens);

            for (int indiceItem = 0; indiceItem < totalItens; indiceItem++) {
                fprintf(arquivoMochila, "%s;%s;%d;%d\n",
                        mochila[indiceItem].nome,
                        mochila[indiceItem].tipo,
                        mochila[indiceItem].quantidade,
                        mochila[indiceItem].raridade);                      
            }

            fclose(arquivoMochila);
            printf("\nArquivo salvo com sucesso!\n");
            break;
        }
        
        // CARREGAR EM ARQUIVO
        case 12: {
            FILE *arquivoMochila = fopen("mochila.text", "r");
            if (!arquivoMochila) {
                printf("Arquivo não encontrado!\n");
                break;
            }

            fscanf(arquivoMochila, "%d\n", &totalItens);

            for (int indiceItem = 0; indiceItem < totalItens; indiceItem++) {
                fscanf(arquivoMochila, "%49[^;];%29[^;];%d;%d\n",
                       mochila[indiceItem].nome,
                       mochila[indiceItem].tipo,
                       &mochila[indiceItem].quantidade,
                       (int*)&mochila[indiceItem].raridade);         
            }

            fclose(arquivoMochila);
            printf("\nMochila carregada!\n");
            break;
            
        }

        case 13:
            printf("\nEncerrando o programa...\n");
            break;

        default:
            printf("\n Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 13);

    return 0;
}
