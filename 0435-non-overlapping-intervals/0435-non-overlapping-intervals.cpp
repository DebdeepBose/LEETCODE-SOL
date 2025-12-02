class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](auto& a, auto& b) { return a[1] < b[1]; });

        int removals = 0;
        int lastEnd = v[0][1];

        for (int i = 1; i < v.size(); i++) {

            if (v[i][0] < lastEnd) {
                removals++;
            } else {
                lastEnd = v[i][1];
            }
        }

        return removals;
    }
};
