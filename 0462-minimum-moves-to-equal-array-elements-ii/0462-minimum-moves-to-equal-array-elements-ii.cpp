class Solution {
public:
    int minMoves2(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        int med = 0;
        if (n % 2 == 1) {
            med = v[n / 2];
        } else {
            med = (v[(n / 2) - 1] + v[n / 2]) / 2;
        }
        int op = 0;
        for (auto e : v) {
            op += abs(med - e);
        }
        return op;
    }
};