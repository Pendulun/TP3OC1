#include <string>
#include <iostream>
#include <fstream>
#include "CPU.hpp"
   
int main(int argc, char *argv[]){
	if(argc>1){
		std::string arq_entrada = argv[1];
		std::fstream fs;
		fs.open(arqEntrada, std::fstream::in);

		if(fs.is_open()){
			Computador::CPU* cpu = new Computador::CPU();
	  		while(!fs.eof()){
	  			unsigned int posicao;
	  			bool tipoInstrucao;
	  			fs>>posicao;
	  			fs>>tipoInstrucao;
	  			if(tipoInstrucao){
	  				std::string dado;
	  				fs>>dado;
	  				cpu->executarInstrucao(posicao,tipo,dado);
	  			}else{
	  				cpu->executarInstrucao(posicao,tipo,"");
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