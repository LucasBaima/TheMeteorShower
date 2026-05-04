#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "game.h"

char matrizTela[ALTURA][LARGURA];
Nave jogador;
int gameOver = 0;

void inicializarJogo() {
    jogador.x = LARGURA / 2;
    jogador.y = ALTURA - 1;
    gameOver = 0;
}

void prepararMatriz() {
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) matrizTela[i][j] = ' ';
    }
    matrizTela[jogador.y][jogador.x] = '^';
}

void desenharTela() {
    COORD coord = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("=== METEOR DODGE ===\n");
    for (int i = 0; i < LARGURA + 2; i++) printf("-");
    printf("\n");
    for (int i = 0; i < ALTURA; i++) {
        printf("|");
        for (int j = 0; j < LARGURA; j++) printf("%c", matrizTela[i][j]);
        printf("|\n");
    }
    for (int i = 0; i < LARGURA + 2; i++) printf("-");
    printf("\n");
}