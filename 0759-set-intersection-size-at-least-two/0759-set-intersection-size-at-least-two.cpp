class Solution {
public:
    static bool cmp(const vector<int>& x, const vector<int>& y) {
        if (x[1] == y[1]) {
            return x[0] > y[0];
        }
        return x[1] < y[1];
    }

    int intersectionSizeTwo(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), cmp);

        int p1 = -1;
        int p2 = -1;
        int c = 0;

        for (auto e : v) {
            int l = e[0];
            int r = e[1];

            if (l > p2) {
                p1 = r - 1;
                p2 = r;
                c += 2;
            } 
            else if (l > p1) {
                p1 = p2;
                p2 = r;
                c += 1;
            }
        }
        return c;
    }
};
