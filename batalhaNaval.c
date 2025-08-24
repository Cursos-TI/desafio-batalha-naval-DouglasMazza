#include <stdio.h>

// Definições de tamanho fixo

#define TABULEIRO 10   
#define NAVIO 3        

int main() {
    
    // Declaração do tabuleiro como matriz 10x10
    
    int tabuleiro[TABULEIRO][TABULEIRO];

    // Inicialização do tabuleiro com água (0)
    
    for (int i = 0; i < TABULEIRO; i++) {
        for (int j = 0; j < TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Declaração dos navios (apenas para referência, todos os elementos = 3)
    
    int navio_horizontal[NAVIO] = {3, 3, 3};
    int navio_vertical[NAVIO] = {3, 3, 3};

    // Coordenadas iniciais pré-definidas dos navios
    
    // (podem ser alteradas no código para outros testes)
    
    int linha_inicial_h = 2, coluna_inicial_h = 4; // navio horizontal
    int linha_inicial_v = 5, coluna_inicial_v = 7; // navio vertical

    // ==== Validação dos navios dentro do tabuleiro ====

    // Verifica se o navio horizontal cabe
    
    if (coluna_inicial_h + NAVIO > TABULEIRO) {
        printf("Erro: navio horizontal nao cabe no tabuleiro!\n");
        return 1; // encerra programa
    }

    // Verifica se o navio vertical cabe
    
    if (linha_inicial_v + NAVIO > TABULEIRO) {
        printf("Erro: navio vertical nao cabe no tabuleiro!\n");
        return 1; // encerra programa
    }

    // ==== Posicionamento dos navios no tabuleiro ====

    // Posiciona o navio horizontal
    
    for (int i = 0; i < NAVIO; i++) {
        // Verifica se já existe navio nessa posição
        if (tabuleiro[linha_inicial_h][coluna_inicial_h + i] == 3) {
            printf("Erro: navios se sobrepoem!\n");
            return 1;
        }
        tabuleiro[linha_inicial_h][coluna_inicial_h + i] = navio_horizontal[i];
    }

    // Posiciona o navio vertical
    
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linha_inicial_v + i][coluna_inicial_v] == 3) {
            printf("Erro: navios se sobrepoem!\n");
            return 1;
        }
        tabuleiro[linha_inicial_v + i][coluna_inicial_v] = navio_vertical[i];
    }

    // ==== Exibição do tabuleiro ====
    
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TABULEIRO; i++) {
        for (int j = 0; j < TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
