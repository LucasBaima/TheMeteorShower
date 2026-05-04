#ifndef GAME_H
#define GAME_H

#define LARGURA 30
#define ALTURA 20
typedef struct {
    int x;
    int y;
} Nave;
typedef struct Meteoro {
    int x;
    int y;
    struct Meteoro* prox;
} Meteoro;      


//// Variáveis Globais (extern permite que sejam compartilhadas entre os arquivos .c)
extern char matrizTela[ALTURA][LARGURA];
extern Meteoro* listaMeteoros;
extern Nave jogador;
extern int score;
extern int gameOver;

void inicializarJogo();
void prepararMatriz();
void desenharTela();

#endif