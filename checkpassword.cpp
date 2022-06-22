#include "checkpassword.h"
#include <exception>


bak::CheckPassword::CheckPassword(std::string passwordIn)
    :password(passwordIn) {

    try {
        sizePassword();
        capitalLetter();
        smallLetter();
        numLetter();
        uperfluousLetter();
    }
    catch (std::exception e) {
        errMessage = e.what();
        confirm = false;
    }
}

bool bak::CheckPassword::isConfirm(){return confirm;}

std::string bak::CheckPassword::getErr() { return errMessage; }

void bak::CheckPassword::sizePassword() {
    errMessage = (std::string)"The password must be more than " + std::to_string(minSize)
        + (std::string)" and less than " + std::to_string(maxSize) + (std::string)" characters";

    if (password.size() < minSize || password.size() > maxSize)
        throw std::exception(errMessage.c_str());
}

void bak::CheckPassword::capitalLetter() {
    errMessage = (std::string)"The password must contain at least " + std::to_string(minCountCapitalLetter)
        + (std::string)" capital letter";

    std::function<bool()> condition = [&]()->bool {
        return (letter >= 'A' && letter <= 'Z');
    };
    rangeCondition(minCountCapitalLetter, NULL, condition);
}

void bak::CheckPassword::smallLetter() {
    errMessage = (std::string)"The password must contain at least " + std::to_string(minCountSmallLetter)
        + (std::string)" Small letter";

    std::function<bool()> condition = [&]()->bool {
        return (letter >= 'a' && letter <= 'z');
    };
    rangeCondition(minCountSmallLetter, NULL, condition);
}

void bak::CheckPassword::numLetter() {
    errMessage = (std::string)"The password must contain at least " + std::to_string(minCountNumLetter)
        + (std::string)" number";

    std::function<bool()> condition = [&]()->bool {
        return (letter >= '0' && letter <= '9');
    };
    rangeCondition(minCountNumLetter, NULL, condition);
}

void bak::CheckPassword::uperfluousLetter() {
    errMessage = "The password must contain number and small and capital letters in English";

    std::function<bool()> condition = [&]()->bool {
        return !(letter >= 'A' && letter <= 'Z') && !(letter >= 'a' && letter <= 'z') && !(letter >= '0' && letter <= '9');
    };
    rangeCondition(NULL, maxSuperfluousLetter, condition);
}

void bak::checkPassword::rangeCondition(const int& minCount, const int& maxCount, std::function<bool()> condition) {

    int countNumber = 0;

    for (int i = 0; i < password.size(); i++) {
        char letter = password[i];
        if (condition())
            countNumber++;
    }

    if (minCount != NULL)
        if (countNumber < minCount)
            throw std::exception(errMessage.c_str());
    if (maxCount != NULL)
        if (countNumber > maxCount)
            throw std::exception(errMessage.c_str());
}
