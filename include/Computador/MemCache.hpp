// Projeto TP3OC1 arquivo hpp
// Classe MemCache
//
// Descrição:
// Essa classe implementa a memória cache em si, e está
//   encarregada de administrar os blocos apropriadamente, ao
//   responder a pedidos da CPU, que, especificamente, incluem:
//   -> Escrita
//   -> Leitura
// No caso de um miss, ela deve fazer um pedido a outra classe,
//   a memória de dados, denominada nesse trabalho por
//   "MemDados".
////////////////////////////////////////////////////////////////

#ifndef MEMCACHE_H	
#define MEMCACHE_H

#include "Bloco.hpp"

#include <vector>

namespace Computador{

typedef std::vector<Bloco*> blocos;

	class MemCache{
		public:
			MemCache();
			~MemCache();

		private:
			static const unsigned int knum_blocos = 64;
			blocos* m_blocos;
	};

}

#endif
