//
// PrimeNumbers: main program.
//
#include "src/utils/utils.hpp"
#include "src/tests/tests.hpp"
#include <filesystem>
#include <iostream>

namespace {

std::string resolveTestsJsonPath() {
    std::filesystem::path current = std::filesystem::current_path();
    while (true) {
        std::filesystem::path candidate = current / "src" / "tests" / "tests.json";
        if (std::filesystem::exists(candidate)) {
            return std::filesystem::absolute(candidate).string();
        }

        if (current.parent_path() == current) {
            break;
        }
        current = current.parent_path();
    }

    return "src/tests/tests.json";
}

}  // namespace

int main() {
    const std::string testsPath = resolveTestsJsonPath();

    // Run solution tests from src/tests/tests.json.
    std::cout << "\n--- Solution tests ---\n";
    testSolution("isPrime", testsPath.c_str());
    testSolution("isTwinPrime", testsPath.c_str());
    testSolution("isMersennePrime", testsPath.c_str());
    testSolution("isFermatPrime", testsPath.c_str());
    testSolution("isSophieGermainPrime", testsPath.c_str());
    testSolution("isEmirp", testsPath.c_str());
    testSolution("isCousinPrime", testsPath.c_str());
    testSolution("isChenPrime", testsPath.c_str());
    testSolution("isCircularPrime", testsPath.c_str());
    testSolution("isBalancedPrime", testsPath.c_str());
    testSolution("isPalindromicPrime", testsPath.c_str());
    testSolution("isLeftTruncatablePrime", testsPath.c_str());
    testSolution("isRightTruncatablePrime", testsPath.c_str());
    testSolution("isTruncatablePrime", testsPath.c_str());
    testSolution("satisfies6kPlusMinus1Form", testsPath.c_str());

    return 0;
}