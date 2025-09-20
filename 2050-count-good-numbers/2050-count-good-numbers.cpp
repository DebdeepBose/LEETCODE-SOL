class Solution {
public:
    long long mod = 1e9 + 7;

    long long power(long long x, long long y) {
        if (y == 0) {
            return 1;
        }
        long long temp = power(x, y / 2) % mod;
        temp = (temp * temp) % mod;
        if (y % 2 == 1) {
            temp = (temp * x) % mod;
        }
        return temp;
    }

    int countGoodNumbers(long long n) {
        /* This is the pattern it follows
         1 -> 5
         2 -> 20
         3 -> 100
         4 -> 400
         5 -> 2000

         so like the odd positions (1-based) have 5 choices, even positions have 4 choices
         we just raise 5 to the count of odd positions and 4 to the count of even positions
         and multiply them together modulo 1e9+7 */
        
        long long oddCount = (n + 1) / 2;
        long long evenCount = n / 2;
        return (power(5, oddCount) * power(4, evenCount)) % mod;
    }
};
