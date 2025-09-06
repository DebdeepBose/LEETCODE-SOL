class Solution {
private:
    // Compute prefix sum of steps up to n
    long long prefixSteps(long long n) {
        if (n <= 0) {
            return 0;
        }

        long long total = 0;
        long long power = 1; // 4^(k-1)
        long long step = 1;

        while (power <= n) {
            long long next = power * 4 - 1;
            long long high = min(n, next);
            long long cnt = high - power + 1;
            total += cnt * step;
            power *= 4;
            step++;
        }
        return total;
    }

public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto& q : queries) {
            long long l = q[0], r = q[1];
            long long totalSteps = prefixSteps(r) - prefixSteps(l - 1);
            ans += (totalSteps + 1) / 2; 
        }
        return ans;
    }
};