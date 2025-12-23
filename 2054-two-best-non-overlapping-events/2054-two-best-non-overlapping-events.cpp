class Solution {
public:
    static bool sortByEnd(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    static bool sortByStart(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    int maxTwoEvents(vector<vector<int>>& v) {
        vector<vector<int>> es = v;
        vector<vector<int>> ss = v;

        sort(es.begin(), es.end(), sortByEnd);
        sort(ss.begin(), ss.end(), sortByStart);

        int ans = 0;
        for (auto& e : v)
            ans = max(ans, e[2]);

        int end_max = 0;
        int j = 0;

        for (auto& e : ss) {
            int start = e[0];
            int value = e[2];

            while (j < es.size() && es[j][1] < start) {
                end_max = max(end_max, es[j][2]);
                j++;
            }

            ans = max(ans, value + end_max);
        }

        return ans;
    }
};
