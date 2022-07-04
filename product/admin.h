#pragma once

#include <string>
#include <vector>

#include "product.h"
#include "fileProduct.h"

namespace bak {

	class admin {

	public:
		std::vector<product>allTransactions();

	private:
		product transactionsProduct;
		fileProduct adminFile;

	};

}