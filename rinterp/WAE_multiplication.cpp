#include "WAE_multiplication.h"

WAE_multiplication::WAE_multiplication(WAE *lhs, WAE *rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
}

WAE_multiplication::~WAE_multiplication() {
    delete lhs;
    delete rhs;
}

bool WAE_multiplication::operator==(const WAE &other) const {
    const auto other_WAE = dynamic_cast<const WAE_multiplication *>(&other);
    if (other_WAE) {
        return *(this->lhs) == *(other_WAE->get_lhs()) && *(this->rhs) == *(other_WAE->get_rhs());
    }
    return false;
}

WAE *WAE_multiplication::get_lhs() const { return lhs; }

WAE *WAE_multiplication::get_rhs() const { return rhs; }
