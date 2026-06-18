//
// Prime number utilities: implementations.
//
#include "utils.hpp"

#include <iostream>
#include <ostream>
#include <cmath>

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
    if (isPrime(n))
        return (isPrime(n-2) || isPrime(n+2));
    return false;
}

bool isMersennePrime(int n) {
    // Mersenne primes: form 2^p - 1 where p is prime (e.g., 2^5 - 1 = 31).
    // Find p such that n == (2^p - 1), then verify p is prime.
    if (isPrime(n)) {
        double x = std::log(n+1) / std::log(2);
        int p = x;
        if (x - p < 0.001) return isPrime(p);
    }
    return false;
}

bool isFermatPrime(int n) {
    // Fermat primes: form 2^(2^k) + 1 (e.g., 2^4 + 1 = 17). Only 5 known: 3, 5, 17, 257, 65537.
    // Verify if n is of the form 2^(2^k) + 1 and is prime. Hint: Use the isPrime function and logarithmic operations.
    if (isPrime(n) && n > 2) {
        double x = std::log(std::log(n-1) / std::log(2)) / std::log(2);
        int k = x;
        return (x - k < 0.001);
    }
    return false;
}

bool isSophieGermainPrime(int n) {
    // Sophie Germain: prime p where 2p + 1 is also prime (e.g., 11 -> 23).
    // Verify n is prime, then check that (2*n + 1) is prime.
    if (isPrime(n)) {
        return (isPrime(2 * n + 1));
    }
    return false;
}

bool isEmirp(int n) {
    // Emirps: primes that yield a different prime when digits are reversed (e.g., 13 -> 31).
    // Reverse digits of n; if reverse != n and both are prime, return true. Hint: Do not confuse with palindromic primes.
    if (isPrime(n)) {
        int num = n, rev_num = 0;
        while (num > 0) {
            rev_num = rev_num * 10 + num % 10;
            num /= 10;
        }
        if (n != rev_num) return (isPrime(rev_num));
    }
    return false;
}

bool isCousinPrime(int n) {
    // Cousin primes: pairs of primes that differ by 4 (e.g., 7, 11).
    // Check if n is prime and either (n-4) or (n+4) is also prime.
    if (isPrime(n))
        return (isPrime(n-4) || isPrime(n+4));
    return false;
}

bool isChenPrime(int n) {
    // Chen primes: prime p where (p + 2) is either prime or semiprime (product of two primes).
    // Verify n is prime; check if (n+2) is prime, or has exactly two prime factors.
    if (isPrime(n)) {
        int p = n + 2, i = 2;
        while (p % i != 0) i++;
        return (isPrime(p) || isPrime(p/i));
    }
    return false;
}

bool isCircularPrime(int n) {
    // Circular primes: remain prime under all rotations (e.g., 197, 971, 719).
    // Rotate digits (e.g., 197 -> 971 -> 719); if all rotations are prime, return true.
    int digitCount = std::log(n) / std::log(10) + 1;
    for (int i = 0; i < digitCount; i++) {
        if (!isPrime(n)) return false;
        int tempDigit = n % 10;
        n = n / 10 + tempDigit * pow(10, digitCount - 1);
    }
    return true;
}

bool isBalancedPrime(int n) {
    // Balanced primes: average of nearest primes above and below (e.g., 53 = (47 + 59)/2).
    // Find next prime above n and previous prime below n; check if n == (prev + next) / 2.
    if (isPrime(n)) {
        int upper = n + 2, lower = n - 2;
        while (!isPrime(upper) && !isPrime(lower) && lower > 0) {
            upper += 2;
            lower -= 2;
        }
        return isPrime(upper) && isPrime(lower);
    }
    return false;
}

bool isPalindromicPrime(int n) {
    // Palindromic primes: read same backward and forward (e.g., 131).
    // Check primality and that n equals its digit-reversed form.
    if (isPrime(n)) {
        int num = n, rev_num = 0;
        while (num > 0) {
            rev_num = rev_num * 10 + num % 10;
            num /= 10;
        }
        return n == rev_num;
    }
    return false;
}

bool isLeftTruncatablePrime(int n) {
    // Left-truncatable: remains prime when digits removed from left (e.g., 9137 -> 137 -> 37 -> 7).
    // Repeatedly remove leftmost digit; verify each resulting number is prime.
    int digitCount = std::log(n) / std::log(10);
    while (isPrime(n) && digitCount > 0) {
        n = n % static_cast<int>(pow(10, digitCount));
        digitCount--;
    }
    return isPrime(n);
}

bool isRightTruncatablePrime(int n) {
    // Right-truncatable: remains prime when digits removed from right (e.g., 7393 -> 739 -> 73 -> 7).
    // Repeatedly remove rightmost digit; verify each resulting number is prime.
    while (isPrime(n)) n /= 10;
    return (n == 0);
}

bool isTruncatablePrime(int n) {
    // Truncatable (both): prime under both left AND right truncation (e.g., 3797).
    // Must satisfy both isLeftTruncatablePrime(n) and isRightTruncatablePrime(n).
    return isLeftTruncatablePrime(n) && isRightTruncatablePrime(n);
}

bool satisfies6kPlusMinus1Form(int start, int end) {
    // All primes > 3 can be expressed as 6k+1 or 6k-1 for some integer k.
    // Equivalently: n % 6 == 1 or n % 6 == 5. (Note: 6k-1 ≡ 5 mod 6)
    // For some prime numbers with some range: return true if all `n` has this form (used to verify the property).
    if (start < 5) start = 5;
    int n = start;
    while (n <= end) {
        if (isPrime(n))
            if (n % 6 != 1 && n % 6 != 5) return false;
        n++;
    }

    return true;
}
