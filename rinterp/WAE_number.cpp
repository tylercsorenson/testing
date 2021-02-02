#include "WAE_number.h"

WAE_number::WAE_number(int number) : number(number) {}

bool WAE_number::operator==(const WAE &other) const {
    const auto rhs = dynamic_cast<const WAE_number *>(&other);
    if (rhs) {
        return this->number == rhs->get_number();
    }
    return false;
}

int WAE_number::get_number() const { return number; }
