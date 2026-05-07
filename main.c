#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "game.h"

void processarInput() {
    if (_kbhit()) {
        char tecla = _getch();
        if ((tecla == 'a' || tecla == 'A') && jogador.x > 0) jogador.x--;
        if ((tecla == 'd' || tecla == 'D') && jogador.x < LARGURA - 1) jogador.x++;
        if (tecla == 'q' || tecla == 'Q') gameOver = 1;
    }
}




int main() {
    inicializarJogo();
    system("cls");


    while (!gameOver){
        processarInput();
        prepararMatriz();
        desenharTela();
        Sleep(50);
    }
    return 0;
}
