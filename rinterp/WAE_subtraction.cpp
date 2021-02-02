#include "WAE_subtraction.h"
#include "invalid_calculation.h"

WAE_subtraction::WAE_subtraction(WAE *lhs, WAE *rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
}

WAE_subtraction::~WAE_subtraction() {
    delete lhs;
    lhs = nullptr;
    delete rhs;
    rhs = nullptr;
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

unsigned WAE_subtraction::solve() {
    unsigned left = lhs->solve();
    unsigned right = rhs->solve();

    if (right >= left) {
        throw invalid_calculation();
    }

    return left - right;
}

WAE *WAE_subtraction::subst(WAE *id, WAE *what) {
    WAE *temp = lhs->subst(id, what);
    delete lhs;
    lhs = temp;
    temp = rhs->subst(id, what);
    delete rhs;
    rhs = temp;
    return this;
}
