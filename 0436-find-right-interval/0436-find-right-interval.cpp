class Solution {
public:
    int findRI(int last, vector<pair<int, int>>& starts) {
        int low = 0, high = starts.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (starts[mid].first >= last) {
                ans = starts[mid].second; 
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans(n, -1);
        vector<pair<int, int>> starts;
        for (int i = 0; i < n; i++) {
            starts.push_back({intervals[i][0], i});
        }
        sort(starts.begin(), starts.end());
        for (int i = 0; i < n; i++) {
            int idx = findRI(intervals[i][1], starts);
            ans[i] = idx;
        }

        return ans;
    }
};
