class Solution {
public:
    int maximizeGreatness(vector<int>& v) {
        unordered_map<int, int> mp;
        int k = 0;
        for (auto e : v) {
            mp[e]++;
            k = max(k, mp[e]);
        }
        return v.size() - k;
    }
};