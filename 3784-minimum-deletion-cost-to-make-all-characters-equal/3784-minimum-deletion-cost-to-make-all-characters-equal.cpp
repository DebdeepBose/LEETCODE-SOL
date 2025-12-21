class Solution {
public:
    long long minCost(string s, vector<int>& v) {
        unordered_map<char, long long> mp;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            mp[s[i]] += v[i];
        }
        long long sum = accumulate(v.begin(), v.end(), 0LL);
        long long minOp = LLONG_MAX;
        for (auto e : mp) {
            minOp = min(minOp, sum - e.second);
        }
        return minOp;
    }
};