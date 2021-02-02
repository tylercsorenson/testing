#include "WAE_with.h"

WAE_with::WAE_with(WAE *x, WAE *inside, WAE *outside) {
    this->x = x;
    this->inside = inside;
    this->outside = outside;
}

WAE_with::~WAE_with() {
    delete x;
    x = nullptr;
    delete inside;
    inside = nullptr;
    delete outside;
    outside = nullptr;
}

bool WAE_with::operator==(const WAE &other) const {
    const auto other_WAE = dynamic_cast<const WAE_with *>(&other);
    if (other_WAE) {
        if (x == nullptr || inside == nullptr || outside == nullptr) {
            return false;
        }
        return *(this->x) == *(other_WAE->get_x()) && *(this->inside) == *(other_WAE->get_inside()) &&
               *(this->outside) == *(other_WAE->get_outside());
    }
    return false;
}

WAE *WAE_with::get_x() const {
    return x;
}

WAE *WAE_with::get_inside() const {
    return inside;
}

WAE *WAE_with::get_outside() const {
    return outside;
}

unsigned WAE_with::solve() {
    WAE *x_copy = x->copy();
    WAE *inside_copy = inside->copy();
    WAE *temp = outside->subst(x_copy, inside_copy);
    delete x_copy;
    delete inside_copy;
    delete x;
    x = nullptr;
    delete inside;
    inside = nullptr;
    delete outside;
    outside = nullptr;
    unsigned result = temp->solve();
    delete temp;
    return result;
}

WAE *WAE_with::subst(WAE *id, WAE *what) {
    WAE *x_copy = x->copy();
    WAE *inside_copy = inside->copy();
    WAE *outside_copy = outside->copy();
    if (*x == *id) {
        WAE *temp = inside_copy;
        inside_copy = inside_copy->subst(id, what);
        delete temp;
    } else {
        WAE *temp = inside_copy;
        inside_copy = inside_copy->subst(id, what);
        delete temp;
        temp = outside_copy;
        outside_copy = outside_copy->subst(id, what);
        delete temp;
    }
    return new WAE_with(x_copy, inside_copy, outside_copy);
}

WAE *WAE_with::copy() {
    return new WAE_with(x->copy(), inside->copy(), outside->copy());
}
