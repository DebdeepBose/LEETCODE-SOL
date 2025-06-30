class Solution {
public:
    int findLHS(vector<int>& v) {
        unordered_map<int, int> mp;
        for (auto e : v) {
            mp[e]++;
        }
        int maxsub = 0;
        for (auto e : mp) {
            int curr_num = e.first;
            int curr_freq = e.second;
            if (mp.find(curr_num + 1) != mp.end()) {
                maxsub = max(maxsub, curr_freq + mp[curr_num + 1]);
            }
        }
        return maxsub;
    }
};