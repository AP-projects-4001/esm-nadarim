#include "fileProduct.h"

bak::fileProduct::fileProduct() {

    std::fstream start(addresFile, std::ios::app | std::ios::binary);
    start.seekg(0, std::ios::end);
    lenghFile = start.tellg();
}

void bak::fileProduct::addProduct(product newProduct) {
    int location = findEmptySpace();

    std::fstream fProducts(addresFile, std::ios::in | std::ios::out | std::ios::binary);
    fProducts.seekp(location);

    newProduct.CountProduct = (location / sizeof(product));
    fProducts.write(reinterpret_cast<const char*>(&newProduct), sizeof(product));

    fProducts.close();
}

void bak::fileProduct::deleteProduct(int CountProductIn) { editProduct(CountProductIn, product()); }

void bak::fileProduct::editProduct(int CountProductIn, product newProduct) {
    int location=(CountProductIn *sizeof(product));
    product search = searchProduct(CountProductIn);

    newProduct.CountProduct = search.CountProduct;

    std::fstream edit(addresFile, std::ios::in | std::ios::out | std::ios::binary);
    edit.seekp(location);
    edit.write(reinterpret_cast<const char*>(&newProduct), sizeof(product));
    edit.close();
}

std::vector<bak::product> bak::fileProduct::searchProduct(product productIn) {
    int location;
    std::vector<product> listOut;
    product test;

    std::fstream cearch(addresFile, std::ios::in | std::ios::out | std::ios::binary);
    cearch.seekg(0);
    location = cearch.tellg();

    while (location != lenghFile) {
        cearch.read(reinterpret_cast<char*>(&test), sizeof(product));
        location = cearch.tellg();

        if (test >= productIn && !std::string(test.userNameSeller).empty())
            listOut.push_back(test);
    }

    cearch.close();

    return listOut;
}

bak::product bak::fileProduct::searchProduct(int CountProductIn) {
    int location = (CountProductIn * sizeof(product));
    product productOut;

    std::fstream cearch(addresFile, std::ios::in | std::ios::out | std::ios::binary);
    cearch.seekg(location);
    cearch.read(reinterpret_cast<char*>(&productOut), sizeof(product));
    cearch.close();

    return productOut;
}


int bak::fileProduct::findEmptySpace() {
    int location = 0;
    product test;

    std::fstream findEmpty(addresFile, std::ios::in | std::ios::out | std::ios::binary);
    findEmpty.seekg(0);
    findEmpty.read(reinterpret_cast<char*>(&test), sizeof(product));

    while (!std::string(reinterpret_cast<const char*>(&test)).empty() && location != lenghFile) {
        location = findEmpty.tellg();
        findEmpty.read(reinterpret_cast<char*>(&test), sizeof(product));
    }

    findEmpty.close();
    return location;
}
