class Solution {
public:
    static bool sortByStart(const vector<int>& a, const vector<int>& b) {
        return a < b;   // lexicographical: start, end, value
    }

    static bool sortByEnd(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int maxTwoEvents(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), sortByStart);

        vector<vector<int>> endSorted = v;
        sort(endSorted.begin(), endSorted.end(), sortByEnd);

        int n = v.size();
        vector<int> maxValueTill(n);

        maxValueTill[0] = endSorted[0][2];
        for (int i = 1; i < n; i++) {
            maxValueTill[i] = max(maxValueTill[i - 1], endSorted[i][2]);
        }

        int ans = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            int start = v[i][0];
            int value = v[i][2];

            while (j < n && endSorted[j][1] < start) {
                j++;
            }

            ans = max(ans, value);

            if (j > 0) {
                ans = max(ans, value + maxValueTill[j - 1]);
            }
        }

        return ans;
    }
};
