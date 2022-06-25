#include "checkpassword.h"

#include <exception>
#include <string>
#include <functional>
#include <QString>


bak::checkPassword::checkPassword(std::string passwordIn)
    :password(passwordIn) {

    try {
        sizePassword();
        capitalLetter();
        smallLetter();
        numLetter();
        uperfluousLetter();

        errMessage = "";
    }
    catch (std::string err) {
        errMessage = err;
        confirm = false;
    }
}

bool bak::checkPassword::isConfirm(){return confirm;}

std::string bak::checkPassword::getErr() { return errMessage; }

void bak::checkPassword::sizePassword() {
    errMessage = "The password must be more than " + std::to_string(minSize)
        + (std::string)" and less than " + std::to_string(maxSize) + (std::string)" characters";

    if (password.size() < minSize || password.size() > maxSize)
        throw errMessage;
}

void bak::checkPassword::capitalLetter() {
    errMessage = (std::string)"The password must contain at least " + std::to_string(minCountCapitalLetter)
        + (std::string)" capital letter";

    std::function<bool()> condition = [&]()->bool {
        return (letter >= 'A' && letter <= 'Z');
    };
    rangeCondition(minCountCapitalLetter, -1, condition);
}

void bak::checkPassword::smallLetter() {
    errMessage = (std::string)"The password must contain at least " + std::to_string(minCountSmallLetter)
        + (std::string)" Small letter";

    std::function<bool()> condition = [&]()->bool {
        return (letter >= 'a' && letter <= 'z');
    };
    rangeCondition(minCountSmallLetter, -1, condition);
}

void bak::checkPassword::numLetter() {
    errMessage = (std::string)"The password must contain at least " + std::to_string(minCountNumLetter)
        + (std::string)" number";

    std::function<bool()> condition = [&]()->bool {
        return (letter >= '0' && letter <= '9');
    };
    rangeCondition(minCountNumLetter, -1, condition);
}

void bak::checkPassword::uperfluousLetter() {
    errMessage = "The password must contain number and small and capital letters in English";

    std::function<bool()> condition = [&]()->bool {
        return !(letter >= 'A' && letter <= 'Z') && !(letter >= 'a' && letter <= 'z') && !(letter >= '0' && letter <= '9');
    };
    rangeCondition(-1, maxSuperfluousLetter, condition);
}

void bak::checkPassword::rangeCondition(const int& minCount, const int& maxCount, std::function<bool()> condition) {

    int countNumber = 0;

    for (int i = 0; i < password.size(); i++) {
        letter = password[i];
        if (condition())
            countNumber++;
    }

    if (minCount != -1)
        if (countNumber < minCount)
            throw errMessage;
    if (maxCount != -1)
        if (countNumber > maxCount)
            throw errMessage;
}
