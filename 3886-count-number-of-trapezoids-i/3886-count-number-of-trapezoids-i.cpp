class Solution {
public:
    int countTrapezoids(vector<vector<int>>& v) {
        int MOD = 1000000007;
        unordered_map<int, long long> mp;
        for (auto e : v) {
            mp[e[1]]++;
        }
        long long res = 0, total = 0;
        for (auto e : mp) {
            long long lines = e.second * (e.second - 1) / 2;
            res = (res + total * lines) % MOD;
            total = (total + lines) % MOD;
        }
        return (int)res;
    }
};