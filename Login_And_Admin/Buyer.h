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

		void setUserNameSeller(std::string userNameSellerIn);
		void setName(std::string nameIn);
		void setGroup(std::string groupIn);
		void setNumberSold(int numberIn);
		void setPrice(int priceIn);
		void setWeight(int weightIn);
		void setBrand(std::string brandIn);
		void setModel(std::string modelIn);
		void setColor(std::string colorIn);
		void setWarranty(std::string warrantyIn);

		void buy();
		std::vector<product>allProducts();

	private:
		product buyerProduct;

	};

}