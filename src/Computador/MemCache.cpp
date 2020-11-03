// Projeto TP3OC1 arquivo cpp
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

#include "MemCache.hpp"

namespace Computador {

// Sem problemas com nullptr
//:D
MemCache::MemCache() {
	m_blocos = new blocos(knum_blocos);
	unsigned int i = 0;
	for(; i < m_blocos->size(); i++) {
		m_blocos->at(i) = new Bloco();
	}
}

//:D
MemCache::~MemCache() {
	// Limpar vetor
	unsigned int i = 0;
	for(; i < m_blocos->size(); i++) {
		delete m_blocos->at(i);
	}
	m_blocos->clear();
	// Depois deletar
	delete m_blocos;
}

}
