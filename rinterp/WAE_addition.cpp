#include "WAE_addition.h"

WAE_addition::WAE_addition(WAE *lhs, WAE *rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
}

WAE_addition::~WAE_addition() {
    delete lhs;
    delete rhs;
}

bool WAE_addition::operator==(const WAE &other) const {
    const auto other_WAE = dynamic_cast<const WAE_addition *>(&other);
    if (other_WAE) {
        return *(this->lhs) == *(other_WAE->get_lhs()) && *(this->rhs) == *(other_WAE->get_rhs());
    }
    return false;
}

WAE *WAE_addition::get_lhs() const { return lhs; }

WAE *WAE_addition::get_rhs() const { return rhs; }
