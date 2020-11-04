#ifndef BLOCO_H
#define BLOCO_H

#include "Palavra.hpp"

#include <vector>

namespace Computador{

typedef std::vector<Palavra*> palavras;

	class Bloco{
		public:
			static const unsigned int ktam_bloco = 4;

			Bloco();
			~Bloco();

			// get & set
			bool getBitValido();
			void setBitValido(bool p_bitValido);
			bool getBitSujo();
			void setBitSujo(bool p_bitSujo);
			const unsigned int getTag();
			void setTag(const unsigned int p_tag);
			palavras* getBloco();
			void setBloco(palavras* p_bloco);
			void setBloco(Bloco* p_bloco); // Copy

		private:
			bool m_bitValido;
			bool m_bitSujo;
			unsigned int m_tag;

			palavras* m_bloco;
	};

}

#endif

