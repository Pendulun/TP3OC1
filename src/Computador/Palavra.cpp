#include "Palavra.hpp"

namespace Computador{

	Palavra::Palavra(){
		this->palavra = "";
	}

	std::string Palavra::getPalavra(){
		return this->palavra;
	}

	void Palavra::getPalavra(std::string palavra){
		this->palavra = palavra;
	}

}