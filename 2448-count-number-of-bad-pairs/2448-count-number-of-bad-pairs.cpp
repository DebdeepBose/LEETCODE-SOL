class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = (nums.size() * (nums.size() - 1))/2;
        unordered_map<long long, int> freq;

        for(int i = 0; i < nums.size(); i++) {
            if(freq[i - nums[i]]) {
                ans -= freq[i - nums[i]];
            }

            freq[i - nums[i]]++;;
        }

        return ans;
    }
};