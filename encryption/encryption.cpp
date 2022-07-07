#include "encryption.h"

bak::encryption::encryption() {
	keyLocking.numberFirstKey = 7;
	keyLocking.numberSecondKey = 16459;

	keyUnlocking.numberFirstKey = 6943;
	keyUnlocking.numberSecondKey = 16459;
}

std::vector<unsigned int> bak::encryption::lock(std::string wordIn) { return encryptionWord(toVectorUnInt(wordIn), keyLocking); }

unsigned int bak::encryption::lock(unsigned int wordIn) { return encryptionNumber(wordIn, keyLocking); }

std::string bak::encryption::unlock(std::vector<unsigned int> wordIn) { return toString(encryptionWord(wordIn, keyUnlocking)); }

unsigned int bak::encryption::unlock(unsigned int wordIn) { return encryptionNumber(wordIn, keyUnlocking); }

std::vector<unsigned int> bak::encryption::encryptionWord(std::vector<unsigned int> wordIn, keyRsa keyIn) {
	std::vector<unsigned int> wordOut(wordIn.size());

	for (int i = 0; i < wordIn.size(); i++)
		wordOut[i] = encryptionNumber(wordIn[i], keyIn);

	return wordOut;
}

unsigned int bak::encryption::encryptionNumber(int numberIn, keyRsa keyIn) {
	return modular(numberIn, keyIn.numberFirstKey, keyIn.numberSecondKey);
}

unsigned int bak::encryption::modular(int base, unsigned int exp, unsigned int mod) {
	int x = 1;
	int power = base % mod;

	for (int i = 0; i < sizeof(int) * 8; i++) {
		int least_sig_bit = 0x00000001 & (exp >> i);
		if (least_sig_bit)
			x = (x * power) % mod;
		power = (power * power) % mod;
	}

	return x;
}

std::string bak::encryption::toString(std::vector<unsigned int>listIn) { return std::string(listIn.begin(), listIn.end()); }

std::vector<unsigned int> bak::encryption::toVectorUnInt(std::string wordIn) {
	std::vector<unsigned int> listOut(wordIn.size());
	for (int i = 0; i < wordIn.size(); i++) { listOut[i] = wordIn[i]; }
	return listOut;
}