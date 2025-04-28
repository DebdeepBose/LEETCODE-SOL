class Solution {
public:
    long long countSubarrays(vector<int>& v, long long k) {
        int left = 0;
        int right = 0;
        int n = v.size();
        long long sum = 0;
        long long c = 0;
        while (right < n) {
            sum += v[right];
            while (sum * (right - left + 1) >= k) {
                sum -= v[left];
                left++;
            }
            c += (right - left + 1);
            right++;
        }
        return c;
    }
};