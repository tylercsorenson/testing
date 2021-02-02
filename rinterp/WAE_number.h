#ifndef RUDIMENTARY_INTERPRETER_WAE_NUMBER_H
#define RUDIMENTARY_INTERPRETER_WAE_NUMBER_H

#include "WAE.h"

class WAE_number : public WAE {
private:
    int number;

public:
    explicit WAE_number(int number);

    bool operator==(const WAE &other) const override;

    [[nodiscard]] int get_number() const;
};

#endif // RUDIMENTARY_INTERPRETER_WAE_NUMBER_H
