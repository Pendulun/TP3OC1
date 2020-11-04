CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -g #-Wextra # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./tp3 # nome do executavel que sera gerado, nao troque
BUILD=./build/
SRC=./src/
INCLUDE=./include/
COMP=Computador/
# Expansoes de variaveis
OBJETOS:=$(patsubst $(SRC)%cpp, $(BUILD)%o, $(wildcard $(SRC)$(COMP)*.cpp))
OBJ_COMPIL_COMMAND=$(CC) $(CFLAGS) -I $(INCLUDE)$(COMP) -c $< -o $@

$(EXEC):	$(BUILD)main.o $(BUILD)$(COMP)
	$(CC) $(CFLAGS) -o $(EXEC) $(BUILD)main.o $(BUILD)$(COMP)*.o 

$(BUILD)$(COMP) ::
	-mkdir $(BUILD)
	-mkdir $@

$(BUILD)main.o:	$(SRC)main.cpp $(OBJETOS)
	$(CC) $(CFLAGS) -I $(INCLUDE)$(COMP) -c $(SRC)main.cpp -o $(BUILD)main.o

$(BUILD)%.o :: $(SRC)%.cpp $(INCLUDE)%.hpp
	$(OBJ_COMPIL_COMMAND)

.PHONY: clean mem
clean:
	rm -f $(BUILD)*/*.o $(BUILD)*.o *.exe

mem:
	valgrind --leak-check=full --show-leak-kinds=all $(EXEC) ./testcases/EX1.txt