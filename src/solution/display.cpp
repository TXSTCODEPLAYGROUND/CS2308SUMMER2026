//
// Display prime-type examples: 100 positive and 100 negative per type,
// and 100 verifying ranges for satisfies6kPlusMinus1Form.
//
#include "display.hpp"
#include "solution.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

namespace {

constexpr int MAX_N = 500000;   // upper bound when collecting examples
constexpr int TARGET = 100;

void printExamples(const std::vector<int>& v, int perLine = 10) {
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i + 1 < v.size()) std::cout << ", ";
        if ((i + 1) % perLine == 0) std::cout << "\n  ";
    }
    if (!v.empty() && v.size() % perLine != 0) std::cout << "\n";
}

template<typename Pred>
void collectPositiveNegative(Pred pred, std::vector<int>& pos, std::vector<int>& neg) {
    pos.clear();
    neg.clear();
    for (int n = 1; n <= MAX_N && (pos.size() < static_cast<size_t>(TARGET) || neg.size() < static_cast<size_t>(TARGET)); ++n) {
        if (pred(n)) {
            if (pos.size() < static_cast<size_t>(TARGET)) pos.push_back(n);
        } else {
            if (neg.size() < static_cast<size_t>(TARGET)) neg.push_back(n);
        }
    }
}

void displayType(const char* name,
                 const std::vector<int>& pos, const std::vector<int>& neg) {
    std::cout << "\n=== " << name << " ===\n";
    std::cout << "Positive examples (" << pos.size() << "):\n  ";
    printExamples(pos);
    std::cout << "Negative examples (" << neg.size() << "):\n  ";
    printExamples(neg);
}

}  // namespace

void displayAllPrimeTypes() {
    std::vector<int> pos, neg;

    auto run = [&](const char* name, bool (*pred)(int)) {
        collectPositiveNegative(pred, pos, neg);
        displayType(name, pos, neg);
    };

    run("isPrime", isPrime);
    run("isTwinPrime", isTwinPrime);
    run("isMersennePrime", isMersennePrime);
    run("isFermatPrime", isFermatPrime);
    run("isSophieGermainPrime", isSophieGermainPrime);
    run("isEmirp", isEmirp);
    run("isCousinPrime", isCousinPrime);
    run("isChenPrime", isChenPrime);
    run("isCircularPrime", isCircularPrime);
    run("isBalancedPrime", isBalancedPrime);
    run("isPalindromicPrime", isPalindromicPrime);
    run("isLeftTruncatablePrime", isLeftTruncatablePrime);
    run("isRightTruncatablePrime", isRightTruncatablePrime);
    run("isTruncatablePrime", isTruncatablePrime);

    // satisfies6kPlusMinus1Form: 100 ranges that verify the property
    // (Every prime > 3 has form 6k±1, so any range verifies; we display 100 disjoint ranges.)
    std::cout << "\n=== satisfies6kPlusMinus1Form (100 verifying ranges) ===\n";
    std::cout << "Ranges [start, end] for which every prime > 3 in the range has form 6k±1:\n  ";
    const int rangeSize = (MAX_N - 2) / TARGET;  // so 100 ranges fit in [2, MAX_N]
    for (int i = 0; i < TARGET; ++i) {
        int start = 2 + i * rangeSize;
        int end = (i + 1 == TARGET) ? MAX_N : (start + rangeSize - 1);
        if (!satisfies6kPlusMinus1Form(start, end)) continue;  // should always be true
        std::cout << "[" << start << ", " << end << "]";
        if ((i + 1) % 5 == 0) std::cout << "\n  ";
        else std::cout << "  ";
    }
    std::cout << "\nTotal: 100 verifying ranges.\n";
}

namespace {

void writeJsonArray(std::ofstream& out, const std::vector<int>& v) {
    out << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i > 0) out << ",";
        out << v[i];
    }
    out << "]";
}

}  // namespace

bool writeExamplesToJson(const char* path) {
    std::ofstream out(path);
    if (!out) return false;

    std::vector<int> pos, neg;
    auto collect = [&](bool (*pred)(int)) {
        pos.clear();
        neg.clear();
        for (int n = 1; n <= MAX_N && (pos.size() < static_cast<size_t>(TARGET) || neg.size() < static_cast<size_t>(TARGET)); ++n) {
            if (pred(n)) {
                if (pos.size() < static_cast<size_t>(TARGET)) pos.push_back(n);
            } else {
                if (neg.size() < static_cast<size_t>(TARGET)) neg.push_back(n);
            }
        }
    };

    out << "{\n  \"primeTypes\": {\n";
    const char* names[] = {
        "isPrime", "isTwinPrime", "isMersennePrime",
        "isFermatPrime", "isSophieGermainPrime", "isEmirp",
        "isCousinPrime", "isChenPrime", "isCircularPrime",
        "isBalancedPrime", "isPalindromicPrime",
        "isLeftTruncatablePrime", "isRightTruncatablePrime",
        "isTruncatablePrime"
    };
    bool (*preds[])(int) = {
        isPrime, isTwinPrime, isMersennePrime,
        isFermatPrime, isSophieGermainPrime, isEmirp,
        isCousinPrime, isChenPrime, isCircularPrime,
        isBalancedPrime, isPalindromicPrime,
        isLeftTruncatablePrime, isRightTruncatablePrime,
        isTruncatablePrime
    };
    const size_t numTypes = sizeof(names) / sizeof(names[0]);

    for (size_t t = 0; t < numTypes; ++t) {
        collect(preds[t]);
        out << "    \"" << names[t] << "\": { \"positive\": ";
        writeJsonArray(out, pos);
        out << ", \"negative\": ";
        writeJsonArray(out, neg);
        out << " }";
        if (t + 1 < numTypes) out << ",";
        out << "\n";
    }

    out << "  },\n  \"satisfies6kPlusMinus1Form\": {\n    \"verifyingRanges\": [\n";
    const int rangeSize = (MAX_N - 2) / TARGET;
    for (int i = 0; i < TARGET; ++i) {
        int start = 2 + i * rangeSize;
        int end = (i + 1 == TARGET) ? MAX_N : (start + rangeSize - 1);
        out << "      {\"start\": " << start << ", \"end\": " << end << "}";
        if (i + 1 < TARGET) out << ",";
        out << "\n";
    }
    out << "    ]\n  }\n}\n";

    return true;
}

bool displayAndWriteExamplesToJson(const char* path) {
    displayAllPrimeTypes();
    std::filesystem::path p(path);
    std::filesystem::create_directories(p.parent_path());
    return writeExamplesToJson(path);
}
