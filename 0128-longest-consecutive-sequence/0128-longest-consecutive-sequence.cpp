class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // If the input array is empty, return 0
        if (nums.empty()) {
            return 0;
        }

        // Using an unordered_set for quick lookups to check if a number exists
        unordered_set<int> numSet(nums.begin(), nums.end());

        int longestStreak = 1; // Stores the maximum length of the consecutive sequence

        // Iterate through each unique number in the set
        for (int num : numSet) {
            // Check if 'num' is the start of a new sequence (i.e., num-1 is not in the set)
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // Continue counting the length of the sequence
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                // Update the longest streak found so far
                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
