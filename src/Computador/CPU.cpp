#include "CPU.hpp"

namespace Computador{

	CPU::CPU(){
		this->leituras=0;
		this->escritas=0;
		this->misses=0;
		this->hits=0;
	}

	CPU::~CPU(){
		//deleta a memória cache
	}

	//Recebe uma instrução a ser executada
	void CPU::executarInstrucao(unsigned int posicao, unsigned int tipo, std::string){

	}

	//Operação de leitura da Cache
	void CPU::lerCache(){

	}

	//Operação de escrita na cache
	void CPU::escreverCache(){

	}

	//Escreve o arquivo temporário
	void CPU::escreverArqTemp(){

	}

	//Escreve o arquivo final de saída
	void escreverArqFinal(){

	}
}