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
    srand(time(NULL));
    system("cls");
    inicializarJogo();
    
    while (!gameOver) {
        processarInput();
        if (rand() % 100 < 30) gerarMeteoro(); // Gera meteoros dinamicamente
        prepararMatriz();
        desenharTela();
        Sleep(50);
    }
    return 0;
}