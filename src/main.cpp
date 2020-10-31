#include <string>
#include <iostream>
#include <fstream>
   
int main(int argc, char *argv[]){
	if(argc>1){
		std::string arq_entrada = argv[1];
		std::fstream fs;
		fs.open(arqEntrada, std::fstream::in);
		if(fs.is_open()){
	  		while(!fs.eof()){
	  			//Lê uma linha por vez até o final
	  		}
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