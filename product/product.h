#include <string>
#pragma once

namespace bak {

	struct product {

	public:
		void setUserNameSeller(std::string userNameSellerIn);
		void setUserNameShopper(std::string userNameShopperIn);
		void setName(std::string nameIn);
		void setGroup(std::string groupIn);
		void setNumber(int numberIn);
		void setPrice(int priceIn);
		void setWeight(int weightIn);
		void setBrand(std::string brandIn);
		void setModel(std::string modelIn);
		void setColor(std::string colorIn);
		void setWarranty(std::string warrantyIn);

		bool operator==(product& productIn);

		char userNameSeller[50]="";
		char userNameShopper[50]="";
		char name[50]="";
		char group[40]="";
		char brand[40]="";
		char model[40]="";
		char color[10]="";
		char warranty[40]="";
		int number = -1;
		int price = -1;
		int weight = -1;

	private:
		void restrictWord(std::string wordIn, char* wordOut, int size);
	
	};

}