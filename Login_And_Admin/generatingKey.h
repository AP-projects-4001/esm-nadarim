#ifndef GENERATINGKEY_H
#define GENERATINGKEY_H


#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>

#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>
#include <algorithm>
//#include <cstdlib>
//#include <time.h>

#include "keyRsa.h"

namespace bak {

    class generatingKey {
    public:

        void setNumbersPrime(unsigned int numberFirsPrimeIn, unsigned int numberSecondPrimeIn);

        void makeKeys();

        keyRsa keyLocking;
        keyRsa keyUnlocking;
    private:


        unsigned int calculate_n();;

        unsigned int calculate_e();
        unsigned int calculate_d();

        unsigned int calculate_phi_n();

        int gcd(int num1, int num2);

        unsigned int numberFirsPrime, numberSecondPrime;

        unsigned int number_n=0;
        unsigned int number_phi_n=0;
        unsigned int number_e=0;
        unsigned int number_d=0;

    };

}

#endif // GENERATINGKEY_H
