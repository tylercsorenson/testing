#ifndef RUDIMENTARY_INTERPRETER_TESTER_H
#define RUDIMENTARY_INTERPRETER_TESTER_H

#include "WAE_x.h"
#include "WAE_with.h"
#include "interpreter.h"
#include "invalid_program.h"
#include "invalid_calculation.h"
#include <iostream>
#include <utility>
#include <string>

using namespace std;

class tester {
private:
    static string compare(const WAE *actual, const WAE *expected);

    string confirm_invalid_program(const string &program);

    static string compare_calc(unsigned, unsigned);

    static string confirm_invalid_calculation(WAE *);

    static string compare_subst(WAE *in, WAE *id, WAE *what, WAE *expected);

    interpreter i;

public:
    void test_parse();

    void test_calc();

    static void test_subst();
};

#endif // RUDIMENTARY_INTERPRETER_TESTER_H
