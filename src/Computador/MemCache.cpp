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

#include <iostream>

namespace Computador {

// Sem problemas com nullptr
//:D
MemCache::MemCache() {
	m_MD = new MemDados();

	m_blocos = new blocos(ktam_memcache);
	unsigned int i = 0;
	for(; i < m_blocos->size(); i++) {
		m_blocos->at(i) = new Bloco();
	}
}

//:D
MemCache::~MemCache() {
	// Limpando m_blocos
	unsigned int i = 0;
	for(; i < m_blocos->size(); i++) {
		delete m_blocos->at(i);
	}
	m_blocos->clear();
	// Depois deletar
	delete m_blocos;

	// Limpando m_MD
	delete m_MD;
}

//:D
bool MemCache::ler(const unsigned int p_pos) {
	bool hit = false;
	// Em qual bloco e palavra da cache p_pos deve ficar
	const unsigned int pos_bloco = m_bloco_em(p_pos);
	//const unsigned int pos_palavra = m_palavra_em(p_pos);

	Bloco* bloco_atual = m_blocos->at(pos_bloco);
	// VALIDO / SUJO
	// 1X
	if (bloco_atual->getBitValido()) {
		// Aqui, usando tag como um id para blocos da MemDados
		if(bloco_atual->getTag() == m_calc_tag(p_pos)) {
			hit = true;
		} // That was a hit!
		else {
			hit = false;
		}
	}
	// 0X
	else {
		hit = false;
	}

	// Pronto, não precisamos checar bit sujo para leitura. A tag
	//   ser igual já garante que temos os dados que procuramos.
	// Só falta trazer os dados certos da MemDados, no caso de um
	//   miss.
	if(!hit) {
		bloco_atual->setBloco(m_ler_MD(p_pos));
	}
	
	return hit;
}

//:D
void MemCache::escrever(const unsigned int p_pos, std::string p_dado) {
	// Em qual bloco e palavra da cache p_pos deve ficar
	const unsigned int pos_bloco = m_bloco_em(p_pos);
	//const unsigned int pos_palavra = m_palavra_em(p_pos);
	
	// Flag que indica que endereco buscado foi encontrado na
	//   cache.
	bool hit = false; // Assumir que deu miss como default
	Bloco* bloco_atual = m_blocos->at(pos_bloco);

	// VALIDO / SUJO
	// 0X
	if (!bloco_atual->getBitValido()) { // Nao tinha nada la
		// Nao se preocupe, ele vai buscar os dados la embaixo
		bloco_atual->setBitValido(true);
	}
	// 10
	else if(!bloco_atual->getBitSujo() == m_calc_tag(p_pos)) {
		if (bloco_atual->getTag() == pos_bloco) {
			bloco_atual->setBitSujo(true);
			hit = true;
		}
	}
	// 11
	else { // Writeback
		if (bloco_atual->getTag() == m_calc_tag(p_pos)) {
			hit = true;
		}
		else { // A palavra que quero nao esta aqui!!
			// Atualizar MemDados de acordo com a MemCache
			m_escrever_MD(bloco_atual); 
		}
	}

	// Se nao encontramos os dados pedidos aqui, precisamos
	//   requisita-los da memoria de dados.
	if (!hit) {
		bloco_atual->setBloco(m_ler_MD(p_pos));
		// E ja resetamos o bit sujo, pois os dados que trouxemos
		//   estao limpinhos.
		bloco_atual->setBitSujo(false);
	}
}

// Requests para MD
//:D
Bloco* MemCache::m_ler_MD(const unsigned int p_pos) {
		return m_MD->ler(p_pos);
}

//:D
void MemCache::m_escrever_MD(Bloco* p_bloco) {
	m_MD->escrever(p_bloco);
}

// Continhas
//:D
const unsigned int MemCache::m_bloco_em(const unsigned int p_pos) {
	return (m_calc_tag(p_pos)) % ktam_memcache;
}

//:D
const unsigned int MemCache::m_palavra_em(const unsigned int p_pos) {
	return p_pos % Bloco::ktam_bloco;
}

//:D
const unsigned int MemCache::m_calc_tag(const unsigned int p_pos) {
	return ((unsigned int) (p_pos / Bloco::ktam_bloco));
}

}
