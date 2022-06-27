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
	fProducts.write(reinterpret_cast<const char*>(&newProduct), sizeof(product));

	fProducts.close();
}

void bak::fileProduct::deleteProduct(product productIn) {

	editProduct(productIn, product());

}

void bak::fileProduct::editProduct(product oldProduct, product newProduct) {
	int location;
	product test;
	bool isFinded = false;

	std::fstream cearch(addresFile, std::ios::in | std::ios::out | std::ios::binary);
	cearch.seekg(0);
	location = cearch.tellg();

	while (location != lenghFile) {
		location = cearch.tellg();
		cearch.read(reinterpret_cast<char*>(&test), sizeof(product));

		if (test == oldProduct) {
			isFinded = true;
			break;
		}
	}

	cearch.close();

	if (isFinded) {
		std::fstream edit(addresFile, std::ios::in | std::ios::out | std::ios::binary);
		edit.seekp(location);
		edit.write(reinterpret_cast<const char*>(&newProduct), sizeof(product));
		edit.close();
	}
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

		if (test >= productIn)
			listOut.push_back(test);
	}

	cearch.close();

	return listOut;
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
