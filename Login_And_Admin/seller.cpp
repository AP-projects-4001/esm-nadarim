#include "seller.h"

bak::seller::seller(std::string userNameSellerIn) {
    sellerProduct.restrictWord(userNameSellerIn, sellerProduct.userNameSeller, sizeof(sellerProduct.userNameSeller));
}

void bak::seller::setName(std::string nameIn) {
    sellerProduct.restrictWord(nameIn, sellerProduct.name, sizeof(sellerProduct.name));
}

void bak::seller::setGroup(std::string groupIn) {
    sellerProduct.restrictWord(groupIn, sellerProduct.group, sizeof(sellerProduct.group));
}

void bak::seller::setNumberUnsold(int numberIn) { sellerProduct.number = numberIn; }

void bak::seller::setPrice(int priceIn) { sellerProduct.price = priceIn; }

void bak::seller::setWeight(int weightIn) { sellerProduct.weight = weightIn; }

void bak::seller::setBrand(std::string brandIn) {
    sellerProduct.restrictWord(brandIn, sellerProduct.brand, sizeof(sellerProduct.brand));
}

void bak::seller::setModel(std::string modelIn) {
    sellerProduct.restrictWord(modelIn, sellerProduct.model, sizeof(sellerProduct.model));
}

void bak::seller::setColor(std::string colorIn) {
    sellerProduct.restrictWord(colorIn, sellerProduct.color, sizeof(sellerProduct.color));
}

void bak::seller::setWarranty(std::string warrantyIn) {
    sellerProduct.restrictWord(warrantyIn, sellerProduct.warranty, sizeof(sellerProduct.warranty));
}

std::vector<bak::product> bak::seller::allProductsSell() {
    std::vector<bak::product> listOut = sellerFile.searchProduct(sellerProduct);
    for (int i = 0; i < listOut.size(); i++) {
        if (!std::string(listOut[i].userNameBuyer).empty()) {
            listOut.erase(listOut.begin() + i);
            i--;
        }
    }

    return listOut;
}

std::vector<bak::product> bak::seller::allProductsPurchase() {
    std::vector<bak::product> listOut = sellerFile.searchProduct(sellerProduct);
    for (int i = 0; i < listOut.size(); i++) {
        if (std::string(listOut[i].userNameBuyer).empty()) {
            listOut.erase(listOut.begin() + i);
            i--;
        }
    }

    return listOut;
}

void bak::seller::addProduct() { sellerFile.addProduct(sellerProduct); }

void bak::seller::deleteProduct(int CountProductIn) { sellerFile.deleteProduct(CountProductIn); }

void bak::seller::editProduct(int CountProductIn) { sellerFile.editProduct(CountProductIn, sellerProduct); }
