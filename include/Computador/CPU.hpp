#ifndef CPU_H
#define CPU_H
#define ARQFINAL result.txt
#define ARQTEMP resultTemp.txt
#include <string>
//#include "MemCache.hpp"
namespace Computador{
	class CPU{
	public:
		void lerCache(unsigned int posicao);
		void escreverCache(unsigned int posicao, std::string dado);
		~CPU();
		CPU();
	private:
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