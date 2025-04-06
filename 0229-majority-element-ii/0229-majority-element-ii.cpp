class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // We are looking for all elements that appear more than ⌊n/3⌋ times in
        // the array. According to the extended Boyer-Moore Voting Algorithm,
        // there can be at most 2 such elements in any array.

        int candidate1, candidate2; // Possible majority elements
        int count1 = 0, count2 = 0; // Counts of candidate1 and candidate2
        int size = nums.size();

        // First Pass: Identify the two potential candidates
        for (int i = 0; i < size; i++) {
            if (count1 == 0 && nums[i] != candidate2) {
                // Assign new candidate1
                candidate1 = nums[i];
                count1 = 1;
            } else if (count2 == 0 && nums[i] != candidate1) {
                // Assign new candidate2
                candidate2 = nums[i];
                count2 = 1;
            } else if (nums[i] == candidate1) {
                count1++;
            } else if (nums[i] == candidate2) {
                count2++;
            } else {
                // Current number doesn't match any candidate, decrease both
                // counts
                count1--;
                count2--;
            }
        }

        // Second Pass: Confirm actual frequencies of the candidates
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == candidate1) {
                count1++;
            }
            if (nums[i] == candidate2) {
                count2++;
            }
        }

        // Collect final results based on actual counts
        vector<int> majorityElementArray;
        if (count1 > floor(size / 3)) {
            majorityElementArray.push_back(candidate1);
        }
        if (count2 > floor(size / 3) && candidate1 != candidate2) {
            majorityElementArray.push_back(candidate2);
        }

        return majorityElementArray;
    }
};
