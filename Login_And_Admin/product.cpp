#include "product.h"
#include <cstring>


bool bak::product::operator==(product& productIn) {
    if (std::string(this->userNameSeller) != std::string(productIn.userNameSeller))
        return false;
    if (std::string(this->userNameBuyer) != std::string(productIn.userNameBuyer))
        return false;
    if (std::string(this->name) != std::string(productIn.name))
        return false;
    if (std::string(this->group) != std::string(productIn.group))
        return false;
    if (std::string(this->brand) != std::string(productIn.brand))
        return false;
    if (std::string(this->model) != std::string(productIn.model))
        return false;
    if (std::string(this->color) != std::string(productIn.color))
        return false;
    if (std::string(this->warranty) != std::string(productIn.warranty))
        return false;
    if (this->number != productIn.number)
        return false;
    if (this->price != productIn.price)
        return false;
    if (this->weight != productIn.weight)
        return false;

    return true;
}

bool bak::product::operator!=(product& productIn) { return (*this == productIn) ? false : true; }

bool bak::product::operator<=(product comparison) {

    if (!std::string(this->userNameSeller).empty()
        && std::string(this->userNameSeller) != std::string(comparison.userNameSeller))
        return false;
    if (!std::string(this->userNameBuyer).empty()
        && std::string(this->userNameBuyer) != std::string(comparison.userNameBuyer))
        return false;
    if (!std::string(this->name).empty()
        && std::string(this->name) != std::string(comparison.name))
        return false;
    if (!std::string(this->group).empty()
        && std::string(this->group) != std::string(comparison.group))
        return false;
    if (!std::string(this->brand).empty()
        && std::string(this->brand) != std::string(comparison.brand))
        return false;
    if (!std::string(this->model).empty()
        && std::string(this->model) != std::string(comparison.model))
        return false;
    if (!std::string(this->color).empty()
        && std::string(this->color) != std::string(comparison.color))
        return false;
    if (!std::string(this->warranty).empty()
        && std::string(this->warranty) != std::string(comparison.warranty))
        return false;
    if (this->number != -1 && this->number != comparison.number)
        return false;
    if (this->price != -1 && this->price != comparison.price)
        return false;
    if (this->weight != -1 && this->weight != comparison.weight)
        return false;

    return true;
}

bool bak::product::operator>=(product comparison) { return (comparison <= *this); }

void bak::product::restrictWord(std::string wordIn, char* wordOut, int size) {

    int length = wordIn.size();
    length = (length < (size - 1) ? length : (size - 1));
    wordIn[length] = '\0';

    if (wordIn != "") {
        const char* word = wordIn.data();
        strncpy(wordOut, word, length);
    }
    else
        wordOut[0] = '\0';
}
