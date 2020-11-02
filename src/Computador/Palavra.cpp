#include "Palavra.hpp"

namespace Computador{

	Palavra::Palavra(){
		this->palavra = "";
	}

	std::string Palavra::getPalavra(){
		return this->palavra;
	}

	void Palavra::setPalavra(std::string palavra){
		this->palavra = palavra;
	}

}