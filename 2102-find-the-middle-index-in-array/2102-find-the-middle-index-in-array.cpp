class Solution {
public:
    int findMiddleIndex(vector<int>& v) {
        int n = v.size();
        int ls = 0;
        int rs = accumulate(v.begin(), v.end(), 0);
        for (int i = 0; i < n; i++) {
            rs -= v[i];
            if (rs == ls) {
                return i;
            }
            ls += v[i];
        }
        return -1;
    }
};