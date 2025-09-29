class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int maxlen = 0;
        deque<int> maxDeq;
        deque<int> minDeq;
        while (j < n) {

            while (!maxDeq.empty() && maxDeq.back() < nums[j]) {
                maxDeq.pop_back();
            }
            maxDeq.push_back(nums[j]);

            while (!minDeq.empty() && minDeq.back() > nums[j]) {
                minDeq.pop_back();
            }
            minDeq.push_back(nums[j]);

            while (!maxDeq.empty() && !minDeq.empty() &&
                   maxDeq.front() - minDeq.front() > limit) {
                if (nums[i] == maxDeq.front()) {
                    maxDeq.pop_front();
                }
                if (nums[i] == minDeq.front()) {
                    minDeq.pop_front();
                }
                i++;
            }
            maxlen = max(maxlen, j - i + 1);
            j++;
        }

        return maxlen;
    }
};