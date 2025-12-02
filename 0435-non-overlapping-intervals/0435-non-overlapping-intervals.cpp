class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int n = v.size();
        sort(v.begin(), v.end(), cmp);

        int iv = 0;
        int c = 0;
        for (int i = 1; i < n; i++) {
            if (v[i][0] < v[iv][1]) {
                c++;
            } else {
                iv = i;
            }
        }
        return c;
    }
};