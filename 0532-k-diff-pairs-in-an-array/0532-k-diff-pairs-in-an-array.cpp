class Solution {
public:
    int findPairs(vector<int>& v, int k) {
        if (k < 0) {
            return 0;
        }

        unordered_map<int, int> mp;
        int n = v.size();
        int c = 0;

        for (int i = 0; i < n; i++) {
            mp[v[i]]++;
        }

        for (auto [num, freq] : mp) {
            int req = num + k;
            if (k == 0) {
                if (freq > 1) {
                    c++;
                }
            } else {
                if (mp.find(req) != mp.end()) {
                    c++;
                }
            }
        }

        return c;
    }
};
