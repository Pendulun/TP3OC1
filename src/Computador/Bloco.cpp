#include "Bloco.hpp"

namespace Computador{

	Bloco::Bloco(){
		m_bloco = new palavras(knum_palavras);
		this->m_bitValido = false;

		unsigned int i = 0;
		for(; i<knum_palavras; i++){
			Palavra* palavra = new Palavra();
			this->m_bloco->at(i) = palavra;
		}

	}

	// Objetos alocados na classe:
	//   ->m_bloco
	Bloco::~Bloco(){
		// Primeiro limpar vetor
		unsigned int i = 0;
		for(; i < m_bloco->size(); i++) {
			delete m_bloco->at(i);
		}
		m_bloco->clear();
		// Depois deletar
		delete m_bloco;
	}

	bool Bloco::getBitValido(){
		return this->m_bitValido;
	}

	palavras* Bloco::getBloco(){
		return this->m_bloco;
	}

	void Bloco::setBitValido(bool p_bitValido){
		this->m_bitValido = p_bitValido;
	}

	void Bloco::setBloco(palavras* p_bloco){
		this->m_bloco = p_bloco;
	}

}