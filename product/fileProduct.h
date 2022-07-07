#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "product.h"

#include "../encryption/fileEnctyption.h"

namespace bak {

	class fileProduct {

	public:
		fileProduct();
		void addProduct(product newProduct);
		void deleteProduct(int CountProductIn);
		void editProduct(int CountProductIn, product newProduct);
		std::vector<product> searchProduct(product productIn);
		product searchProduct(int CountProductIn);

	private:
		int findEmptySpace();

		fileEnctyption fileEnctyption;

		std::string addresFile = "fProducts.dat";
		int lenghFile;

	};

}