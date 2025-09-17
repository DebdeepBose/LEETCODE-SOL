class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& v) {
        int n = v.size();
        unordered_map<double, int> mp;
        for (int i = 0; i < n; i++) {
            mp[(double)v[i][1] / (double)v[i][0]]++;
        }
        long long in = 0;
        for (auto e : mp) {
            if (e.second > 1) {
                long long el = e.second - 1;
                long long sum = el * (el + 1) / 2;
                in += sum;
            }
        }
        return in;
    }
};