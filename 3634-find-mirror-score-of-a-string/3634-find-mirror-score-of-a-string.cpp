class Solution {
public:
    long long calculateScore(string s) {
        long long c = 0;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < s.size(); i++) {
            int cur = s[i] - 'a', m = 25 - cur;
            if (mp.find(m) != mp.end() && mp[m].size() > 0) {
                c += (long long)i - (long long)mp[m].back();
                mp[m].pop_back();
            } else {
                mp[cur].push_back(i);
            }
        }
        return c;
    }
};