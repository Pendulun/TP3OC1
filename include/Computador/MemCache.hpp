// Projeto TP3OC1 arquivo hpp
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

#ifndef MEMCACHE_H	
#define MEMCACHE_H

#include "Bloco.hpp"
#include "MemDados.hpp"

#include <string>
#include <vector>

namespace Computador{

	class MemCache{
		public:
			static const unsigned int ktam_memcache = 64; // Em blocos

			MemCache();
			~MemCache();
			bool ler(const unsigned int p_pos);
			void escrever(const unsigned int p_pos, std::string p_dado);
		private:
			blocos* m_blocos;
		
			// Pode-se pensar que aqui tem um fio para MemDados.
			// Para propósitos desse trabalho, que não será
			//   sintetizado, não tem problema instanciar MemDados
			//   aqui.
			MemDados* m_MD;
			Bloco* m_ler_MD(const unsigned int p_pos);
			void m_escrever_MD(Bloco* p_bloco);

			// Continhas para MemCache
			// Faz continha para descobrir tag associada ao endereco
			//    dado em p_pos
			static const unsigned int m_calc_tag(const unsigned int p_pos);
			// Faz continha para descobrir bloco correspondente
			//   ao endereço
			static const unsigned int m_bloco_em(const unsigned int p_pos);
			// Faz continha para descobrir palavra no bloco
			//   correspondente a p_posicao
			static const unsigned int m_palavra_em(const unsigned int p_pos);
	};

}

#endif
