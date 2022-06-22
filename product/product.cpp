#include "product.h"

void bak::product::setUserNameSeller(std::string userNameSellerIn) {

	
	restrictWord(userNameSellerIn, userNameSeller, sizeof(userNameSeller));

}

void bak::product::setUserNameShopper(std::string userNameShopperIn) {


	restrictWord(userNameShopperIn, userNameShopper, sizeof(userNameShopper));


}

void bak::product::setName(std::string nameIn) {


	restrictWord(nameIn, name, sizeof(name));


}

void bak::product::setGroup(std::string groupIn) {

	restrictWord(groupIn, group, sizeof(group));


}

void bak::product::setNumber(int numberIn) {

	number = numberIn;

	//todo: check num

}

void bak::product::setPrice(int priceIn) {

	price = priceIn;
	//todo: check num


}

void bak::product::setWeight(int weightIn) {


	weight = weightIn;
	//todo: check num

}

void bak::product::setBrand(std::string brandIn) {

	restrictWord(brandIn, brand, sizeof(brand));


}

void bak::product::setModel(std::string modelIn) {

	restrictWord(modelIn, model, sizeof(model));


}

void bak::product::setColor(std::string colorIn) {

	restrictWord(colorIn, color, sizeof(color));


}

void bak::product::setWarranty(std::string warrantyIn) {

	restrictWord(warrantyIn, warranty, sizeof(warranty));


}

bool bak::product::operator==(product& productIn){
	if (std::string(this->userNameSeller) != std::string(productIn.userNameSeller))
		return false;
	if (std::string(this->userNameShopper) != std::string(productIn.userNameShopper))
		return false;
	if (std::string(this->name) != std::string(productIn.name))
		return false;
	if (std::string(this->group) != std::string(productIn.group))
		return false;
	if (std::string(this->brand) != std::string(productIn.brand))
		return false;
	if (std::string(this->model) != std::string(productIn.model))
		return false;
	if (std::string(this->color) != std::string(productIn.color))
		return false;
	if (std::string(this->warranty) != std::string(productIn.warranty))
		return false;
	if (this->number != productIn.number)
		return false;
	if (this->price != productIn.price)
		return false;
	if (this->weight != productIn.weight)
		return false;

	return true;
}

void bak::product::restrictWord(std::string wordIn, char* wordOut, int size) {

	int length = wordIn.size();
	length = (length < (size - 1) ? length : (size - 1));
	wordIn[length] = '\0';

	const char* word = wordIn.data();

	strncpy_s(wordOut, (length+1),word, length);
}
