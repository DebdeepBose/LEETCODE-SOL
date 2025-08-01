class Solution {
public:
    unordered_map<int, vector<int>> mp;
    Solution(vector<int>& v) {
        int n = v.size();
        for (int i = 0; i < n; i++) {
            mp[v[i]].push_back(i);
        }
    }

    int pick(int t) {
        vector<int> tmp = mp[t];
        return tmp[rand() % tmp.size()];
    }
};