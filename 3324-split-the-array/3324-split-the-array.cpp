class Solution {
public:
    bool isPossibleToSplit(vector<int>& v) {
        unordered_map<int, int> mp;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            mp[v[i]]++;
        }
        for (auto e : mp) {
            if (e.second > 2) {
                return false;
            }
        }
        return true;
    }
};