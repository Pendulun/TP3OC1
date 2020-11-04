// Projeto TP3OC1 arquivo hpp
// Classe MemDados
//
// Descrição:
// Essa classe implementa a memória de dados, que é o segundo
//   nível da nossa hierarquia de memória.
// Tudo que ela é responsável por fazer é ser capaz de antender
//   a pedidos de escrita e leitura, simplesmente escrevendo e
//   lendo, não é necessário fazer análises mais profundas.
////////////////////////////////////////////////////////////////

#include "MemDados.hpp"

#include <iostream>

namespace Computador {

//:D
MemDados::MemDados() {
	m_dados = new blocos(ktam_memdados);
	unsigned int i = 0;
	for(; i < m_dados->size(); i++) {
		m_dados->at(i) = new Bloco();
		// A tag eh um id, podemos simplesmente usar i
		m_dados->at(i)->setTag(i);
		// Na memdados, tudo deve ter bitvalido = true
		// Na verdade, nao teria nem esse bit, mas ficou mais facil
		//   implementar assim, para aproveitar a classe ~Bloco~.
		m_dados->at(i)->setBitValido(true);
	}
}

// Objetos alocados nesse objeto:
//   ->m_dados
//     ->palavras
//:D
MemDados::~MemDados() {
	// Limpar m_dados
	unsigned int i = 0;
	for(; i < m_dados->size(); i++) {
		delete m_dados->at(i);
	}
	m_dados->clear();
	
	delete m_dados;
}

//:D
Bloco* MemDados::ler(const unsigned int p_pos)
{
	const unsigned int pos_bloco = (unsigned int) (p_pos / Bloco::ktam_bloco);
	return m_dados->at(pos_bloco);
}

//:D
void MemDados::escrever(Bloco* p_bloco)
{
	// Garantindo que a gambiarra funcione
	p_bloco->setBitValido(true);
	p_bloco->setBitSujo(false);
	m_dados->at(p_bloco->getTag())->setBloco(p_bloco);
	
}

}