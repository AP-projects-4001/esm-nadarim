#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "product.h"

#pragma once

namespace bak {

	struct fileProduct {

	public:
		fileProduct();
		void addProduct(product newProduct);
		void editProduct(product oldProduct, product newProduct);
		product searchProduct(product productIn);

	private:
		int findEmptySpace();

		std::string addFileProducts = "fProducts.dat";
		int lenghFile;

	};

}