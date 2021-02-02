#ifndef RUDIMENTARY_INTERPRETER_WAE_X_H
#define RUDIMENTARY_INTERPRETER_WAE_X_H

#include "WAE.h"
#include <string>

using namespace std;

class WAE_x : public WAE {
private:
    std::string x;

public:
    explicit WAE_x(string x);

    bool operator==(const WAE &other) const override;

    [[nodiscard]] string get_x() const;

    unsigned solve() override;

    WAE *subst(WAE *id, WAE *what) override;
};

#endif // RUDIMENTARY_INTERPRETER_WAE_X_H
