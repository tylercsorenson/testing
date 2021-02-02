#ifndef RUDIMENTARY_INTERPRETER_INTERPRETER_H
#define RUDIMENTARY_INTERPRETER_INTERPRETER_H

#include "WAE_addition.h"
#include "WAE_subtraction.h"
#include "WAE_multiplication.h"
#include "WAE_division.h"
#include "WAE_number.h"
#include "WAE_x.h"
#include "WAE_with.h"
#include <string>

using namespace std;

class interpreter {
private:
    void subst();

    bool check_parens(const string &program);

    int get_expression_length(const string &input);

    int get_with_brackets_length(const string &input);

    int get_sequence_length(const string &input);

    WAE *build_x(const string &program);

    void build_expression(const string &program, unsigned index, WAE *&lhs, WAE *&rhs);

    void build_inbetween_brackets(const string &excerpt, WAE *&x, WAE *&inside);

public:
    WAE *parse(string program);

    int calc(WAE *input);
};

#endif // RUDIMENTARY_INTERPRETER_INTERPRETER_H
