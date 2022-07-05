#pragma once

#include <string>
#include <vector>

#include "product.h"
#include "fileProduct.h"
#include "seller.h"

namespace bak {

    class Buyer {

    public:
        Buyer(std::string userNameBuyer);

        void setCountProduct(int countProductIn);
        void setNumberPurchased(int numberPurchasedIn);

        void buy();
        std::vector<product>allProducts();

        bool isPossibleBuy();

    private:
        void findProductSeller();
        void setBuyerProduct();
        void editProductSeller();

        product buyerProduct;
        product sellerProduct;
        fileProduct BuyerFile;
        int countProductPurchased;
    };

}
