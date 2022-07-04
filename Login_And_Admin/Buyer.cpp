#include "Buyer.h"

bak::Buyer::Buyer(std::string userNameBuyer) {
    buyerProduct.restrictWord(userNameBuyer, buyerProduct.userNameBuyer, sizeof(buyerProduct.userNameBuyer));
}

void bak::Buyer::setCountProduct(int countProductIn) {
    countProductPurchased = countProductIn;
    findProductSeller();
}

void bak::Buyer::setNumberPurchased(int numberPurchasedIn) { buyerProduct.number = numberPurchasedIn; }

void bak::Buyer::buy() {
    setBuyerProduct();
    editProductSeller();
    BuyerFile.addProduct(buyerProduct);
}

std::vector<bak::product> bak::Buyer::allProducts() {
    fileProduct BuyerFile;
    return BuyerFile.searchProduct(buyerProduct);
}

bool bak::Buyer::isPossibleBuy() { return (sellerProduct.number >= buyerProduct.number); }

void bak::Buyer::findProductSeller() {
    product search = BuyerFile.searchProduct(countProductPurchased);
    if (std::string(search.userNameBuyer).empty())
        sellerProduct = search;
}

void bak::Buyer::setBuyerProduct() {
    std::string tempUserNameBuyer = buyerProduct.userNameBuyer;
    int tempNumberPurchased = buyerProduct.number;
    buyerProduct = sellerProduct;

    buyerProduct.restrictWord(tempUserNameBuyer, buyerProduct.userNameBuyer, sizeof(buyerProduct.userNameBuyer));
    buyerProduct.number = tempNumberPurchased;
}

void bak::Buyer::editProductSeller() {
    sellerProduct.number -= buyerProduct.number;
    BuyerFile.editProduct(countProductPurchased, sellerProduct);
}
