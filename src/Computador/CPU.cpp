#include "CPU.hpp"

namespace Computador{

	CPU::CPU(){
		this->leituras=0;
		this->escritas=0;
		this->misses=0;
		this->hits=0;
		//this->memCache = new Computador::MemCache();
	}

	CPU::~CPU(){
		//deleta a memória cache
		//delete this->memCache;
	}

	//Operação de leitura da Cache
	void CPU::lerCache(unsigned int posicao){
		this->leituras++;
		bool hit=false;
		//Se deu hit
		if(this->memCache->buscarMemDados(posicao)){
			this->hit++;
			hit = true;
		}else{
			this->misses++;
		}
		//Escreve no arqTemp
		//posicao 0 hit ? H : M
		std::string linha = posicao;
		linha.append(" 0 ");
		if(hit){
			linha.append("H");
		}else{
			linha.append("M");
		}
		escreverArqTemp(linha);
	}

	//Operação de escrita na cache
	void CPU::escreverCache(unsigned int posicao, std::string dado){
		this->escritas++;
		this->memCache->salvarMemDados(posicao,dado);
		//Escreve no arqTemp
		//posicao 1 dado W
		std::string linha = posicao;
		linha.append(" 1 ");
		linha.append(dado);
		linha.append(" W");
		escreverArqTemp(linha);
	}

	//Escreve o arquivo temporário
	void CPU::escreverArqTemp(std::string linha){
		std::fstream saida;
		saida.open("../../output/resultTemp.txt", std::ofstream::app);
		saida<<linha<<std::endl;
		saida.close();
	}

	//Escreve o arquivo final de saída
	void escreverArqFinal(){
		std::fstream saida, arqTemp;
		saida.open("../../output/result.txt", std::ofstream::out);

		saida<<"READS: "<<this->leituras<<std::endl;
		saida<<"WRITES: "<<this->escritas<<std::endl;
		saida<<"HITS: "<<this->hits<<std::endl;
		saida<<"MISSES: "<<this->misses<<std::endl;

		float hitRate = this->hits/this->leituras;
		float missRate = this->misses/this->leituras;
		saida<<"HIT RATE: "<<hitRate<<std::endl;
		saida<<"MISS RATE: "<<missRate<<std::endl;
		saida<<std::endl;

		arqTemp.open("../../output/resultTemp.txt", std::ofstream::in);
		while(!arqTemp.eof()){
			std::string linha;
			arqTemp>>linha;
			saida<<linha<<std::endl;
		}
		
		arqTemp.close();
		saida.close();
	}
}