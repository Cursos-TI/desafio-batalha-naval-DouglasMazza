#include <stdio.h>

#define TABULEIRO_TAMANHO 10
#define HABILIDADE_TAMANHO 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// --- Funções para criar as áreas de efeito das habilidades ---

// Constrói uma matriz de efeito em formato de Cone

void criar_cone(int matriz[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO]) {
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            if (j >= HABILIDADE_TAMANHO / 2 - i && j <= HABILIDADE_TAMANHO / 2 + i) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Constrói uma matriz de efeito em formato de Cruz

void criar_cruz(int matriz[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO]) {
    int centro = HABILIDADE_TAMANHO / 2;
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            if (i == centro || j == centro) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Constrói uma matriz de efeito em formato de Octaedro (Losango)

void criar_octaedro(int matriz[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO]) {
    int centro = HABILIDADE_TAMANHO / 2;
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Posiciona um navio no tabuleiro

void posicionar_navio(int tabuleiro[TABULEIRO_TAMANHO][TABULEIRO_TAMANHO], int linha, int coluna) {
    if (linha >= 0 && linha < TABULEIRO_TAMANHO && coluna >= 0 && coluna < TABULEIRO_TAMANHO) {
        if (tabuleiro[linha][coluna] == AGUA) {
            tabuleiro[linha][coluna] = NAVIO;
        }
    }
}

void aplicar_habilidade(int tabuleiro[TABULEIRO_TAMANHO][TABULEIRO_TAMANHO], int habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO], int linha_origem, int coluna_origem) {
    int offset = HABILIDADE_TAMANHO / 2;
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            int tabuleiro_linha = linha_origem - offset + i;
            int tabuleiro_coluna = coluna_origem - offset + j;

            // Validação de limites para garantir que a habilidade não saia do tabuleiro
            
            if (tabuleiro_linha >= 0 && tabuleiro_linha < TABULEIRO_TAMANHO &&
                tabuleiro_coluna >= 0 && tabuleiro_coluna < TABULEIRO_TAMANHO) {
                
                // Aplica a habilidade apenas se a posição na matriz de habilidade for 1
                
                if (habilidade[i][j] == 1) {
                    tabuleiro[tabuleiro_linha][tabuleiro_coluna] = HABILIDADE;
                }
            }
        }
    }
}

// Exibe o tabuleiro com todos os elementos

void exibir_tabuleiro(int tabuleiro[TABULEIRO_TAMANHO][TABULEIRO_TAMANHO]) {
    printf("\n=== TABULEIRO COM HABILIDADES ===\n\n");
    for (int i = 0; i < TABULEIRO_TAMANHO; i++) {
        for (int j = 0; j < TABULEIRO_TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// --- Função Principal ---

int main() {
    // Declaração e inicialização do tabuleiro
    
    int tabuleiro[TABULEIRO_TAMANHO][TABULEIRO_TAMANHO];
    for (int i = 0; i < TABULEIRO_TAMANHO; i++) {
        for (int j = 0; j < TABULEIRO_TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Declaração das matrizes de habilidades
    
    int cone[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO];
    int cruz[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO];
    int octaedro[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO];

    // Criação das formas das habilidades
    
    criar_cone(cone);
    criar_cruz(cruz);
    criar_octaedro(octaedro);

    // Posicionamento de alguns navios para referência
    
    posicionar_navio(tabuleiro, 1, 1);
    posicionar_navio(tabuleiro, 1, 2);
    posicionar_navio(tabuleiro, 1, 3);
    posicionar_navio(tabuleiro, 8, 8);

    // Aplicação das habilidades no tabuleiro
    
    aplicar_habilidade(tabuleiro, cone, 2, 5); // Cone centrado na linha 2, coluna 5
    aplicar_habilidade(tabuleiro, cruz, 7, 2); // Cruz centrada na linha 7, coluna 2
    aplicar_habilidade(tabuleiro, octaedro, 5, 8); // Octaedro centrado na linha 5, coluna 8

    // Exibição do tabuleiro final
    exibir_tabuleiro(tabuleiro);

    return 0;
}