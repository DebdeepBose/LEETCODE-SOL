class Solution {
public:
    int minMoves(vector<int>& v) {
        sort(v.begin(), v.end());
        if (v[0] == v.back()) {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < v.size(); i++) {
            res += (v[i] - v[0]);
        }

        return res;
    }
};