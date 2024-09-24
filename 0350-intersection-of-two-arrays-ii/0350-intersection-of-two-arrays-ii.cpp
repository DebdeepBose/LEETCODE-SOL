class Solution {
public:
    vector<int> intersect(vector<int>& u, vector<int>& v) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (auto e : u) {
            mp[e]++;
        }
        for (auto e : v) {
            if (mp[e] > 0) {
                mp[e]--;
                ans.push_back(e);
            }
        }
        return ans;
    }
};