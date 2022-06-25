#pragma once

#include <string>
#include <vector>

#include "product.h"
#include "fileProduct.h"

namespace bak {

    class manager {

	public:
		std::vector<product>allTransactions();

	private:
		product transactionsProduct;

	};

}
