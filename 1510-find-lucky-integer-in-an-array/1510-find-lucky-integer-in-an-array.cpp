class Solution {
public:
    int findLucky(vector<int>& v) {
        unordered_map<int, int> mp;
        for (auto e : v) {
            mp[e]++;
        }
        int lucky = -1;
        for (auto e : v) {
            if (mp[e] == e) {
                lucky = max(lucky, e);
            }
        }
        return lucky;
    }
};