class Solution {
public:
    const int MOD = 1e9 + 7;

    // Fast power using iterative binary exponentiation
    long long power(long long x, long long n) {
        long long result = 1;
        x %= MOD;

        while (n > 0) {
            if (n % 2 == 1) { // If n is odd
                result = (result * x) % MOD;
            }
            x = (x * x) % MOD;
            n /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; // digits at even indices (0-based)
        long long odd = n / 2;        // digits at odd indices

        // 5 choices for even positions (0,2,4...) and 4 for odd (1,3,5...)
        return (power(5, even) * power(4, odd)) % MOD;
    }
};
