class Solution {
public:
    int numRabbits(vector<int>& v) {
        unordered_map<int, int> mp;
        int rabbitCount = 0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            mp[v[i]]++;
        }
        for (auto e : mp) {
            rabbitCount += ceil((double)e.second / (e.first + 1)) * (e.first + 1);
        }
        return rabbitCount;
    }
};
