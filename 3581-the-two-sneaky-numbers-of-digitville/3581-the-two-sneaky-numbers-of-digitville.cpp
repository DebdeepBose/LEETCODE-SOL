class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto e : nums) {
            if (mp.count(e)) {
                ans.push_back(e);
            }
            mp[e]++;
        }

        return ans;
    }
};