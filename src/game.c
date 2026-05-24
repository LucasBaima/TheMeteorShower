#include <stdio.h>
#include <stdlib.h>
#include "screen.h" //header cli-clb
#include "keyboard.h"
#include "game.h"

char matrizTela[ALTURA][LARGURA];
Nave jogador;
int score = 0; 
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
    // ALTERADO: SetConsoleCursorPosition(...) -> screenHomeCursor()
    screenHomeCursor();
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
    // ADICIONADO: flush imediato para evitar flickering
    screenUpdate();
}

void atualizarMeteoros() {
    Meteoro* atual = listaMeteoros;
    Meteoro* anterior = NULL;

    while (atual != NULL) {
        atual->y++; // Física

        if (atual->x == jogador.x && atual->y == jogador.y) gameOver = 1; // Colisão

        if (atual->y >= ALTURA) {
            Meteoro* remover = atual;
            if (anterior == NULL) listaMeteoros = atual->prox;
            else anterior->prox = atual->prox;
            
            atual = atual->prox;
            free(remover); // Liberação de memória
            score += 10;
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}




void gerenciarTopScore() {
    FILE* arquivo;
    int recorde = 0;
    char nomeRecordista[50] = "Ninguem";

    arquivo = fopen("topscore.txt", "r");
    if (arquivo != NULL) {
        fscanf(arquivo, "%s %d", nomeRecordista, &recorde);
        fclose(arquivo);
    }


    screenClear();
    screenUpdate();

    printf("====== GAME OVER ======\nSua pontuacao: %d\n\n", score);

    if (score > recorde) {
        printf("NOVO RECORDE!!!\nDigite seu primeiro nome: ");
        char nome[50];

        keyboardDestroy(); // Restaura o terminal para modo normal antes do scanf
        scanf("%49s", nome);

        arquivo = fopen("topscore.txt", "w");
        if (arquivo != NULL) {
            fprintf(arquivo, "%s %d\n", nome, score);
            fclose(arquivo);
        }
        printf("Recorde salvo com sucesso!\n");
    } else {
        printf("Recorde atual: %s com %d pontos.\n", nomeRecordista, recorde);
    }

        // Limpeza de segurança da memória restante
    Meteoro* atual = listaMeteoros;
    while(atual != NULL) {
        Meteoro* remover = atual;
        atual = atual->prox;
        free(remover);
    }
}