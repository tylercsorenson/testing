#ifndef RUDIMENTARY_INTERPRETER_WAE_DIVISION_H
#define RUDIMENTARY_INTERPRETER_WAE_DIVISION_H

#include "WAE.h"

class WAE_division : public WAE {
private:
    WAE *lhs;
    WAE *rhs;

public:
    explicit WAE_division(WAE *lhs = nullptr, WAE *rhs = nullptr);

    ~WAE_division() override;

    [[nodiscard]] WAE *get_lhs() const;

    [[nodiscard]] WAE *get_rhs() const;

    bool operator==(const WAE &other) const override;
};

#endif // RUDIMENTARY_INTERPRETER_WAE_DIVISION_H
