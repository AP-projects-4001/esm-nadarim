#include "findprime.h"

void bak::findPrime::setRange(unsigned int minNumberIn, unsigned int maxNumberIn) {
    minNumber = minNumberIn;
    maxNumber = maxNumberIn;
}

std::vector<unsigned int> bak::findPrime::find() {
    std::vector<unsigned int> listPrime;

    minNumber = convertOdd(minNumber);

    for (unsigned int i = minNumber; i <= maxNumber; i += 2)
        if (isPrime(i))
            listPrime.push_back(i);

    return listPrime;
}

bool bak::findPrime::isPrime(unsigned int numberIn) {
    bool isPrime = true;

    unsigned int maxRange = static_cast<unsigned int>(sqrt(numberIn));

    for (unsigned int j = 2; j <= maxRange; j++) {
        if (numberIn % j == 0) {
            isPrime = false;
            break;
        }
    }

    return isPrime;
}

unsigned int bak::findPrime::convertOdd(unsigned int numberIn) { return (numberIn % 2 == 0) ? numberIn + 1 : numberIn; }
