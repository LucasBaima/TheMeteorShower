
#include <stdio.h>
#include <stdlib.h>
#include "keyboard.h" //header cli-clb
#include "screen.h" //header cli-clb
#include <timer.h>  //Declaração de time.h para usar a função time()
#include "game.h"

void processarInput() {
    if (keyhit()) {
        char tecla = readch();  //Alteração para usar readch() do header cli-clb
        if ((tecla == 'a' || tecla == 'A') && jogador.x > 0) jogador.x--;
        if ((tecla == 'd' || tecla == 'D') && jogador.x < LARGURA - 1) jogador.x++;
        if (tecla == 'q' || tecla == 'Q') gameOver = 1;
    }
}




int main() {
    screenInit(0); //Inicialização da tela usando a função do header cli-clb
    keyboardInit(); //Inicialização do teclado usando a função do header cli-clb
    timerInit(50); //Inicialização do timer usando a função do header cli-clb

    inicializarJogo();
    
    while (!gameOver) {
        processarInput();
        if (rand() % 100 < 30) gerarMeteoro(); // Gera meteoros dinamicamente
        atualizarMeteoros();
        prepararMatriz();
        desenharTela();
        
        while (!timerTimeOver());
    }

    gerenciarTopScore();

    // Restaura o terminal para o estado original
    keyboardDestroy();
    screenDestroy();
    
   
    return 0;
}