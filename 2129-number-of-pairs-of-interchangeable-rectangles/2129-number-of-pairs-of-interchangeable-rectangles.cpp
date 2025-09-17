class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& v) {
        int n = v.size();
        vector<double> r;
        for (int i = 0; i < n; i++) {
            r.push_back((double)v[i][1] / (double)v[i][0]);
        }
        unordered_map<double, int> mp;
        for (auto e : r) {
            mp[e]++;
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