class Solution {
public:
    int countDigits(int n) {
        unordered_map<int, int> digits;
        int m = n;
        while (n > 0) {
            int d = n % 10;
            digits[d]++;
            n /= 10;
        }

        int ans = 0;

        for (auto& digit : digits) {
            if (m % digit.first == 0) {
                ans += digit.second;
            }
        }
        return ans;
    }
};