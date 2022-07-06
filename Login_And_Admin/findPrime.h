#pragma once

#include <vector>
#include <math.h>

namespace bak {

	class findPrime{

	public:
		void setRange(unsigned int minNumberIn, unsigned int maxNumberIn );
		std::vector<unsigned int> find();

	private:
		bool isPrime(unsigned int numberIn);
		unsigned int convertOdd(unsigned int numberIn);

		unsigned int minNumber = 0, maxNumber = 0;
	};

}