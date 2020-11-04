#include <string>
#include <iostream>
#include <fstream>
#include "CPU.hpp"
   
int main(int argc, char *argv[]){
	if(argc>1){
		std::string arqEntrada = argv[1];
		std::fstream fs;
		fs.open(arqEntrada, std::fstream::in);

		if(fs.is_open()){
			std::cerr << "Inicializando cpu" << std::endl;
			Computador::CPU* cpu = new Computador::CPU();
			std::cerr << "Cpu inicializado" <<std::endl;
	  		while(!fs.eof()){
	  			unsigned int posicao;
	  			bool tipoInstrucao;
	  			fs>>posicao;
	  			fs>>tipoInstrucao;
	  			if(tipoInstrucao){
	  				std::string dado;
	  				fs>>dado;
						std::cerr << "Indo para cpu" << std::endl;
	  				cpu->escreverCache(posicao,dado);
						std::cerr << "Voltando de cpu" << std::endl;

	  			}else{
						std::cerr << "Indo para cpu" << std::endl;

	  				cpu->lerCache(posicao);
						std::cerr << "Voltando de cpu" << std::endl;

	  			}
	  		}
	  		cpu->escreverArqFinal();
	  		delete cpu;
	  		fs.close();
 		 }else{
    		std::cout<< "Erro ao abrir o arquivo - confira o local e nome do arquivo"<<std::endl;
    		fs.close();
    		system("PAUSE");
  		}
	}else{
		std::cout<< "Nao foi detectado nenhum arquivo de entrada"<<std::endl;
	}
	return 0;
}