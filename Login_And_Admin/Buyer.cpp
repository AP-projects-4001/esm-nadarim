#include "Buyer.h"

bak::Buyer::Buyer(std::string userNameBuyer) {
	buyerProduct.restrictWord(userNameBuyer, buyerProduct.userNameBuyer, sizeof(buyerProduct.userNameBuyer));
}

void bak::Buyer::setUserNameSeller(std::string userNameSellerIn) {
	buyerProduct.restrictWord(userNameSellerIn, buyerProduct.userNameSeller, sizeof(buyerProduct.userNameSeller));
}

void bak::Buyer::setName(std::string nameIn){
	buyerProduct.restrictWord(nameIn, buyerProduct.name, sizeof(buyerProduct.name));
}

void bak::Buyer::setGroup(std::string groupIn){
	buyerProduct.restrictWord(groupIn, buyerProduct.group, sizeof(buyerProduct.group));
}

void bak::Buyer::setNumberSold(int numberIn){buyerProduct.number = numberIn;/*todo: check num*/ }

void bak::Buyer::setPrice(int priceIn){ buyerProduct.price = priceIn;/*todo: check num*/ }

void bak::Buyer::setWeight(int weightIn){ buyerProduct.weight = weightIn;/*todo: check num*/ }

void bak::Buyer::setBrand(std::string brandIn){
	buyerProduct.restrictWord(brandIn, buyerProduct.brand, sizeof(buyerProduct.brand));
}

void bak::Buyer::setModel(std::string modelIn){
	buyerProduct.restrictWord(modelIn, buyerProduct.model, sizeof(buyerProduct.model));
}

void bak::Buyer::setColor(std::string colorIn){
	buyerProduct.restrictWord(colorIn, buyerProduct.color, sizeof(buyerProduct.color));
}

void bak::Buyer::setWarranty(std::string warrantyIn){
	buyerProduct.restrictWord(warrantyIn, buyerProduct.warranty, sizeof(buyerProduct.warranty));
}

void bak::Buyer::buy(){
	fileProduct BuyerFile;

	product productForSearch = buyerProduct;
	productForSearch.restrictWord("", productForSearch.userNameBuyer, sizeof(productForSearch.userNameBuyer));
	productForSearch.number = -1;

	std::vector<product>productSeller = BuyerFile.searchProduct(productForSearch);
	
	product editedProduct=productSeller[0];
	editedProduct.number -= buyerProduct.number;
	BuyerFile.editProduct(productSeller[0], editedProduct);

	BuyerFile.addProduct(buyerProduct);
}

std::vector<bak::product> bak::Buyer::allProducts(){
	fileProduct BuyerFile;
	return BuyerFile.searchProduct(buyerProduct);
}