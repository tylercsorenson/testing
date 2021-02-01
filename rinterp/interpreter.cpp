#include "invalid_program.h"
#include <istream>

#include "interpreter.h"
#include <stack>

WAE *interpreter::parse(string program) {
    int index = 0;
    if (isdigit(program.at(index))) {
        for (char c : program) {
            if (!isdigit(c)) {
                throw invalid_program();
            }
        }
        double value = stod(program);
        if (value == 0) {
            throw invalid_program();
        }
        return new WAE_number(value);
    } else if (isalpha(program.at(index))) {
        if (program == "with") {
            throw invalid_program();
        }
        for (char c : program) {
            if (!isalpha(c)) {
                throw invalid_program();
            }
        }
        return new WAE_x(program);
    } else if (program.at(index) == '(') {
        WAE *lhs = nullptr;
        WAE *rhs = nullptr;
        if (!check_parens(program)) {
            throw invalid_program();
        }
        index++;
        if (program.at(index) == '+') {
            build_expression(program, index, lhs, rhs);
            return new WAE_addition(lhs, rhs);
        } else if (program.at(index) == '-') {
            build_expression(program, index, lhs, rhs);
            return new WAE_subtraction(lhs, rhs);
        } else if (program.at(index) == '*') {
            build_expression(program, index, lhs, rhs);
            return new WAE_multiplication(lhs, rhs);
        } else if (program.at(index) == '/') {
            build_expression(program, index, lhs, rhs);
            return new WAE_division(lhs, rhs);
        } else if (program.length() >= 5 && program.substr(index, 4) == "with") {
        }
    }
    throw invalid_program();
}

double interpreter::calc(WAE *input) { return 0; }

bool interpreter::check_parens(const string &program) {
    stack<char> paren_stack;
    for (char c : program) {
        if (c == '(') {
            paren_stack.emplace(c);
        } else if (c == ')') {
            if (paren_stack.empty()) {
                return false;
            }
            paren_stack.pop();
        }
    }
    return true;
}

int interpreter::get_expression_length(const string &input) {
    stack<char> paren_stack;
    int length = 0;
    for (char c : input) {
        length++;
        if (c == '(') {
            paren_stack.emplace(c);
        } else if (c == ')') {
            if (paren_stack.empty()) {
                return false;
            }
            paren_stack.pop();
            if (paren_stack.empty()) {
                return length;
            }
        }
    }
    return length;
}

int interpreter::get_sequence_length(const string &input) {
    int length = 0;
    for (char c : input) {
        if (isspace(c) || c == ')') {
            return length;
        }
        length++;
    }
    return length;
}


void interpreter::build_expression(const string &program, unsigned index, WAE *&lhs, WAE *&rhs) {
    index++;
    if (index >= program.length() || program.at(index) != ' ') {
        throw invalid_program();
    }

    index++;
    if (index >= program.length()) {
        throw invalid_program();
    }
    if (program.at(index) == '(') {
        int exp_length = get_expression_length(program.substr(index));
        try {
            lhs = parse(program.substr(index, exp_length));
        } catch (invalid_program &e) {
            delete lhs;
            lhs = nullptr;
            delete rhs;
            rhs = nullptr;
            throw e;
        }
        index += exp_length;
    } else if (isalnum(program.at(index))) {
        int seq_length = get_sequence_length(program.substr(index));
        try {
            lhs = parse(program.substr(index, seq_length));
        } catch (invalid_program &e) {
            delete lhs;
            lhs = nullptr;
            delete rhs;
            rhs = nullptr;
            throw e;
        }
        index += seq_length;
    } else {
        throw invalid_program();
    }

    if (index >= program.length() || program.at(index) != ' ') {
        throw invalid_program();
    }

    index++;
    if (index >= program.length()) {
        throw invalid_program();
    }
    if (program.at(index) == '(') {
        int exp_length = get_expression_length(program.substr(index));
        try {
            rhs = parse(program.substr(index, exp_length));
        } catch (invalid_program &e) {
            delete lhs;
            lhs = nullptr;
            delete rhs;
            rhs = nullptr;
            throw e;
        }
        index += exp_length;
    } else if (isalnum(program.at(index))) {
        int seq_length = get_sequence_length(program.substr(index));
        try {
            rhs = parse(program.substr(index, seq_length));
        } catch (invalid_program &e) {
            delete lhs;
            lhs = nullptr;
            delete rhs;
            rhs = nullptr;
            throw e;
        }
        index += seq_length;
    } else {
        throw invalid_program();
    }

    if (index != program.length() - 1 || program.at(index) != ')') {
        throw invalid_program();
    }
}


