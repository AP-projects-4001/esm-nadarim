#include "filter.h"

void bak::filter::setUserNameSeller(std::string userNameSellerIn) {
	filterProduct.restrictWord(userNameSellerIn, filterProduct.userNameSeller, sizeof(filterProduct.userNameSeller));
}

void bak::filter::setName(std::string nameIn) {
	filterProduct.restrictWord(nameIn, filterProduct.name, sizeof(filterProduct.name));
}

void bak::filter::setGroup(std::string groupIn) {
	filterProduct.restrictWord(groupIn, filterProduct.group, sizeof(filterProduct.group));
}

void bak::filter::setNumber(int minNumberIn, int maxNumberIn) {
	minNumber = minNumberIn;
	maxNumber = maxNumberIn;
	/*todo: check num*/
}

void bak::filter::setPrice(int minPriceIn, int maxPriceIn) {
	minPrice = minPriceIn;
	maxPrice = maxPriceIn;
	/*todo: check num*/
}

void bak::filter::setWeight(int minWeightIn, int maxWeightIn) {
	minWeight = minWeightIn;
	maxWeight = maxWeightIn;
	/*todo: check num*/
}

void bak::filter::setBrand(std::string brandIn) {
	filterProduct.restrictWord(brandIn, filterProduct.brand, sizeof(filterProduct.brand));
}

void bak::filter::setModel(std::string modelIn) {
	filterProduct.restrictWord(modelIn, filterProduct.model, sizeof(filterProduct.model));
}

void bak::filter::setColor(std::string colorIn) {
	filterProduct.restrictWord(colorIn, filterProduct.color, sizeof(filterProduct.color));
}

void bak::filter::setWarranty(std::string warrantyIn) {
	filterProduct.restrictWord(warrantyIn, filterProduct.warranty, sizeof(filterProduct.warranty));
}

std::vector<bak::product> bak::filter::allProducts() {
	fileProduct sellerFile;
	std::vector<bak::product> listOut = sellerFile.searchProduct(filterProduct);
	for (int i = 0; i < listOut.size(); i++) {
		if (!std::string(listOut[i].userNameBuyer).empty()) {
			listOut.erase(listOut.begin() + i);
			i--;
		}
		else if (minNumber != -1) {
			if (listOut[i].number > maxNumber && listOut[i].number < minNumber) {
				listOut.erase(listOut.begin() + i);
				i--;
			}
		}
		else if (minPrice != -1) {
			if (listOut[i].price > maxPrice && listOut[i].price < minPrice) {
				listOut.erase(listOut.begin() + i);
				i--;
			}
		}
		else if (minWeight != -1) {
			if (listOut[i].weight > maxWeight && listOut[i].weight < minWeight) {
				listOut.erase(listOut.begin() + i);
				i--;
			}
		}
	}

	return listOut;
}