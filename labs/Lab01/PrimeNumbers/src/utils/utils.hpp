//
// Prime number utilities: primality and prime-type checks.
//
#pragma once

/*Traditionally
#ifndef UTILS_HPP
#define UTILS_HPP
// ... contents ...
#endif
*/

/// Returns true if n is prime (n > 1, no divisors other than 1 and itself).
bool isPrime(int n);

/// Twin prime: n prime and (n-2) or (n+2) prime.
bool isTwinPrime(int n);
/// Mersenne prime: n = 2^p - 1 with p prime.
bool isMersennePrime(int n);
/// Fermat prime: n = 2^(2^k) + 1 (only 5 known: 3, 5, 17, 257, 65537).
bool isFermatPrime(int n);
/// Sophie Germain: n prime and 2n+1 prime.
bool isSophieGermainPrime(int n);
/// Emirp: n prime, reverse(n) != n and reverse(n) prime.
bool isEmirp(int n);
/// Cousin prime: n prime and (n-4) or (n+4) prime.
bool isCousinPrime(int n);
/// Chen prime: n prime and (n+2) prime or semiprime.
bool isChenPrime(int n);
/// Circular prime: all rotations of digits are prime.
bool isCircularPrime(int n);
/// Balanced prime: n = (prev_prime + next_prime) / 2.
bool isBalancedPrime(int n);
/// Palindromic prime: n prime and n == reverse(n).
bool isPalindromicPrime(int n);
/// Left-truncatable: remains prime when digits removed from left.
bool isLeftTruncatablePrime(int n);
/// Right-truncatable: remains prime when digits removed from right.
bool isRightTruncatablePrime(int n);
/// Truncatable (both): left- and right-truncatable.
bool isTruncatablePrime(int n);
/// True if every prime in [start, end] with n > 3 has form 6k±1.
bool satisfies6kPlusMinus1Form(int start, int end);
