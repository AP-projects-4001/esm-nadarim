#include "fileProduct.h"

bak::fileProduct::fileProduct() {

	std::fstream start(addFileProducts, std::ios::app | std::ios::binary);
	start.seekg(0, std::ios::end);
	lenghFile = start.tellg();
}

void bak::fileProduct::addProduct(product newProduct) {
	int location = findEmptySpace();

	std::fstream fProducts(addFileProducts, std::ios::in | std::ios::out | std::ios::binary);
	fProducts.seekp(location);
	fProducts.write(reinterpret_cast<const char*>(&newProduct), sizeof(product));

	fProducts.close();
}

void bak::fileProduct::editProduct(product oldProduct, product newProduct) {}

//bak::product bak::fileProduct::searchProduct(product productIn) {
//	int location;
//	std::vector<product> listOut;
//	product test;
//
//	std::fstream cearch(addFileProducts, std::ios::in | std::ios::out | std::ios::binary);
//	cearch.seekg(0);
//
//	while (test== productIn && location != lenghFile) {
//		location = cearch.tellg();
//		cearch.read(reinterpret_cast<char*>(&test), sizeof(product));
//	}
//
//	return ;
//}


int bak::fileProduct::findEmptySpace() {
	int location = 0;
	product test;

	std::fstream findEmpty(addFileProducts, std::ios::in | std::ios::out | std::ios::binary);
	findEmpty.seekg(0);
	findEmpty.read(reinterpret_cast<char*>(&test), sizeof(product));

	while (!std::string(test.userNameSeller).empty() && location != lenghFile) {
		location = findEmpty.tellg();
		findEmpty.read(reinterpret_cast<char*>(&test), sizeof(product));
	}

	findEmpty.close();
	return location;
}
