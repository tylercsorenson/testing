#include "WAE_with.h"

WAE_with::WAE_with(WAE *x, WAE *inside, WAE *outside) {
    this->x = x;
    this->inside = inside;
    this->outside = outside;
}

WAE_with::~WAE_with() {
    delete x;
    delete inside;
    delete outside;
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
