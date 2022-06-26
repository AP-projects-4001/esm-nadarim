#include <exception>
#include <string>
#include <functional>

#pragma once

namespace bak {

	class checkPassword {

	public:
		checkPassword(std::string passwordIn);
		
		bool isConfirm();
		std::string getErr();

	private:
		void sizePassword();
		void capitalLetter();
		void smallLetter();
		void numLetter();
		void uperfluousLetter();

		void rangeCondition(const int& minCount, const int& maxCount, std::function<bool()> condition);

		std::string errMessage;
		std::string password;
		char letter;
		bool confirm = true;

		int minSize = 8, maxSize = 20;
		int minCountCapitalLetter = 1, minCountSmallLetter = 1, minCountNumLetter = 1;
		int maxSuperfluousLetter = 0;
		
	};

}