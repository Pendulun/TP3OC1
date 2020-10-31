#ifndef CPU_H
#define CPU_H
#include <string>
//#include "MemCache.hpp"
namespace Computador{
	class CPU{
	public:
		void executarInstrucao(unsigned int posicao, unsigned int tipo, std::string);
		~CPU();
		CPU();
	private:
		void lerCache();
		void escreverCache();
		void escreverArqTemp();
		void escreverArqFinal();
		//MemCache* memCache;
		unsigned int leituras;
		unsigned int escritas;
		unsigned int misses;
		unsigned int hits;	
	};
}

#endif