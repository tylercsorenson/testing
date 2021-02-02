#include "tester.h"
#include <iostream>
#include <utility>

void tester::test_parse() {
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
    cout << "parse(\"(+ (- 3 1) (* (/ 4 2) 8))\"): " << compare(i.parse("(+ (- 3 1) (* (/ 4 2) 8))"), new WAE_addition(
            new WAE_subtraction(new WAE_number(3), new WAE_number(1)),
            new WAE_multiplication(new WAE_division(new WAE_number(4), new WAE_number(2)), new WAE_number(8)))) << endl;
    cout << "parse(\"(with ([a 15]) a)\"): "
         << compare(i.parse("(with ([a 15]) a)"), new WAE_with(new WAE_x("a"), new WAE_number(15), new WAE_x("a")))
         << endl;
    cout << "parse(\"(with ([abc (+ 15 14)]) (* 15 abc))\"): "
         << compare(i.parse("(with ([abc (+ 15 14)]) (* 15 abc))"),
                    new WAE_with(new WAE_x("abc"), new WAE_addition(new WAE_number(15), new WAE_number(14)),
                                 new WAE_multiplication(new WAE_number(15), new WAE_x("abc")))) << endl;
    cout << "parse(\"(with ([abc 13]) b)\"): "
         << compare(i.parse("(with ([abc 13]) b)"), new WAE_with(new WAE_x("abc"), new WAE_number(13), new WAE_x("b")))
         << endl;
    cout << "parse(\"(with ([a 5]) (with ([b 3]) (/ a b)))\"): "
         << compare(i.parse("(with ([a 5]) (with ([b 3]) (/ a b)))"), new WAE_with(new WAE_x("a"), new WAE_number(5),
                                                                                   new WAE_with(new WAE_x("b"),
                                                                                                new WAE_number(3),
                                                                                                new WAE_division(
                                                                                                        new WAE_x("a"),
                                                                                                        new WAE_x(
                                                                                                                "b")))))
         << endl;
    cout << "parse(\"(with ([a (with ([c 3]) c)]) a)\"): " << compare(i.parse("(with ([a (with ([c 3]) c)]) a)"),
                                                                      new WAE_with(new WAE_x("a"),
                                                                                   new WAE_with(new WAE_x("c"),
                                                                                                new WAE_number(3),
                                                                                                new WAE_x("c")),
                                                                                   new WAE_x("a"))) << endl;
    cout << "parse(\"(with ([x (with ([x 13]) (+ x 7))]) x)\"): "
         << compare(i.parse("(with ([x (with ([x 13]) (+ x 7))]) x)"), new WAE_with(new WAE_x("x"),
                                                                                    new WAE_with(new WAE_x("x"),
                                                                                                 new WAE_number(13),
                                                                                                 new WAE_addition(
                                                                                                         new WAE_x("x"),
                                                                                                         new WAE_number(
                                                                                                                 7))),
                                                                                    new WAE_x("x"))) << endl;

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
    cout << "parse(\"(with [x 1] x)\"): " << confirm_invalid_program("(with [x 1] x)") << endl;
    cout << "parse(\"( with ([a 13]) a)\"): " << confirm_invalid_program("( with ([a 13]) a)") << endl;
    cout << "parse(\"(with  ([a 13]) a)\"): " << confirm_invalid_program("(with  ([a 13]) a)") << endl;
    cout << "parse(\"(with ( [a 13]) a)\"): " << confirm_invalid_program("(with ( [a 13]) a)") << endl;
    cout << "parse(\"(with ([ a 13]) a)\"): " << confirm_invalid_program("(with ([ a 13]) a)") << endl;
    cout << "parse(\"(with ([a  13]) a)\"): " << confirm_invalid_program("(with ([a  13]) a)") << endl;
    cout << "parse(\"(with ([a 13 ]) a)\"): " << confirm_invalid_program("(with ([a 13 ]) a)") << endl;
    cout << "parse(\"(with ([a 13] ) a)\"): " << confirm_invalid_program("(with ([a 13] ) a)") << endl;
    cout << "parse(\"(with ([a 13])  a)\"): " << confirm_invalid_program("(with ([a 13])  a)") << endl;
    cout << "parse(\"(with ([a 13]) a )\"): " << confirm_invalid_program("(with ([a 13]) a )") << endl;
    cout << "parse(\"(with (x 1]) x)\"): " << confirm_invalid_program("(with (x 1]) x)") << endl;
    cout << "parse(\"(with ([x 1) x)\"): " << confirm_invalid_program("(with ([x 1) x)") << endl;
    cout << "parse(\"(with ([x 1]) x))\"): " << confirm_invalid_program("(with ([x 1]) x))") << endl;
    cout << "parse(\"(with ([x 1)] x)\"): " << confirm_invalid_program("(with ([x 1)] x)") << endl;
    cout << "parse(\"(with ([x 1]) (+ x 2)))\"): " << confirm_invalid_program("(with ([x 1]) (+ x 2)))") << endl;
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

void tester::test_calc() {
    cout << endl << endl << "testing calc" << endl << endl;
    cout << "valid calculations" << endl;
    cout << "calc(parse(\"13\")): " << compare_calc(i.calc(i.parse("13")), 13) << endl;
    cout << "calc(parse(\"1\")): " << compare_calc(i.calc(i.parse("1")), 1) << endl;
    cout << "calc(parse(\"(+ 8 13)\")): " << compare_calc(i.calc(i.parse("(+ 8 13)")), 21) << endl;
    cout << "calc(parse(\"(+ (+ 1 3) 13)\")): " << compare_calc(i.calc(i.parse("(+ (+ 1 3) 13)")), 17) << endl;
    cout << "calc(parse(\"(+ 7 (+ 2 8))\")): " << compare_calc(i.calc(i.parse("(+ 7 (+ 2 8))")), 17) << endl;
    cout << "calc(parse(\"(+ (+ 1 3) (+ 2 8))\")): " << compare_calc(i.calc(i.parse("(+ (+ 1 3) (+ 2 8))")), 14)
         << endl;
    cout << "calc(parse(\"(+ (- 3 1) (* (/ 4 2) 8))\")): "
         << compare_calc(i.calc(i.parse("(+ (- 3 1) (* (/ 4 2) 8))")), 18) << endl;
    cout << "calc(parse(\"(with ([a 15]) a)\")): " << compare_calc(i.calc(i.parse("(with ([a 15]) a)")), 15) << endl;
    cout << "calc(parse(\"(with ([x 5]) (with ([x 10]) x))\")): "
         << compare_calc(i.calc(i.parse("(with ([x 5]) (with ([x 10]) x))")), 10) << endl;
    cout << "calc(parse(\"(with ([abc (+ 15 14)]) (* 15 abc))\")): "
         << compare_calc(i.calc(i.parse("(with ([abc (+ 15 14)]) (* 15 abc))")), 435) << endl;
    cout << "calc(parse(\"(with ([a 5]) (with ([b 3]) (/ a b)))\")): "
         << compare_calc(i.calc(i.parse("(with ([a 5]) (with ([b 3]) (/ a b)))")), 1) << endl;
    cout << "calc(parse(\"(with ([a (with ([c 3]) c)]) a)\")): "
         << compare_calc(i.calc(i.parse("(with ([a (with ([c 3]) c)]) a)")), 3) << endl;
    cout << "calc(parse(\"(with ([x (with ([x 13]) (+ x 7))]) x)\")): "
         << compare_calc(i.calc(i.parse("(with ([x (with ([x 13]) (+ x 7))]) x)")), 20) << endl;

    cout << endl << "invalid calculations" << endl;
    cout << "calc(parse(\"x\")): " << confirm_invalid_calculation(i.parse("x")) << endl;
    /*cout << "calc(parse(\"hello\")): " << confirm_invalid_calculation(i.parse("hello")) << endl;
    cout << "calc(parse(\"vAr\")): " << confirm_invalid_calculation(i.parse("vAr")) << endl;
    cout << "calc(parse(\"wITH\")): " << confirm_invalid_calculation(i.parse("wITH")) << endl;
    cout << "calc(parse(\"(+ 7 a)\")): " << confirm_invalid_calculation(i.parse("(+ 7 a)")) << endl;
    cout << "calc(parse(\"(with ([abc 13]) b)\")): " << confirm_invalid_calculation(i.parse("(with ([abc 13]) b)"))
         << endl;*/
}

string tester::compare_calc(unsigned actual, unsigned expected) {
    if (actual == expected) {
        return "passed";
    }
    return "FAILED!!";
}

string tester::confirm_invalid_calculation(WAE *input) {
    try {
        i.calc(input);
    } catch (invalid_calculation &e) {
        return "passed";
    }
    return "FAILED!!";
}