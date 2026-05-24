# Compilador utilizado
CC = gcc

# Flags de compilação:
# -Wall    -> ativa todos os warnings
# -I./include -> informa ao compilador onde estão os headers (.h)
CFLAGS = -Wall -I./include

# Todos os arquivos .c dentro da pasta src/
SRC = ./src/*.c

# Nome do executável gerado
TARGET = meteordodge

# Regra principal: compila o projeto
# Digite 'make' no terminal para compilar
all:
	$(CC) $(SRC) $(CFLAGS) -o $(TARGET)

# Regra de limpeza: remove o executável
# Digite 'make clean' no terminal para limpar
clean:
	rm -f $(TARGET)
