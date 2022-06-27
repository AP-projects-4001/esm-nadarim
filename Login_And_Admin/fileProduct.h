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
		void deleteProduct(product productIn);
		void editProduct(product oldProduct, product newProduct);
		std::vector<product> searchProduct(product productIn);

	private:
		int findEmptySpace();

        std::string addresFile = "C:/Users/amirr/Desktop/fProducts.dat";
		int lenghFile;

	};

}
