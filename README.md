# TheMeteorShower

Um jogo de sobrevivência rítmico desenvolvido em C para o terminal, como projeto final da disciplina de **Programação Imperativa e Funcional (PIF)** do segundo período de Ciência da Computação.

O objetivo é controlar uma nave no horizonte inferior da tela e sobreviver o maior tempo possível a uma chuva incessante de meteoros, cujos padrões e velocidades aumentam conforme a pontuação sobe.

## 👥 Autores
* **Arthur von Sohsten**
* **Joao Lucas Baima**
* **Marcelo Henrique**

## 🚀 Funcionalidades
- **Movimentação em Tempo Real:** Controle da nave usando as teclas `A` (esquerda) e `D` (direita).
- **Animação Fluida:** Sistema de frames por segundo (FPS) simulado no terminal.
- **Dificuldade Progressiva:** Aumento na taxa de surgimento de meteoros com o tempo.
- **Sistema de High Scores:** Persistência de dados para salvar os melhores tempos e nomes dos jogadores.






## ⚙️ Como compilar

Antes de tudo, você precisa ter o **GCC** instalado. Se não tiver:

```bash
sudo apt install gcc make
```

Com tudo instalado, entra na pasta do projeto e roda:

``bash
make
```

Isso já compila tudo automaticamente. Se der certo, vai aparecer o executável `meteordodge` na pasta.

Se quiser limpar e recompilar do zero:

`bash
make clean && make
```

## 🎮 Como jogar

```bash
./meteordodge
```

- `A` ou `←` — move a nave pra esquerda
- `D` ou `→` — move a nave pra direita
- `Q` — sai do jogo

O objetivo é sobreviver o maior tempo possível desviando dos meteoros que caem. Cada meteoro que passa sem te acertar vale **10 pontos**. Quando morrer, se bater o recorde vai poder salvar seu nome.

## 🖥️ Requisitos

- Linux ou macOS
- GCC instalado
- Terminal com suporte a ANSI (qualquer terminal moderno serve)