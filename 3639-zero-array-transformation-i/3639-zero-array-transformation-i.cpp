class Solution {
public:
    bool isZeroArray(vector<int>& v, vector<vector<int>>& q) {
        int n = v.size();
        vector<int> ls(n + 1, 0);
        // line sweep

        for (auto e : q) {
            ls[e[0]]++;
            ls[e[1] + 1]--;
        }

        int pref = 0;
        for (int i = 0; i < n; i++) {
            pref += ls[i];
            if (pref < v[i]) {
                return false;
            }
        }
        return true;
    }
};