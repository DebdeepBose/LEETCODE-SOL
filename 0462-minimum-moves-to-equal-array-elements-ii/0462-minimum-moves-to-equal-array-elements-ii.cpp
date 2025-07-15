class Solution {
public:
    int minMoves2(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        int med = v[n / 2];
        int op = 0;
        for (auto e : v) {
            op += abs(med - e);
        }
        return op;
    }
};