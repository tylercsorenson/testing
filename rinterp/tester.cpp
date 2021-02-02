#include "tester.h"
#include <iostream>
#include <utility>

void tester::test_parse() {
    cout << boolalpha;
    cout << "testing parse" << endl << endl;
    cout << "valid programs" << endl;
    cout << "parse(\"13\"): " << compare(i.parse("13"), new WAE_number(13)) << endl;
    cout << "parse(\"1\"): " << compare(i.parse("1"), new WAE_number(1)) << endl;
    cout << "parse(\"x\"): " << compare(i.parse("x"), new WAE_x("x")) << endl;
    cout << "parse(\"hello\"): " << compare(i.parse("hello"), new WAE_x("hello")) << endl;
    cout << "parse(\"vAr\"): " << compare(i.parse("vAr"), new WAE_x("vAr")) << endl;
    cout << "parse(\"wITH\"): " << compare(i.parse("wITH"), new WAE_x("wITH")) << endl;
    cout << "parse(\"(+ 8 13)\"): " << compare(i.parse("(+ 8 13)"), new WAE_addition(new WAE_number(8),
                                                                                     new WAE_number(13))) << endl;
    cout << "parse(\"(+ (+ 1 3) 13)\"): "
         << compare(i.parse("(+ (+ 1 3) 13)"),
                    new WAE_addition(new WAE_addition(new WAE_number(1), new WAE_number(3)), new WAE_number(13)))
         << endl;
    cout << "parse(\"(+ 7 (+ 2 8))\"): "
         << compare(i.parse("(+ 7 (+ 2 8))"),
                    new WAE_addition(new WAE_number(7), new WAE_addition(new WAE_number(2), new WAE_number(8))))
         << endl;
    cout << "parse(\"(+ (+ 1 3) (+ 2 8))\"): "
         << compare(i.parse("(+ (+ 1 3) (+ 2 8))"),
                    new WAE_addition(new WAE_addition(new WAE_number(1), new WAE_number(3)),
                                     new WAE_addition(new WAE_number(2), new WAE_number(8)))) << endl;

    cout << "parse(\"(+ 7 a)\"): " << compare(i.parse("(+ 7 a)"), new WAE_addition(new WAE_number(7), new WAE_x("a")))
         << endl;
    cout << "parse(\"(+ (- 1 3) (* (/ 2 4) 8))\"): " << compare(i.parse("(+ (- 1 3) (* (/ 2 4) 8))"), new WAE_addition(
            new WAE_subtraction(new WAE_number(1), new WAE_number(3)),
            new WAE_multiplication(new WAE_division(new WAE_number(2), new WAE_number(4)), new WAE_number(8)))) << endl;
    cout << "parse(\"(with ([a 15]) a)\"): "
         << compare(i.parse("(with ([a 15]) a)"), new WAE_with(new WAE_x("a"), new WAE_number(15), new WAE_x("a")))
         << endl;
    cout << "parse(\"(with ([abc (+ 15 14)]) (* 15 abc))\"): "
         << compare(i.parse("(with ([abc (+ 15 14)]) (* 15 abc))"),
                    new WAE_with(new WAE_x("abc"), new WAE_addition(new WAE_number(15), new WAE_number(14)),
                                 new WAE_multiplication(new WAE_number(15), new WAE_x("abc")))) << endl;

    cout << endl << "invalid programs" << endl;
    cout << "parse(\" 2\"): " << confirm_invalid_program(" 2") << endl;
    cout << "parse(\"3 \"): " << confirm_invalid_program("3 ") << endl;
    cout << "parse(\"3 2\"): " << confirm_invalid_program("3 2") << endl;
    cout << "parse(\"17.2\"): " << confirm_invalid_program("17.2") << endl;
    cout << "parse(\"0.9\"): " << confirm_invalid_program("0.9") << endl;
    cout << "parse(\".9\"): " << confirm_invalid_program(".9") << endl;
    cout << "parse(\"0\"): " << confirm_invalid_program("0") << endl;
    cout << "parse(\"-3\"): " << confirm_invalid_program("-3") << endl;
    cout << "parse(\"-5.2\"): " << confirm_invalid_program("-5.2") << endl;
    cout << "parse(\"-.7\"): " << confirm_invalid_program("-.7") << endl;
    cout << "parse(\"with\"): " << confirm_invalid_program("with") << endl;
    cout << "parse(\" cs\"): " << confirm_invalid_program(" cs") << endl;
    cout << "parse(\"cs \"): " << confirm_invalid_program("cs ") << endl;
    cout << "parse(\"hello world\"): " << confirm_invalid_program("hello world") << endl;
    cout << "parse(\"id*\"): " << confirm_invalid_program("id*") << endl;
    cout << "parse(\"/test\"): " << confirm_invalid_program("/test") << endl;
    cout << "parse(\"my_var\"): " << confirm_invalid_program("my_var") << endl;
    cout << "parse(\"pie314\"): " << confirm_invalid_program("pie314") << endl;
    cout << "parse(\"(+8 13)\"): " << confirm_invalid_program("(+8 13)") << endl;
    cout << "parse(\"( + 8 13\"): " << confirm_invalid_program("( + 8 13") << endl;
    cout << "parse(\"(+  8 13)\"): " << confirm_invalid_program("(+  8 13)") << endl;
    cout << "parse(\"(+ 8 13 )\"): " << confirm_invalid_program("(+ 8 13 )") << endl;
    cout << "parse(\"(+ 8 13))\"): " << confirm_invalid_program("(+ 8 13))") << endl;
    cout << "parse(\"(+ 8)\"): " << confirm_invalid_program("(+ 8)") << endl;
    cout << "parse(\"(+ (+ 1 3))\"): " << confirm_invalid_program("(+ (+ 1 3))") << endl;
    cout << "parse(\"(+ (+ 1 3) )\"): " << confirm_invalid_program("(+ (+ 1 3) )") << endl;
    cout << "parse(\"(+ 8 (+ 1 3)\"): " << confirm_invalid_program("(+ 8 (+ 1 3)") << endl;
    cout << "parse(\"(+ 7 (abc))\"): " << confirm_invalid_program("(+ 7 (abc))") << endl;
    cout << "parse(\"(+ 8 (+ 9 .))\"): " << confirm_invalid_program("(+ 8 (+ 9 .))") << endl;
    cout << "parse(\"(+ * 8)\"): " << confirm_invalid_program("(+ * 8)") << endl;
    cout << "parse(\"(++ 8 7)\"): " << confirm_invalid_program("(++ 8 7)") << endl;
    cout << "parse(\"(7 - 2)\"): " << confirm_invalid_program("(7 - 2)") << endl;

}

string tester::compare(const WAE *actual, const WAE *expected) {
    string result = "FAILED!!";
    if (*actual == *expected) {
        result = "passed";
    }
    delete actual;
    delete expected;
    return result;
}

string tester::confirm_invalid_program(const string &program) {
    try {
        i.parse(program);
    } catch (invalid_program &e) {
        return "passed";
    }
    return "FAILED!!";
}
