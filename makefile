# Variaveis
CC=g++
CFLAGS=-Wall -g
EXEC=./tp3 # nome do executavel que sera gerado, nao troque
BUILD=./build/
SRC=./src/
INCLUDE=./include/
COMP=Computador/

# Expansoes de variaveis
OBJETOS:=$(patsubst $(SRC)%cpp, $(BUILD)%o, $(wildcard $(SRC)$(COMP)*.cpp))
OBJ_COMPIL_COMMAND=$(CC) $(CFLAGS) -I $(INCLUDE)$(COMP) -c $< -o $@

# Regras
$(EXEC):	$(BUILD)main.o
	$(CC) $(CFLAGS) -o $(EXEC) $(BUILD)main.o $(BUILD)$(COMP)*.o 

$(BUILD)$(COMP) ::
	@-mkdir --parents $@

$(BUILD)main.o:	$(BUILD)$(COMP) $(SRC)main.cpp $(OBJETOS)
	$(CC) $(CFLAGS) -I $(INCLUDE)$(COMP) -c $(SRC)main.cpp -o $(BUILD)main.o

$(BUILD)%.o :: $(SRC)%.cpp $(INCLUDE)%.hpp
	$(OBJ_COMPIL_COMMAND)

.PHONY: clean mem
clean ::
	$(info Deleting all the directories and subfolders:)
	$(info $(BUILD))
	@echo
	@echo Are you sure? \(Y/N\)
	@read choice && \
	if [[ "$$choice" = "y" ]] || [[ "$$choice" = "Y" ]]; then \
	{ rm --verbose --preserve-root --recursive $(BUILD) && \
		rm --verbose --preserve-root $(EXEC) && \
		echo Cleaning successful.; } || \
		{ let "status = $$?"; \
			echo Cleaning of some directory failed; \
			echo Shell exit status: $$status; \
			exit $$status; \
		} \
	else \
	echo No cleaning was performed.; \
	fi

mem:
	valgrind --leak-check=full --show-leak-kinds=all $(EXEC) ./testcases/EX3.txt
