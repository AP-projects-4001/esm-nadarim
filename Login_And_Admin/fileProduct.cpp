#include "fileProduct.h"



bak::fileProduct::fileProduct() {

    std::fstream start(addresFile, std::ios::app | std::ios::binary);
    start.seekg(0, std::ios::end);
    lenghFile = start.tellg();
    start.close();

    fileEnctyption.setAddresFile(addresFile);
}

void bak::fileProduct::addProduct(product newProduct) {
    int location = findEmptySpace();

    newProduct.CountProduct = (location / (sizeof(product) * sizeof(unsigned int)));

    fileEnctyption.write(reinterpret_cast<const unsigned char*>(&newProduct), sizeof(product), location);
}

void bak::fileProduct::deleteProduct(int CountProductIn) { editProduct(CountProductIn, product()); }

void bak::fileProduct::editProduct(int CountProductIn, product newProduct) {
    int location = (CountProductIn * sizeof(product) * sizeof(unsigned int));
    product search = searchProduct(CountProductIn);

    newProduct.CountProduct = search.CountProduct;

    fileEnctyption.write(reinterpret_cast<const unsigned char*>(&newProduct), sizeof(product), location);
}

std::vector<bak::product> bak::fileProduct::searchProduct(product productIn) {
    int location;
    std::vector<product> listOut;
    product test;

    location = 0;

    while (location != lenghFile) {
        fileEnctyption.read(reinterpret_cast<char*>(&test), sizeof(product), location);

        location += sizeof(product) * sizeof(unsigned int);

        if (test >= productIn && !std::string(test.userNameSeller).empty())
            listOut.push_back(test);
    }

    return listOut;
}

bak::product bak::fileProduct::searchProduct(int CountProductIn) {
    int location = (CountProductIn * sizeof(product) * sizeof(unsigned int));
    product productOut;

    fileEnctyption.read(reinterpret_cast<char*>(&productOut), sizeof(product), location);

    return productOut;
}


int bak::fileProduct::findEmptySpace() {
    int location = 0;
    product test;

    fileEnctyption.read(reinterpret_cast<char*>(&test), sizeof(product), location);

    while (!std::string(reinterpret_cast<const char*>(&test)).empty() && location != lenghFile) {
        location += sizeof(product) * sizeof(unsigned int);
        fileEnctyption.read(reinterpret_cast<char*>(&test), sizeof(product), location);
    }
    return location;
}
