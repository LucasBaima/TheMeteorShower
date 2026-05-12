#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "game.h"

char matrizTela[ALTURA][LARGURA];
Nave jogador;
int gameOver = 0;
Meteoro* listaMeteoros = NULL;

void inicializarJogo() {
    jogador.x = LARGURA / 2;
    jogador.y = ALTURA - 1;
    gameOver = 0;
    listaMeteoros = NULL;
}
void gerarMeteoro() {
    Meteoro* novoMeteoro = (Meteoro*)malloc(sizeof(Meteoro));
    if (novoMeteoro == NULL) return;
    novoMeteoro->x = rand() % LARGURA;
    novoMeteoro->y = 0;
    novoMeteoro->prox = listaMeteoros;
    listaMeteoros = novoMeteoro;
}

void prepararMatriz() {
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) matrizTela[i][j] = ' ';
    }
    Meteoro* atual = listaMeteoros;
    while (atual != NULL) {
        if (atual->y < ALTURA) matrizTela[atual->y][atual->x] = 'O';
        atual = atual->prox;
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