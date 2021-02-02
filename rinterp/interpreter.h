#ifndef RUDIMENTARY_INTERPRETER_INTERPRETER_H
#define RUDIMENTARY_INTERPRETER_INTERPRETER_H

#include "WAE_addition.h"
#include "WAE_subtraction.h"
#include "WAE_multiplication.h"
#include "WAE_division.h"
#include "WAE_number.h"
#include "WAE_x.h"
#include "WAE_with.h"
#include "invalid_calculation.h"
#include <stack>
#include <istream>
#include <string>

using namespace std;

class interpreter {
private:
    static bool check_parens(const string &program);

    static int get_expression_length(const string &input);

    static int get_with_brackets_length(const string &input);

    static int get_sequence_length(const string &input);

    static WAE *build_x(const string &program);

    void build_expression(const string &program, unsigned index, WAE *&lhs, WAE *&rhs);

    void build_inbetween_brackets(const string &excerpt, WAE *&x, WAE *&inside);

public:
    WAE *parse(string program);

    static unsigned calc(WAE *input);
};

#endif // RUDIMENTARY_INTERPRETER_INTERPRETER_H
