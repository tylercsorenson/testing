#ifndef RUDIMENTARY_INTERPRETER_WAE_MULTIPLICATION_H
#define RUDIMENTARY_INTERPRETER_WAE_MULTIPLICATION_H

#include "WAE.h"

class WAE_multiplication : public WAE {
private:
    WAE *lhs;
    WAE *rhs;

public:
    explicit WAE_multiplication(WAE *lhs = nullptr, WAE *rhs = nullptr);

    ~WAE_multiplication() override;

    [[nodiscard]] WAE *get_lhs() const;

    [[nodiscard]] WAE *get_rhs() const;

    bool operator==(const WAE &other) const override;

    unsigned solve() override;

    WAE *copy() override;

    WAE *subst(WAE *id, WAE *what) override;
};

#endif // RUDIMENTARY_INTERPRETER_WAE_MULTIPLICATION_H
