class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (auto e : t) {
            mp[e]++;
        }
        int l = 0;
        int r = 0;
        int n = s.size();
        int mini = INT_MAX;
        int c = 0;      // Dats required k?
        int stidx = -1; // starting substr index :)
        while (r < n) {
            if (mp[s[r]] > 0) {
                c++;
            }
            mp[s[r]]--;
            while (c == t.size()) {
                if (r - l + 1 < mini) {
                    mini = r - l + 1;
                    stidx = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) {
                    c--;
                }
                l++;
            }
            r++;
        }
        return stidx == -1 ? "" : s.substr(stidx, mini);
    }
};