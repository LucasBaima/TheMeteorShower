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