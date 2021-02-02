#ifndef RUDIMENTARY_INTERPRETER_WAE_SUBTRACTION_H
#define RUDIMENTARY_INTERPRETER_WAE_SUBTRACTION_H

#include "WAE.h"

class WAE_subtraction : public WAE {
private:
    WAE *lhs;
    WAE *rhs;

public:
    explicit WAE_subtraction(WAE *lhs = nullptr, WAE *rhs = nullptr);

    ~WAE_subtraction() override;

    [[nodiscard]] WAE *get_lhs() const;

    [[nodiscard]] WAE *get_rhs() const;

    bool operator==(const WAE &other) const override;

    unsigned solve() override;

    WAE *subst(WAE *id, WAE *what) override;
};

#endif // RUDIMENTARY_INTERPRETER_WAE_SUBTRACTION_H
