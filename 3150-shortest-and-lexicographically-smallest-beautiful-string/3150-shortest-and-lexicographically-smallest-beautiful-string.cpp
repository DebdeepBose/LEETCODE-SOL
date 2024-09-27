class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = 0, r = 0;
        int n = s.size();
        vector<string> v;
        int c = 0;
        int minlen = INT_MAX;

        while (r < n) {
            if (s[r] == '1') {
                c++;
            }
            while (c >= k) {
                if (c == k) {
                    int currlen = r - l + 1;
                    if (currlen <= minlen) {
                        if (currlen < minlen) {
                            v.clear();
                            minlen = currlen;
                        }
                        v.push_back(s.substr(l, currlen));
                    }
                }
                if (s[l] == '1') {
                    c--;
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
