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

	//Operação de leitura da Cache
	void CPU::lerCache(unsigned int posicao){

	}

	//Operação de escrita na cache
	void CPU::escreverCache(unsigned int posicao, std::string dado){

	}

	//Escreve o arquivo temporário
	void CPU::escreverArqTemp(){

	}

	//Escreve o arquivo final de saída
	void escreverArqFinal(){

	}
}