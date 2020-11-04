#include "CPU.hpp"

namespace Computador{

	CPU::CPU(){
		this->leituras=0;
		this->escritas=0;
		this->misses=0;
		this->hits=0;
		this->flag = true;
		std::cerr << "Inicializando cache" << std::endl;
		this->memCache = new Computador::MemCache();
		std::cerr << "Cache inicializada" << std::endl;
	}

	CPU::~CPU(){
		//deleta a memória cache
		delete this->memCache;
	}

	//Operação de leitura da Cache
	void CPU::lerCache(unsigned int posicao){
		this->leituras++;
		std::cerr << "Indo ler na cache" << std::endl;
		bool hit = this->memCache->ler(posicao);
		//Se deu hit
		if(hit){
			this->hits++;
		} else{
			this->misses++;
		}
		// Leitura foi feita
		std::cerr << "Leu na cache" << std::endl;
		//Escreve no arqTemp
		//posicao 0 hit ? H : M
		std::string linha = std::to_string(posicao);
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
		// Não precisamos chegar hit / miss. Teoricamente, a CPU
		//   pode continuar sua vida sem precisar saber se é um hit.
		std::cerr << "Indo escrever na cache" << std::endl;
		this->memCache->escrever(posicao,dado);
		std::cerr << "Escreveu na cache" << std::endl;

		//Escreve no arqTemp
		//posicao 1 dado W
		std::string linha = std::to_string(posicao);
		linha.append(" 1 ");
		linha.append(dado);
		linha.append(" W");
		escreverArqTemp(linha);
	}

	//Escreve o arquivo temporário
	void CPU::escreverArqTemp(std::string linha){
		std::fstream saida;
		saida.open(nomeArqTemp, std::ofstream::app);
		if(saida.is_open()){
			saida<<linha<<std::endl;
			saida.close();
		}else{
			std::cout<<"Não deu pra abrir o arqTemp"<<std::endl;
		}
		
	}

	//Escreve o arquivo final de saída
	void CPU::escreverArqFinal(){
		std::cerr << "Escrevendo arquivo final" << std::endl;
		std::fstream saida, arqTemp;
		saida.open(nomeArqFinal, std::ofstream::out);
		double hitRate = (int)this->hits/(int)this->leituras;
		double missRate = (int)this->misses/(int)this->leituras;
		if(saida.is_open()){
			saida<<"READS: "<<std::to_string(this->leituras)<<std::endl;
			saida<<"WRITES: "<<std::to_string(this->escritas)<<std::endl;
			saida<<"HITS: "<<std::to_string(this->hits)<<std::endl;
			saida<<"MISSES: "<<std::to_string(this->misses)<<std::endl;
			saida<<"HIT RATE: "<<std::to_string(hitRate)<<std::endl;
			saida<<"MISS RATE: "<<std::to_string(missRate)<<std::endl;
			saida<<std::endl;

			arqTemp.open(nomeArqTemp, std::ofstream::in);
			if(arqTemp.is_open()){
				std::string linha;
				while (std::getline(arqTemp, linha)) {
				saida<<linha<<std::endl;
				}

				arqTemp.close();
			}else{
				std::cout<<"Não deu pra abrir o arqTemp"<<std::endl;
			}
			
			saida.close();
		}else{
			std::cout<<"Não deu pra abrir o arqFinal"<<std::endl;
		}
		std::cerr << "Escreveu arquivo final" << std::endl;
	}
}