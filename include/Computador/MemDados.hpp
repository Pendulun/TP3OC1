// Projeto TP3OC1 arquivo hpp
// Classe MemDados
//
// Descrição:
// Essa classe implementa a memória de dados, que é so segundo
//   nível da nossa hierarquia de memória.
// Tudo que ela é responsável por fazer é ser capaz de antender
//   a pedidos de escrita e leitura, simplesmente escreverndo e
//   lendo, não é necessário fazer análises mais profundas.
////////////////////////////////////////////////////////////////

#ifndef MEMDADOS_H
#define MEMDADOS_H

#include "Bloco.hpp"

namespace Computador {

// Dividir memoria em blocos, para garantir consistencia
typedef std::vector<Bloco*> blocos;

	class MemDados {
		public:
			static const unsigned int ktam_memdados = 256;

			MemDados();
			~MemDados();

			Bloco* ler(const unsigned int p_pos);
			void escrever(Bloco* p_bloco);
		private:
			const unsigned int m_bloco_em(const unsigned int p_pos);

			blocos* m_dados;
	};

}

#endif
