class Solution {
public:
    int countMaxOrSubsets(vector<int>& v) {
        int maxor = 0;
        for (auto e : v) {
            maxor |= e;
        }
        return helper(v, maxor, 0, 0);
    }

private:
    int helper(vector<int>& v, int maxor, int idx, int currOr) {
        if (idx == v.size()) {
            if (currOr == maxor) {
                return 1;
            } else {
                return 0;
            }
        }
        if (currOr == maxor) {
            return 1 << (v.size() - idx);
        }
        int take = helper(v, maxor, idx + 1, currOr | v[idx]);
        int skip = helper(v, maxor, idx + 1, currOr);
        return take + skip;
    }
};