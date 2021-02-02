#ifndef RUDIMENTARY_INTERPRETER_TESTER_H
#define RUDIMENTARY_INTERPRETER_TESTER_H

#include "WAE_x.h"
#include "WAE_with.h"
#include "interpreter.h"
#include "invalid_program.h"
#include <string>

using namespace std;

class tester {
private:
    string compare(const WAE *actual, const WAE *expected);

    string confirm_invalid_program(const string &program);

    interpreter i;

public:
    void test_parse();
};

#endif // RUDIMENTARY_INTERPRETER_TESTER_H
