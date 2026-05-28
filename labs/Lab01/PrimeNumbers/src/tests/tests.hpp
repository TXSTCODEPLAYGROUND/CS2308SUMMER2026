//
// Test Solution: run a given Solution function against JSON samples in this folder.
//
#pragma once

#include <string>

/// Runs tests for the given function name using JSON data from this folder.
/// \p functionName: e.g. "isPrimeSolution", "isTwinPrimeSolution", ...,
///   or "satisfies6kPlusMinus1Form" (uses verifyingRanges: start/end).
/// \p jsonPath: path to tests.json; default "src/tests/tests.json".
/// Returns true if all tests passed, false otherwise. Prints results to stdout.
bool testSolution(const std::string& functionName, const char* jsonPath = "../src/tests/tests.json");
