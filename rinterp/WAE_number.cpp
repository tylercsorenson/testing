#include "WAE_number.h"

WAE_number::WAE_number(unsigned number) : number(number) {}

bool WAE_number::operator==(const WAE &other) const {
    const auto rhs = dynamic_cast<const WAE_number *>(&other);
    if (rhs) {
        return this->number == rhs->get_number();
    }
    return false;
}

unsigned WAE_number::get_number() const { return number; }

unsigned WAE_number::solve() {
    return number;
}

WAE *WAE_number::subst(WAE *id, WAE *what) {
    return new WAE_number(number);
}

WAE_number::~WAE_number() = default;

WAE *WAE_number::copy() {
    return new WAE_number(number);
}
