#include "generatingKey.h"

void bak::generatingKey::setNumbersPrime(unsigned int numberFirsPrimeIn, unsigned int numberSecondPrimeIn) {
	numberFirsPrime = numberFirsPrimeIn;
	numberSecondPrime = numberSecondPrimeIn;
}

void bak::generatingKey::makeKeys() {

	number_n = calculate_n();
	number_phi_n = calculate_phi_n();

	number_n = calculate_n();
	number_e = calculate_e();
	number_d = calculate_d();

	keyLocking.numberFirstKey = number_e;
	keyLocking.numberSecondKey = number_n;
	keyUnlocking.numberFirstKey = number_d;
	keyUnlocking.numberSecondKey = number_n;

}

unsigned int bak::generatingKey::calculate_n() { return (numberFirsPrime * numberSecondPrime); }

unsigned int bak::generatingKey::calculate_e() {
	unsigned int i = 2;
	while (gcd(i, number_phi_n) != 1)
		i++;

	if (i > number_phi_n)
		return 0;
	else
		return i;
}

unsigned int bak::generatingKey::calculate_d() {
	unsigned int k = 1;

	while (((k * number_phi_n) + 1) % number_e != 0) { k++; }

	int d = ((k * number_phi_n) + 1) / number_e;

	return d;
}

unsigned int bak::generatingKey::calculate_phi_n() { return ((numberFirsPrime - 1) * (numberSecondPrime - 1)); }

int bak::generatingKey::gcd(int num1, int num2) {
	int maxNum, minNum, tempNum;

	if (num1 > num2) {
		maxNum = num1;
		minNum = num2;
	}
	else {
		maxNum = num2;
		minNum = num1;
	}
	while (minNum != 0) {
		tempNum = maxNum % minNum;
		maxNum = minNum;
		minNum = tempNum;
	}
	return maxNum;
}
