#pragma once

#include <string>
#include <vector>

#include "product.h"
#include "fileProduct.h"

namespace bak {

    class seller  {

    public:
        seller(std::string userNameSellerIn);

        void setName(std::string nameIn);
        void setGroup(std::string groupIn);
        void setNumberUnsold(int numberIn);
        void setPrice(int priceIn);
        void setWeight(int weightIn);
        void setBrand(std::string brandIn);
        void setModel(std::string modelIn);
        void setColor(std::string colorIn);
        void setWarranty(std::string warrantyIn);

        std::vector<product>allProductsSell();
        std::vector<product>allProductsPurchase();
        void addProduct();
        void deleteProduct(int CountProductIn);
        void editProduct(int CountProductIn);

    private:
        product sellerProduct;
        fileProduct sellerFile;

    };

}
