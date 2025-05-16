#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.
// Constantes para direções e movimentos
#define CIMA 1
#define BAIXO 2
#define ESQUERDA 3
#define DIREITA 4
#define BISPO_DIAGONAL 5
#define TORRE_HORIZONTAL 5
#define RAINHA_HORIZONTAL 8
#define CAVALO_L 3  // 2 casas em uma direção + 1 perpendicular

// Protótipos das funções
void nivel_novato();
void nivel_aventureiro();
void nivel_mestre();
void movimentar_bispo_novato();
void movimentar_torre_novato();
void movimentar_rainha_novato();
void movimentar_cavalo_aventureiro();
void movimentar_bispo_recursivo(int casas);
void movimentar_torre_recursivo(int casas);
void movimentar_rainha_recursivo(int casas);
void movimentar_cavalo_complexo();

int main() {
  printf("=== DESAFIO DE XADREZ - MATECHECK ===\n\n");
    
    printf("----- NÍVEL NOVATO -----\n");
    nivel_novato();
    
    printf("\n----- NÍVEL AVENTUREIRO -----\n");
    nivel_aventureiro();
    
    printf("\n----- NÍVEL MESTRE -----\n");
    nivel_mestre();
     

    return 0;
}

void nivel_novato() {
    printf("Movimentação básica usando loops simples:\n");
    movimentar_bispo_novato();
    movimentar_torre_novato();
    movimentar_rainha_novato();
}

void nivel_aventureiro() {
    printf("Movimento do Cavalo usando loops aninhados:\n");
    movimentar_cavalo_aventureiro();
}

void nivel_mestre() {
    printf("Movimentação com funções recursivas e loops complexos:\n");
    
    printf("\nBispo (recursivo):\n");
    movimentar_bispo_recursivo(BISPO_DIAGONAL);
    
    printf("\nTorre (recursivo):\n");
    movimentar_torre_recursivo(TORRE_HORIZONTAL);
    
    printf("\nRainha (recursivo):\n");
    movimentar_rainha_recursivo(RAINHA_HORIZONTAL);
    
    printf("\nCavalo (complexo):\n");
    movimentar_cavalo_complexo();
}

// ========== FUNÇÕES DO NÍVEL NOVATO ==========

void movimentar_bispo_novato() {
    printf("\nBispo movendo %d casas na diagonal superior direita:\n", BISPO_DIAGONAL);
    for(int i = 1; i <= BISPO_DIAGONAL; i++) {
        printf("Casa %d: Cima + Direita\n", i);
    }
}

void movimentar_torre_novato() {
    printf("\nTorre movendo %d casas para a direita:\n", TORRE_HORIZONTAL);
    int i = 1;
    while(i <= TORRE_HORIZONTAL) {
        printf("Casa %d: Direita\n", i);
        i++;
    }
}

void movimentar_rainha_novato() {
    printf("\nRainha movendo %d casas para a esquerda:\n", RAINHA_HORIZONTAL);
    for(int i = 1; i <= RAINHA_HORIZONTAL; i++) {
        printf("Casa %d: Esquerda\n", i);
    }
}

// ========== FUNÇÕES DO NÍVEL AVENTUREIRO ==========

void movimentar_cavalo_aventureiro() {
    printf("\nCavalo movendo em L (2 baixo + 1 esquerda):\n");
    
    // Primeira parte do L (2 casas para baixo)
    for(int i = 1; i <= 2; i++) {
        printf("Passo %d: Baixo\n", i);
    }
    
    // Segunda parte do L (1 casa para esquerda)
    int j = 1;
    do {
        printf("Passo %d: Esquerda\n", j);
        j++;
    } while(j <= 1);
}

// ========== FUNÇÕES DO NÍVEL MESTRE ==========

void movimentar_bispo_recursivo(int casas) {
    if(casas <= 0) return;
    
    printf("Casa %d: Cima + Direita\n", BISPO_DIAGONAL - casas + 1);
    movimentar_bispo_recursivo(casas - 1);
}

void movimentar_torre_recursivo(int casas) {
    if(casas <= 0) return;
    
    printf("Casa %d: Direita\n", TORRE_HORIZONTAL - casas + 1);
    movimentar_torre_recursivo(casas - 1);
}

void movimentar_rainha_recursivo(int casas) {
    if(casas <= 0) return;
    
    printf("Casa %d: Esquerda\n", RAINHA_HORIZONTAL - casas + 1);
    movimentar_rainha_recursivo(casas - 1);
}

void movimentar_cavalo_complexo() {
    printf("\nCavalo movendo em L com condições complexas:\n");
    
    for(int vertical = 1, horizontal = 1; vertical <= 2 || horizontal <= 1; ) {
        if(vertical > 2) {
            printf("Finalizando movimento em L...\n");
            break;
        }
        
        if(vertical <= 2) {
            printf("Passo vertical %d: Baixo\n", vertical);
            vertical++;
            continue;
        }
        
        if(horizontal <= 1) {
            printf("Passo horizontal %d: Esquerda\n", horizontal);
            horizontal++;
        }
    }
}