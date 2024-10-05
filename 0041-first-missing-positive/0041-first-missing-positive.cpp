class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        int n = v.size();
        vector<int> mp(n + 1, 0);

        for (auto e : v) {
            if (e > 0 && e <= n) {
                mp[e]++;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (mp[i] == 0) {
                return i;
            }
        }

        return n + 1;
    }
};
