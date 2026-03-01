class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        long long res = 0;
        int leftd = 0, leftv = 0, vcount = 0;
        unordered_map<int, int> countd, countv;

        int right = 0;
        while (right < (int)nums.size()) {
            countd[nums[right]]++;

            while ((int)countd.size() > k) {
                if ((countd[nums[leftd]]--) == 1) {
                    countd.erase(nums[leftd]);
                }
                leftd++;
            }

            if (((countv[nums[right]]++) + 1) == m) {
                vcount++;
            }

            while (vcount >= k) {
                if ((countv[nums[leftv]]--) == m) {
                    vcount--;
                }
                leftv++;
            }

            if ((leftv > leftd)) {
                res += (leftv - leftd);
            }

            right++;
        }

        return res;
    }
};