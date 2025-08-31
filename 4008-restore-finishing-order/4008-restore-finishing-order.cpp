class Solution {
public:
    vector<int> recoverOrder(vector<int>& o, vector<int>& f) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto e : f) {
            mp[e]++;
        }
        for (auto e : o) {
            if (mp[e] == 1) {
                ans.push_back(e);
            }
        }
        return ans;
    }
};