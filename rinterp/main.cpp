#include "tester.h"

int main() {
    tester test = tester();
    test.test_parse();
    tester::test_subst();
    test.test_calc();
    return 0;
}
