//
// Display prime-type examples: 100 positive and 100 negative per type,
// and 100 verifying ranges for satisfies6kPlusMinus1Form.
//
#pragma once

/// Displays for each prime type: up to 100 positive examples (numbers that
/// satisfy the type), up to 100 negative examples (numbers that do not), and
/// for satisfies6kPlusMinus1FormSolution, 100 ranges that verify the property.
void displayAllPrimeTypes();

/// Writes the same examples to a JSON file at \p path (e.g. "prime_examples.json").
/// Returns true on success, false if the file could not be opened.
bool writeExamplesToJson(const char* path);

/// Displays all prime-type examples (like displayAllPrimeTypes) and writes them to a JSON file.
/// Saves to \p path; default is "tests/tests.json". Creates the "tests" directory if needed.
/// Returns true on success, false if the file could not be opened.
bool displayAndWriteExamplesToJson(const char* path = "src/tests/tests.json");
