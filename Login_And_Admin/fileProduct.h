#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "product.h"

namespace bak {

    struct fileProduct {

    public:
        fileProduct();
        void addProduct(product newProduct);
        void deleteProduct(int CountProductIn);
        void editProduct(int CountProductIn, product newProduct);
        std::vector<product> searchProduct(product productIn);
        product searchProduct(int CountProductIn);

    private:
        int findEmptySpace();

        std::string addresFile = "fProducts.dat";
        int lenghFile;

    };

}
