#include "manager.h"

std::vector < bak::product > bak::manager::allTransactions(){
	fileProduct adminFile;
	std::vector<bak::product> listOut = adminFile.searchProduct(transactionsProduct);
	for (int i = 0; i < listOut.size(); i++) {
		if (std::string(listOut[i].userNameBuyer).empty()) {
			listOut.erase(listOut.begin() + i);
			i--;
		}
	}

	return listOut;
}
