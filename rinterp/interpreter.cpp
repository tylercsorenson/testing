#include "invalid_program.h"
#include <istream>

#include "interpreter.h"
#include <stack>

WAE *interpreter::parse(string program) {
    unsigned index = 0;
    if (isdigit(program.at(index))) {
        for (char c : program) {
            if (!isdigit(c)) {
                throw invalid_program();
            }
        }
        int value = stoi(program);
        if (value == 0) {
            throw invalid_program();
        }
        return new WAE_number(value);
    } else if (isalpha(program.at(index))) {
        return build_x(program);
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
            index += 4;
            if (index >= program.length() || program.at(index) != ' ') {
                throw invalid_program();
            }

            index++;
            if (index >= program.length() || program.at(index) != '(') {
                throw invalid_program();
            }

            index++;
            if (index >= program.length() || program.at(index) != '[') {
                throw invalid_program();
            }
            int with_brackets_length = get_with_brackets_length(program.substr(index));

            WAE *x = nullptr;
            WAE *inside = nullptr;

            build_inbetween_brackets(program.substr(index + 1, with_brackets_length - 2), x, inside);

            index += with_brackets_length;
            if (index >= program.length() || program.at(index) != ')') {
                delete x;
                x = nullptr;
                delete inside;
                inside = nullptr;
                throw invalid_program();
            }

            index++;
            if (index >= program.length() || program.at(index) != ' ') {
                delete x;
                x = nullptr;
                delete inside;
                inside = nullptr;
                throw invalid_program();
            }

            index++;
            if (index >= program.length()) {
                delete x;
                x = nullptr;
                delete inside;
                inside = nullptr;
                throw invalid_program();
            }
            WAE *outside = nullptr;
            try {
                unsigned remaining_chars = program.length() - index;
                outside = parse(program.substr(index, remaining_chars - 1));
            } catch (invalid_program &e) {
                delete x;
                x = nullptr;
                delete inside;
                inside = nullptr;
                throw e;
            }

            if (program.at(program.length() - 1) != ')') {
                delete x;
                x = nullptr;
                delete inside;
                inside = nullptr;
                delete outside;
                outside = nullptr;
                throw invalid_program();
            }

            return new WAE_with(x, inside, outside);
        }
    }
    throw invalid_program();
}

unsigned interpreter::calc(WAE *input) {
    unsigned result = input->solve();
    delete input;
//    input = nullptr;
    return result;
}

bool interpreter::check_parens(const string &program) {
    stack<char> paren_stack;
    for (char c : program) {
        if (c == '(' || c == '[') {
            paren_stack.emplace(c);
        } else if (c == ')') {
            if (paren_stack.empty() or paren_stack.top() == '[') {
                return false;
            }
            paren_stack.pop();
        } else if (c == ']') {
            if (paren_stack.empty() or paren_stack.top() == '(') {
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

WAE *interpreter::build_x(const string &program) {
    if (program == "with") {
        throw invalid_program();
    }
    for (char c : program) {
        if (!isalpha(c)) {
            throw invalid_program();
        }
    }
    return new WAE_x(program);
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
        delete lhs;
        lhs = nullptr;
        delete rhs;
        rhs = nullptr;
        throw invalid_program();
    }

    if (index >= program.length() || program.at(index) != ' ') {
        delete lhs;
        lhs = nullptr;
        delete rhs;
        rhs = nullptr;
        throw invalid_program();
    }

    index++;
    if (index >= program.length()) {
        delete lhs;
        lhs = nullptr;
        delete rhs;
        rhs = nullptr;
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
        delete lhs;
        lhs = nullptr;
        delete rhs;
        rhs = nullptr;
        throw invalid_program();
    }

    if (index != program.length() - 1 || program.at(index) != ')') {
        delete lhs;
        lhs = nullptr;
        delete rhs;
        rhs = nullptr;
        throw invalid_program();
    }
}

int interpreter::get_with_brackets_length(const string &input) {
    stack<char> bracket_stack;
    int length = 0;
    for (char c : input) {
        length++;
        if (c == '[') {
            bracket_stack.emplace(c);
        } else if (c == ']') {
            if (bracket_stack.empty()) {
                return false;
            }
            bracket_stack.pop();
            if (bracket_stack.empty()) {
                return length;
            }
        }
    }
    return length;
}

void interpreter::build_inbetween_brackets(const string &excerpt, WAE *&x, WAE *&inside) {
    unsigned index = 0;
    if (index >= excerpt.length()) {
        throw invalid_program();
    }
    int seq_length = get_sequence_length(excerpt);
    x = build_x(excerpt.substr(index, seq_length));

    index += seq_length;
    if (index >= excerpt.length() || excerpt.at(index) != ' ') {
        delete x;
        x = nullptr;
        throw invalid_program();
    }

    index++;
    if (index >= excerpt.length()) {
        delete x;
        x = nullptr;
        throw invalid_program();
    }
    try {
        inside = parse(excerpt.substr(index));
    } catch (invalid_program &e) {
        delete x;
        x = nullptr;
        throw e;
    }
}
