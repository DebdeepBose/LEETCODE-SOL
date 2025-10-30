class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        int n = nums.size();

        long long maxSq = 0;
        for (int i = 0; i < n; i++) {
            nums[i] = (nums[i] * nums[i]);
        }

        sort(nums.begin(), nums.end());

        int i = 0;
        int j = n - 1;

        while (i <= j) {
            if (i == j) {
                maxSq += nums[i];
                break;
            }
            maxSq += (nums[j] - nums[i]);

            i++;
            j--;
        }

        return maxSq;
    }
};