#pragma once

#include <string>
#include <vector>

#include "product.h"
#include "fileProduct.h"

namespace bak {

    class filter {

    public:
        void setUserNameSeller(std::string userNameSellerIn);
        void setName(std::string nameIn);
        void setGroup(std::string groupIn);
        void setBrand(std::string brandIn);
        void setModel(std::string modelIn);
        void setColor(std::string colorIn);
        void setWarranty(std::string warrantyIn);
        void setNumber(int minNumberIn, int maxNumberIn);
        void setPrice(int minPriceIn, int maxPriceIn);
        void setWeight(int minWeightIn, int maxWeightIn);

        std::vector<product>allProducts();

    private:
        product filterProduct;
        fileProduct sellerFile;

        int minNumber=-1, maxNumber=-1;
        int minPrice=-1, maxPrice=-1;
        int minWeight=-1, maxWeight =-1;

    };

}
