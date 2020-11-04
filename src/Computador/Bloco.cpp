#include "Bloco.hpp"

#include <iostream>

namespace Computador{

	Bloco::Bloco(){
		// Escalares
		this->m_bitSujo = false;
		this->m_bitValido = false;
		this->m_tag = 0;

		// Inicializando bloco
		m_bloco = new palavras(ktam_bloco);
		unsigned int i = 0;
		for(; i<ktam_bloco; i++){
			Palavra* palavra = new Palavra();
			this->m_bloco->at(i) = palavra;
		}

	}

	// Objetos alocados na classe:
	//   ->m_bloco
	//     ->palavras
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

	bool Bloco::getBitSujo(){
		return this->m_bitSujo;
	}
	
	void Bloco::setBitSujo(bool p_sujo){
		this->m_bitSujo = p_sujo;
	}

	bool Bloco::getBitValido(){
		return this->m_bitValido;
	}

	void Bloco::setBitValido(bool p_bitValido){
		this->m_bitValido = p_bitValido;
	}

	const unsigned int Bloco::getTag() {
		return this->m_tag;
	}

	void Bloco::setTag(const unsigned int p_tag){
		this->m_tag = p_tag;
	}

	palavras* Bloco::getBloco(){
		return this->m_bloco;
	}

	void Bloco::setBloco(palavras* p_bloco){
		this->m_bloco = p_bloco;
	}

	void Bloco::setBloco(Bloco* p_bloco) {
		// Copiar tudo de p_bloco
		// Escalares
		this->m_bitSujo = p_bloco->getBitSujo();
		this->m_bitValido = p_bloco->getBitValido();
		this->m_tag = p_bloco->getTag();

		// Ajustando palavras
		unsigned int i = 0;
		// Tem que pegar uma por uma
		for(; i < m_bloco->size(); i++) {
			m_bloco->at(i)->setPalavra(p_bloco->getBloco()->at(i)->getPalavra());
		}
	}
}