#ifndef BLOCO_H
#define BLOCO_H

#include "Palavra.hpp"

#include <vector>

namespace Computador{

typedef std::vector<Palavra*> palavras;

	class Bloco{
		public:
			Bloco();
			~Bloco();

			// get & set
			bool getBitValido();
			palavras* getBloco();
			void setBitValido(bool p_bitValido);
			void setBloco(palavras* p_bloco);

		private:
			static const unsigned int knum_palavras = 4;

			bool m_bitValido;

			palavras* m_bloco;
	};

}

#endif

