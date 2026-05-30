//
// Test Solution: run a given Solution function against JSON samples in this folder.
//
#include "tests.hpp"
#include "../utils/utils.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <cstddef>
#include <map>

namespace {

std::string readFile(const char* path) {
    std::ifstream f(path);
    if (!f) return {};
    std::ostringstream os;
    os << f.rdbuf();
    return os.str();
}

// Parse integer starting at pos, return value and update pos to after the number
int parseInt(const std::string& json, std::size_t& pos) {
    int sign = 1;
    if (pos < json.size() && json[pos] == '-') {
        sign = -1;
        ++pos;
    }
    int n = 0;
    while (pos < json.size() && std::isdigit(static_cast<unsigned char>(json[pos]))) {
        n = n * 10 + (json[pos] - '0');
        ++pos;
    }
    return sign * n;
}

void parseIntArray(const std::string& json, std::size_t start, std::vector<int>& out) {
    out.clear();
    std::size_t i = start;
    while (i < json.size() && json[i] != ']') {
        if (std::isdigit(static_cast<unsigned char>(json[i])) || json[i] == '-') {
            out.push_back(parseInt(json, i));
        } else {
            ++i;
        }
    }
}

bool parsePositiveNegative(const std::string& json, const std::string& method,
                           std::vector<int>& positive, std::vector<int>& negative) {
    std::string key = "\"" + method + "\": { \"positive\": ";
    std::size_t pos = json.find(key);
    if (pos == std::string::npos) return false;
    std::size_t posArray = json.find('[', pos);
    if (posArray == std::string::npos) return false;
    parseIntArray(json, posArray + 1, positive);
    std::size_t negKey = json.find("\"negative\": [", posArray);
    if (negKey == std::string::npos) return false;
    parseIntArray(json, negKey + 13, negative);
    return true;
}

struct Range { int start; int end; };

bool parseVerifyingRanges(const std::string& json, std::vector<Range>& ranges) {
    ranges.clear();
    std::size_t pos = json.find("\"verifyingRanges\": [");
    if (pos == std::string::npos) return false;
    pos += 19;
    
    while (pos < json.size()) {
        std::size_t startKey = json.find("\"start\":", pos);
        if (startKey == std::string::npos) break;
        std::size_t numStart = json.find_first_of("0123456789-", startKey + 8);
        if (numStart == std::string::npos) break;
        
        int startVal = parseInt(json, numStart);
        
        std::size_t endKey = json.find("\"end\":", numStart);
        if (endKey == std::string::npos) break;
        std::size_t endNum = json.find_first_of("0123456789-", endKey + 6);
        if (endNum == std::string::npos) break;
        
        int endVal = parseInt(json, endNum);
        ranges.push_back({startVal, endVal});
        pos = endNum;
    }
    return !ranges.empty();
}

using UnaryPred = bool (*)(int);

UnaryPred getUnaryPredicate(const std::string& name) {
    static const std::map<std::string, UnaryPred> predicates = {
        {"isPrime", isPrime},
        {"isTwinPrime", isTwinPrime},
        {"isMersennePrime", isMersennePrime},
        {"isFermatPrime", isFermatPrime},
        {"isSophieGermainPrime", isSophieGermainPrime},
        {"isEmirp", isEmirp},
        {"isCousinPrime", isCousinPrime},
        {"isChenPrime", isChenPrime},
        {"isCircularPrime", isCircularPrime},
        {"isBalancedPrime", isBalancedPrime},
        {"isPalindromicPrime", isPalindromicPrime},
        {"isLeftTruncatablePrime", isLeftTruncatablePrime},
        {"isRightTruncatablePrime", isRightTruncatablePrime},
        {"isTruncatablePrime", isTruncatablePrime}
    };
    auto it = predicates.find(name);
    return (it != predicates.end()) ? it->second : nullptr;
}

}  // namespace

bool testSolution(const std::string& functionName, const char* jsonPath) {
    std::string json = readFile(jsonPath);
    if (json.empty()) {
        std::cerr << "testSolution: could not read " << jsonPath << "\n";
        return false;
    }

    if (functionName == "satisfies6kPlusMinus1Form") {
        std::vector<Range> ranges;
        if (!parseVerifyingRanges(json, ranges)) {
            std::cerr << "testSolution: could not parse verifyingRanges from " << jsonPath << "\n";
            return false;
        }
        int failed = 0;
        for (const auto& r : ranges) {
            if (!satisfies6kPlusMinus1Form(r.start, r.end)) {
                std::cerr << "  FAIL: " << functionName << "(" << r.start << ", " << r.end << ") expected true\n";
                ++failed;
            }
        }
        std::cout << "  " << functionName << ": " << ranges.size() << " ranges; " << failed << " failed\n";
        return failed == 0;
    }

    UnaryPred pred = getUnaryPredicate(functionName);
    if (!pred) {
        std::cerr << "testSolution: unknown function " << functionName << "\n";
        return false;
    }

    std::vector<int> positive, negative;
    if (!parsePositiveNegative(json, functionName, positive, negative)) {
        std::cerr << "testSolution: could not parse positive/negative for " << functionName << " from " << jsonPath << "\n";
        return false;
    }

    int failed = 0;
    for (int n : positive) {
        if (!pred(n)) {
            std::cerr << "  FAIL positive: " << functionName << "(" << n << ") expected true\n";
            ++failed;
        }
    }
    for (int n : negative) {
        if (pred(n)) {
            std::cerr << "  FAIL negative: " << functionName << "(" << n << ") expected false\n";
            ++failed;
        }
    }
    std::cout << "  " << functionName << ": " << positive.size() << " positive, " << negative.size() << " negative; " << failed << " failed\n";
    return failed == 0;
}
