#include "WAE_subtraction.h"

WAE_subtraction::WAE_subtraction(WAE *lhs, WAE *rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
}

WAE_subtraction::~WAE_subtraction() {
    delete lhs;
    delete rhs;
}

bool WAE_subtraction::operator==(const WAE &other) const {
    const auto other_WAE = dynamic_cast<const WAE_subtraction *>(&other);
    if (other_WAE) {
        return *(this->lhs) == *(other_WAE->get_lhs()) && *(this->rhs) == *(other_WAE->get_rhs());
    }
    return false;
}

WAE *WAE_subtraction::get_lhs() const { return lhs; }

WAE *WAE_subtraction::get_rhs() const { return rhs; }
