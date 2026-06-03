//
// Prime number utilities: implementations.
//
#include "utils.hpp"

// -----------------------------------------------------------------------------
// Primality
// -----------------------------------------------------------------------------

bool isPrime(int n) {
    if (n < 2 || n % 2 == 0) return n == 2;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// -----------------------------------------------------------------------------
// Prime type checks (stubs with implementation guides)
// -----------------------------------------------------------------------------

bool isTwinPrime(int n) {
    // Twin primes: pairs of primes that differ by 2 (e.g., 11, 13).
    // Check if n is prime and either (n-2) or (n+2) is also prime.
    return false;
}

bool isMersennePrime(int n) {
    // Mersenne primes: form 2^p - 1 where p is prime (e.g., 2^5 - 1 = 31).
    // Find p such that n == (2^p - 1), then verify p is prime.
    return false;
}

bool isFermatPrime(int n) {
    // Fermat primes: form 2^(2^k) + 1 (e.g., 2^4 + 1 = 17). Only 5 known: 3, 5, 17, 257, 65537.
    // Verify if n is of the form 2^(2^k) + 1 and is prime. Hint: Use the isPrime function and logarithmic operations.
    return false;
}

bool isSophieGermainPrime(int n) {
    // Sophie Germain: prime p where 2p + 1 is also prime (e.g., 11 -> 23).
    // Verify n is prime, then check that (2*n + 1) is prime.
    return false;
}

bool isEmirp(int n) {
    // Emirps: primes that yield a different prime when digits are reversed (e.g., 13 -> 31).
    // Reverse digits of n; if reverse != n and both are prime, return true. Hint: Do not confuse with palindromic primes.
    return false;
}

bool isCousinPrime(int n) {
    // Cousin primes: pairs of primes that differ by 4 (e.g., 7, 11).
    // Check if n is prime and either (n-4) or (n+4) is also prime.
    return false;
}

bool isChenPrime(int n) {
    // Chen primes: prime p where (p + 2) is either prime or semiprime (product of two primes).
    // Verify n is prime; check if (n+2) is prime, or has exactly two prime factors.
    return false;
}

bool isCircularPrime(int n) {
    // Circular primes: remain prime under all rotations (e.g., 197, 971, 719).
    // Rotate digits (e.g., 197 -> 971 -> 719); if all rotations are prime, return true.
    return false;
}

bool isBalancedPrime(int n) {
    // Balanced primes: average of nearest primes above and below (e.g., 53 = (47 + 59)/2).
    // Find next prime above n and previous prime below n; check if n == (prev + next) / 2.
    return false;
}

bool isPalindromicPrime(int n) {
    // Palindromic primes: read same backward and forward (e.g., 131).
    // Check primality and that n equals its digit-reversed form.
    return false;
}

bool isLeftTruncatablePrime(int n) {
    // Left-truncatable: remains prime when digits removed from left (e.g., 9137 -> 137 -> 37 -> 7).
    // Repeatedly remove leftmost digit; verify each resulting number is prime.
    return false;
}

bool isRightTruncatablePrime(int n) {
    // Right-truncatable: remains prime when digits removed from right (e.g., 7393 -> 739 -> 73 -> 7).
    // Repeatedly remove rightmost digit; verify each resulting number is prime.
    return false;
}

bool isTruncatablePrime(int n) {
    // Truncatable (both): prime under both left AND right truncation (e.g., 3797).
    // Must satisfy both isLeftTruncatablePrime(n) and isRightTruncatablePrime(n).
    return false;
}

bool satisfies6kPlusMinus1Form(int start, int end) {
    // All primes > 3 can be expressed as 6k+1 or 6k-1 for some integer k.
    // Equivalently: n % 6 == 1 or n % 6 == 5. (Note: 6k-1 ≡ 5 mod 6)
    // For some prime numbers with some range: return true if all `n` has this form (used to verify the property).
    return false;
}
