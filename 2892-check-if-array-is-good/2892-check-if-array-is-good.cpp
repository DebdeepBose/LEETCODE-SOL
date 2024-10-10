class Solution {
public:
    bool isGood(vector<int>& v) {
        sort(v.begin(), v.end());
        if (v.size() != v.back() + 1) {
            return false;
        }
        unordered_map<int, int> mp;
        for (auto e : v) {
            mp[e]++;
        }
        bool f = false;
        for (auto e : mp) {
            if (e.first == v.back()) {
                if (e.second == 2) {
                    f = true;
                }
            } else {
                if (e.second > 1) {
                    return false;
                }
            }
        }
        return f;
    }
};