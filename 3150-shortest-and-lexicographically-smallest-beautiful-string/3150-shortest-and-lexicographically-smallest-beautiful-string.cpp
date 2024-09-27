class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = 0, r = 0;
        int n = s.size();
        vector<string> v;
        unordered_map<char, int> mp;
        int minlen = numeric_limits<int>::max();

        while (r < n) {
            mp[s[r]]++;
            
            while (mp['1'] >= k) {
                if (mp['1'] == k) {
                    int currlen = r - l + 1;
                    if (currlen <= minlen) {
                        if (currlen < minlen) {
                            v.clear();
                            minlen = currlen;
                        }
                        v.push_back(s.substr(l, currlen));
                    }
                }
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }
            r++;
        }

        if (v.empty()) {
            return "";
        }
        
        sort(v.begin(), v.end());
        return v.front();
    }
};