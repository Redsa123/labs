//
// Created by redsa on 25.11.25.
//

#include <iostream>
#include <cmath>
#include <algorithm>

// Function prototypes (definitions will follow)
long long next_prime(long long n);
long long prime_count_pi(long long x);
long long calculate_lower_bound(long long k);

long long find_kth_prime(long long k) {
    if (k < 1) return -1; // Error for invalid k
    if (k == 1) return 2; // p_1 = 2

    // Step 1: Get an estimate for the starting prime p
    long long L = calculate_lower_bound(k);
    long long p = next_prime(L);

    // Step 2 & 3: Iterate until the index m matches k
    long long m = prime_count_pi(p);

    // Iterate until we find p_k
    while (m != k) {
        if (m < k) {
            // The estimate p is too small, move to the next prime(s)
            p = next_prime(p + 1);
            m++; // Since p is the next prime, the count increases by 1
        } else { // m > k
            // The estimate p is too large, step backward to find p_k
            // This case is rare if the initial bound L is good, but required for completeness.
            // Note: Stepping backward requires a pre-computed list of primes or complex sieving.
            // A simpler approach for *m > k* is to refine the estimate for 'p' down and repeat,
            // or simply assume the lower bound L is very close.

            // For a simplified implementation, we'll assume the initial estimate is close enough
            // that m won't be much larger than k, and just finding the L's *exact* p_k is the goal.
            // Since the formula is a lower bound, m should rarely be much larger than k.

            // In a real implementation, you'd need a method to find the (m-k)-th prime *before* p.
            // For safety, let's just break for simplicity if the gap is too large.
            std::cout << "Warning: The estimate was significantly larger than k. Exiting early." << std::endl;
            return -1;
        }
    }

    return p; // p is the kth prime
}

long long calculate_lower_bound(long long k) {
    // k is n in the formula
    if (k < 2) return 2; // Safe return for k=1. The formula is valid for k >= 2.

    double dk = static_cast<double>(k);

    // The C++ 'log' function is natural log (ln)
    double lnk = std::log(dk);
    double lnlnk = std::log(lnk);

    // Formula: k * (ln(k) + ln(ln(k)) - 1)
    double lower_bound_double = dk * (lnk + lnlnk - 1.0);

    // Return the ceiling of the lower bound to ensure L <= p_k
    // Note: The formula is strict (p_k > L), so L = floor(L_double) is safer
    // The programming task requires L <= p_k, so let's use the floor/cast for simplicity.
    return static_cast<long long>(std::floor(lower_bound_double));
}


// --- Simplified next_prime implementation using trial division (SLOW for large numbers) ---

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (long long i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

long long next_prime(long long n) {
    if (n < 2) return 2;
    long long p = n;
    while (true) {
        if (is_prime(p)) {
            return p;
        }
        p++;
    }
}

// For large numbers, replace is_prime with the Miller-Rabin test for better performance.


// --- Simplified prime_count_pi implementation using Sieve (Only for SMALL x) ---

long long prime_count_pi(long long x) {
    if (x < 2) return 0;

    // Threshold for simple sieve (e.g., up to 10^7 or 10^8)
    // For x beyond this, you must use Meissel-Lehmer.
    long long threshold = 1000000;

    if (x <= threshold) {
        // Simple Sieve of Eratosthenes implementation
        std::vector<bool> is_prime_vec(x + 1, true);
        is_prime_vec[0] = is_prime_vec[1] = false;
        long long count = 0;

        for (long long p = 2; p * p <= x; p++) {
            if (is_prime_vec[p]) {
                for (long long i = p * p; i <= x; i += p)
                    is_prime_vec[i] = false;
            }
        }

        for (long long p = 2; p <= x; p++) {
            if (is_prime_vec[p]) count++;
        }
        return count;
    } else {
        // !!! Placeholder for Meissel-Lehmer !!!
        // Implementation of the Meissel-Lehmer method is required here for large x.
        // It's a complex combinatorial algorithm.
        std::cout << "Error: Meissel-Lehmer method not implemented. Cannot compute pi(" << x << ") for large x." << std::endl;
        return -1;
    }
}

int main() {
    std::cout << find_kth_prime(100) << std::endl;

    return 0;
}