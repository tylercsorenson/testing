#ifndef RUDIMENTARY_INTERPRETER_WAE_WITH_H
#define RUDIMENTARY_INTERPRETER_WAE_WITH_H

#include "WAE.h"
#include "WAE_x.h"

class WAE_with : public WAE {
private:
    WAE *x;
    WAE *inside;
    WAE *outside;

    WAE *subst(WAE *id, WAE *what) override;

public:
    explicit WAE_with(WAE *x = nullptr, WAE *inside = nullptr, WAE *outside = nullptr);

    ~WAE_with() override;

    [[nodiscard]] WAE *get_x() const;

    [[nodiscard]] WAE *get_inside() const;

    [[nodiscard]] WAE *get_outside() const;

    bool operator==(const WAE &other) const override;

    unsigned solve() override;

    WAE *copy() override;
};

#endif // RUDIMENTARY_INTERPRETER_WAE_WITH_H
