#include "WAE_division.h"
WAE_division::WAE_division(WAE *lhs, WAE *rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
}

WAE_division::~WAE_division() {
    delete lhs;
    delete rhs;
}

bool WAE_division::operator==(const WAE &other) const {
    const auto other_WAE = dynamic_cast<const WAE_division *>(&other);
    if (other_WAE) {
        return *(this->lhs) == *(other_WAE->get_lhs()) && *(this->rhs) == *(other_WAE->get_rhs());
    }
    return false;
}

WAE *WAE_division::get_lhs() const { return lhs; }

WAE *WAE_division::get_rhs() const { return rhs; }
