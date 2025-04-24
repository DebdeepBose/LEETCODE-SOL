class Solution {
public:
    int countNicePairs(vector<int>& v) {
        unordered_map<int, int> mp;
        int n = v.size();
        long long c = 0;
        int MOD = 1e9 + 7;
        
        for (int i = 0; i < n; i++) {
            string s = to_string(v[i]);
            reverse(s.begin(), s.end());
            int rev = stoi(s);
            int diff = v[i] - rev;

            c = (c + mp[diff]) % MOD;
            mp[diff]++;
        }

        return c;
    }
};
