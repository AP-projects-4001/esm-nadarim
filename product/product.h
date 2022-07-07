#pragma once

#include <string>
#include <string>
#pragma warning(disable : 4996)

namespace bak {

	struct product {

	public:
		void restrictWord(std::string wordIn, char* wordOut, int size);

		bool operator==(product& productIn);
		bool operator!=(product& productIn);
		bool operator<=(product comparison);
		bool operator>=(product comparison);

		char userNameSeller[50] = "";
		char userNameBuyer[50] = "";
		char name[50] = "";
		char group[40] = "";
		char brand[40] = "";
		char model[40] = "";
		char color[10] = "";
		char warranty[40] = "";
		int number = -1;
		int price = -1;
		int weight = -1;
		int CountProduct = -1;


	};

}