class Solution {
public:
    int maxDifference(string s) {
        vector<int> mp(26, 0);
        for (auto e : s) {
            mp[e - 'a']++;
        }
        int e_min = INT_MAX;
        int o_max = INT_MIN;
        for (auto e : mp) {
            if (e % 2 == 0 && e > 0) {
                e_min = min(e_min, e);
            } else {
                o_max = max(o_max, e);
            }
        }
        return o_max - e_min;
    }
};