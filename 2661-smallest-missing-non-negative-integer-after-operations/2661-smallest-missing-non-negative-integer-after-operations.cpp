class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int v) {
        int n = nums.size();
        int x = 0;
        int ans = 0;
        vector<int> rem(v, 0);
        for (int i = 0; i < n; i++) {
            x = ((nums[i] % v) + v) % v;
            rem[x]++;
        }

        while (rem[ans % v]--) {
            ans++;
        }
        return ans;
    }
};