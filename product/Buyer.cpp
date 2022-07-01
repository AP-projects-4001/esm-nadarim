#include "Buyer.h"

bak::Buyer::Buyer(std::string userNameBuyer) {
	buyerProduct.restrictWord(userNameBuyer, buyerProduct.userNameBuyer, sizeof(buyerProduct.userNameBuyer));
}

void bak::Buyer::buy(int CountProductIn, int productPurchased){
	fileProduct BuyerFile;
	product productSearch = BuyerFile.searchProduct(CountProductIn);
	
	setBuyerProduct(productSearch);
	buyerProduct.number = productPurchased;


	product editedProduct= productSearch;

	editedProduct.number -= buyerProduct.number;
	BuyerFile.editProduct(CountProductIn, editedProduct);

	BuyerFile.addProduct(buyerProduct);
}

std::vector<bak::product> bak::Buyer::allProducts(){
	fileProduct BuyerFile;
	return BuyerFile.searchProduct(buyerProduct);
}

void bak::Buyer::setBuyerProduct(product productIn){
	buyerProduct.restrictWord(productIn.userNameSeller, buyerProduct.userNameSeller, sizeof(buyerProduct.userNameSeller));
	buyerProduct.restrictWord(productIn.name, buyerProduct.name, sizeof(buyerProduct.name));
	buyerProduct.restrictWord(productIn.group, buyerProduct.group, sizeof(buyerProduct.group));
	buyerProduct.restrictWord(productIn.brand, buyerProduct.brand, sizeof(buyerProduct.brand));
	buyerProduct.restrictWord(productIn.model, buyerProduct.model, sizeof(buyerProduct.model));
	buyerProduct.restrictWord(productIn.color, buyerProduct.color, sizeof(buyerProduct.color));
	buyerProduct.restrictWord(productIn.warranty, buyerProduct.warranty, sizeof(buyerProduct.warranty));
	buyerProduct.price = productIn.price;
	buyerProduct.weight = productIn.weight;
}
