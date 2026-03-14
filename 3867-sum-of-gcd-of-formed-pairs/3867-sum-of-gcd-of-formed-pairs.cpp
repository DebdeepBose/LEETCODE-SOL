class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixGCD(n);
        prefixGCD[0] = nums[0];
        long long curMax = nums[0];
        for (int i = 1; i < n; i++) {
            curMax = max(curMax, (long long)nums[i]);
            prefixGCD[i] = __gcd((long long)nums[i], curMax);
        }
        sort(prefixGCD.begin(), prefixGCD.end());
        int left = 0;
        int right = n - 1;
        long long sum = 0LL;
        while (left < right) {
            sum += __gcd(prefixGCD[left++], prefixGCD[right--]);
        }
        return sum;
    }
};