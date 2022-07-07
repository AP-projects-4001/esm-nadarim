#include "fileenctyption.h"



void bak::fileEnctyption::setAddresFile(std::string addresFileIn) { addresFile = addresFileIn; }

void bak::fileEnctyption::write(const unsigned char* wordIn, unsigned int sizeWord, unsigned int location) {
    std::fstream fileWrite(addresFile, std::ios::in | std::ios::out | std::ios::binary);
    fileWrite.seekp(location);

    unsigned int letter;
    for (unsigned int i = 0; i < sizeWord; i++) {
        letter = encryptionFile.lock(wordIn[i]);
        fileWrite.write((char*)&letter, sizeof(letter));
    }
    fileWrite.close();
}

void bak::fileEnctyption::read(char* wordOut, unsigned int sizeWord, unsigned int location) {
    std::fstream fileRead(addresFile, std::ios::in | std::ios::out | std::ios::binary);
    fileRead.seekg(location);

    unsigned int letter;
    for (unsigned int i = 0; i < sizeWord; i++) {
        fileRead.read((char*)&letter, sizeof(letter));
        wordOut[i] = encryptionFile.unlock(letter);
    }
    fileRead.close();
}
