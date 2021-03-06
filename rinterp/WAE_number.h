#ifndef RUDIMENTARY_INTERPRETER_WAE_NUMBER_H
#define RUDIMENTARY_INTERPRETER_WAE_NUMBER_H

#include "WAE.h"

class WAE_number : public WAE {
private:
    unsigned number;

public:
    explicit WAE_number(unsigned number);

    ~WAE_number() override;

    bool operator==(const WAE &other) const override;

    [[nodiscard]] unsigned get_number() const;

    unsigned solve() override;

    WAE *copy() override;

    WAE *subst(WAE *id, WAE *what) override;
};

#endif // RUDIMENTARY_INTERPRETER_WAE_NUMBER_H
