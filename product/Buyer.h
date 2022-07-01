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

		void buy(int CountProductIn, int productPurchased);
		std::vector<product>allProducts();

	private:
		void setBuyerProduct(product productIn);

		product buyerProduct;

	};

}