#include "WAE_division.h"

WAE_division::WAE_division(WAE *lhs, WAE *rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
}

WAE_division::~WAE_division() {
    delete lhs;
    lhs = nullptr;
    delete rhs;
    rhs = nullptr;
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

unsigned WAE_division::solve() {
    unsigned left = lhs->solve();
    unsigned right = rhs->solve();
    if (right == 0) {
        throw invalid_calculation();
    }
    delete lhs;
    lhs = nullptr;
    delete rhs;
    rhs = nullptr;
    return left / right;
}

WAE *WAE_division::subst(WAE *id, WAE *what) {
    WAE *temp = new WAE_division(lhs->subst(id, what), rhs->subst(id, what));
    delete lhs;
    lhs = nullptr;
    delete rhs;
    rhs = nullptr;
    return temp;
}

WAE *WAE_division::copy() {
    return new WAE_division(lhs->copy(), rhs->copy());
}
