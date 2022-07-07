#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "encryption.h"

namespace bak {

	class fileEnctyption {

	public:
		void setAddresFile(std::string addresFileIn);

		void write(const char* wordIn, unsigned int sizeWord, unsigned int location);
		void read(char* wordOut, unsigned int sizeWord, unsigned int location);

	private:

		bak::encryption encryptionFile;

		std::string addresFile;
	};

}