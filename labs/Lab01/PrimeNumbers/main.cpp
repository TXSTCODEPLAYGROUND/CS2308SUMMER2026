//
// PrimeNumbers: main program.
//
#include "src/utils/utils.hpp"
#include "src/tests/tests.hpp"
#include <iostream>

int main() {
    // Run solution tests from src/tests/tests.json
    std::cout << "\n--- Solution tests ---\n";
    testSolution("isPrime");
    /*
    testSolution("isTwinPrime");
    testSolution("isMersennePrime");
    testSolution("isFermatPrime");
    testSolution("isSophieGermainPrime");
    testSolution("isEmirp");
    testSolution("isCousinPrime");
    testSolution("isChenPrime");
    testSolution("isCircularPrime");
    testSolution("isBalancedPrime");
    testSolution("isPalindromicPrime");
    testSolution("isLeftTruncatablePrime");
    testSolution("isRightTruncatablePrime");
    testSolution("isTruncatablePrime");
    testSolution("satisfies6kPlusMinus1Form");
    */
    return 0;
}
