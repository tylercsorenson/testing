#ifndef RUDIMENTARY_INTERPRETER_WAE_ADDITION_H
#define RUDIMENTARY_INTERPRETER_WAE_ADDITION_H

#include "WAE.h"

class WAE_addition : public WAE {
private:
    WAE *lhs;
    WAE *rhs;

public:
    explicit WAE_addition(WAE *lhs = nullptr, WAE *rhs = nullptr);

    ~WAE_addition() override;

    [[nodiscard]] WAE *get_lhs() const;

    [[nodiscard]] WAE *get_rhs() const;

    bool operator==(const WAE &other) const override;
};

#endif // RUDIMENTARY_INTERPRETER_WAE_ADDITION_H
