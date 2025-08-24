#include <stdio.h>

#define TABULEIRO 10
#define NAVIO 3

// Função para validar e posicionar um navio
// Retorna 0 em caso de sucesso, 1 em caso de erro (fora do tabuleiro ou sobreposição)
int posicionar_navio(int tabuleiro[TABULEIRO][TABULEIRO], int linha_inicial, int coluna_inicial, int tipo_navio) {
    
    // Validação de limites
    
    if (tipo_navio == 0) { 
        if (coluna_inicial + NAVIO > TABULEIRO) {
            printf("Erro: navio horizontal nao cabe no tabuleiro!\n");
            return 1;
        }
    } else if (tipo_navio == 1) { 
        if (linha_inicial + NAVIO > TABULEIRO) {
            printf("Erro: navio vertical nao cabe no tabuleiro!\n");
            return 1;
        }
    } else if (tipo_navio == 2) { 
        if (linha_inicial + NAVIO > TABULEIRO || coluna_inicial + NAVIO > TABULEIRO) {
            printf("Erro: navio diagonal crescente nao cabe no tabuleiro!\n");
            return 1;
        }
    } else if (tipo_navio == 3) { 
        if (linha_inicial + NAVIO > TABULEIRO || coluna_inicial - NAVIO < -1) {
            printf("Erro: navio diagonal decrescente nao cabe no tabuleiro!\n");
            return 1;
        }
    }

    // Validação de sobreposição e posicionamento
    
    for (int i = 0; i < NAVIO; i++) {
        int linha_atual, coluna_atual;

        if (tipo_navio == 0) { 
            linha_atual = linha_inicial;
            coluna_atual = coluna_inicial + i;
        } 
        else if (tipo_navio == 1) { 
            linha_atual = linha_inicial + i;
            coluna_atual = coluna_inicial;
        } 
        else if (tipo_navio == 2) { 
            linha_atual = linha_inicial + i;
            coluna_atual = coluna_inicial + i;
        } 
        else { 
            linha_atual = linha_inicial + i;
            coluna_atual = coluna_inicial - i;
        }

        if (tabuleiro[linha_atual][coluna_atual] == 3) {
            printf("Erro: navios se sobrepoem!\n");
            return 1;
        }
    }

    // Se passou na validação, posiciona o navio
    
    for (int i = 0; i < NAVIO; i++) {
        if (tipo_navio == 0) { 
            tabuleiro[linha_inicial][coluna_inicial + i] = 3;
        } 
        else if (tipo_navio == 1) { 
            tabuleiro[linha_inicial + i][coluna_inicial] = 3;
        } 
        else if (tipo_navio == 2) { 
            tabuleiro[linha_inicial + i][coluna_inicial + i] = 3;
        } 
        else { 
            tabuleiro[linha_inicial + i][coluna_inicial - i] = 3;
        }
    }

    return 0; 
}
// Função para exibir o tabuleiro

void exibir_tabuleiro(int tabuleiro[TABULEIRO][TABULEIRO]){
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TABULEIRO; i++) {
        for (int j = 0; j < TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
   
    // Declaração do tabuleiro como matriz 10x10
   
    int tabuleiro[TABULEIRO][TABULEIRO];

    // Inicialização do tabuleiro com água (0)
    
    for (int i = 0; i < TABULEIRO; i++) {
        for (int j = 0; j < TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    
    // Navios Horizontal e Vertical
    
    int linha_h = 2, coluna_h = 4;
    int linha_v = 5, coluna_v = 1;
    
    // Navios Diagonais
    // Diagonal crescente (linha e coluna aumentam)
    
    int linha_d1 = 1, coluna_d1 = 6; 
   
    // Diagonal decrescente (linha aumenta, coluna diminui)
    
    int linha_d2 = 6, coluna_d2 = 9; 

    // Posicionamento dos navios
   
    if (posicionar_navio(tabuleiro, linha_h, coluna_h, 0) != 0) return 1;
    if (posicionar_navio(tabuleiro, linha_v, coluna_v, 1) != 0) return 1;
    if (posicionar_navio(tabuleiro, linha_d1, coluna_d1, 2) != 0) return 1;
    if (posicionar_navio(tabuleiro, linha_d2, coluna_d2, 3) != 0) return 1;

    // Exibição do tabuleiro
   
    exibir_tabuleiro(tabuleiro);

    return 0;
}