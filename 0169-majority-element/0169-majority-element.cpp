class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // Using Moore's Voting Algo
        // So what happens is
        int size = nums.size();

        // tkae candidate
        int current_candidate = 0;

        // take count
        int count = 0;

        for (int i = 0; i < size; i++) {
            if (count == 0) {
                current_candidate = nums[i];
            }
            if (nums[i] == current_candidate) {
                count++;
            } else {
                count--;
            }
        }
        return current_candidate;
    }
};