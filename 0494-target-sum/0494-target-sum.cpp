class Solution {
public:
    void helper(vector<int>& v, int t, int st, int i, int& c) {
        if (i == v.size()) {
            if (st == t) {
                c++;
            }
            return;
        }

        helper(v, t, st + v[i], i + 1, c);
        helper(v, t, st - v[i], i + 1, c);
    }
    int findTargetSumWays(vector<int>& v, int t) {
        int n = v.size();
        int c = 0;
        helper(v, t, 0, 0, c);
        return c;
    }
};