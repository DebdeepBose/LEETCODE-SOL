class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size == 1) {
            return intervals;
        }

        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (int i = 0; i < size; i++) {
            // If merged is empty or current interval doesn't overlap with the last one
            if (merged.empty() || intervals[i][0] > merged.back()[1]) {
                merged.push_back(intervals[i]);
            } else {
                // Merge by updating the end of the last interval
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            }
        }

        return merged;
    }
};
