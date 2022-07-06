#pragma once

#include <vector>
#include <bitset>
#include <math.h>
#include <string>

#include "keyRsa.h"

namespace bak {

	class encryption {

	public:
		encryption();

		std::vector<unsigned int> lock(std::string wordIn);
		std::string unlock(std::vector<unsigned int> wordIn);


	private:
		std::vector<unsigned int> encryptionWord(std::vector<unsigned int> wordIn, keyRsa keyIn);
		unsigned int encryptionNumber(int numberIn, keyRsa keyIn);

		unsigned int modular(int base, unsigned int exp, unsigned int mod);

		std::string toString(std::vector<unsigned int> listIn);
		std::vector<unsigned int> toVectorUnInt(std::string wordIn);

		keyRsa keyLocking;
		keyRsa keyUnlocking;
	};

}