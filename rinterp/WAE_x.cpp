#include "WAE_x.h"
#include <utility>
#include "invalid_calculation.h"

WAE_x::WAE_x(string x) : x(std::move(x)) {}

bool WAE_x::operator==(const WAE &other) const {
    const auto rhs = dynamic_cast<const WAE_x *>(&other);
    if (rhs) {
        return this->x == rhs->get_x();
    }
    return false;
}

string WAE_x::get_x() const { return x; }

unsigned WAE_x::solve() {
    throw invalid_calculation();
}

WAE *WAE_x::subst(WAE *id, WAE *what) {
    if (*this == *id) {
        return what;
    }

    return this;
}
