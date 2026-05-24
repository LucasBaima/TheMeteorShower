
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "game.h"
#include <time.h>  //Declaração de time.h para usar a função time()

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
        atualizarMeteoros();
        prepararMatriz();
        desenharTela();
        Sleep(50);
    }

    gerenciarTopScore();
   
    return 0;
}