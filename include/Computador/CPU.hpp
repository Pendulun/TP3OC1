#ifndef CPU_H
#define CPU_H
//#include "MemCache.hpp"
namespace Computador{
	class CPU{
	public:
		void executarInstrucao();
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