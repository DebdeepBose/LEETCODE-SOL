class Solution {
public:
    int tupleSameProduct(vector<int>& v) {
        unordered_map<int, int> mp;
        int ans = 0, n = v.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int product = v[i] * v[j];
                ans += 8 * mp[product];
                mp[product]++;
            }
        return ans;
    }
};