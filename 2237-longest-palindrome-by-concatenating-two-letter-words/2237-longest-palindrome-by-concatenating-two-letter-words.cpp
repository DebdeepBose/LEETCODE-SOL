class Solution {
public:
    int longestPalindrome(vector<string> v) {
        unordered_map<string, int> mp;
        int len = 0;
        bool hasCentral = false;

        for (int i = 0; i < v.size(); i++) {
            mp[v[i]]++;
        }

        for (auto it : mp) {
            string e = it.first;
            int f = it.second;
            string rev = e;
            reverse(rev.begin(), rev.end());

            if (e == rev) {
                len += (f / 2) * 4;
                if (f % 2 == 1) {
                    hasCentral = true;
                }
            } else if (mp.find(rev) != mp.end()) {
                int c = min(f, mp[rev]);
                len += c * 4;
                mp[rev] = 0;
                mp[e] = 0;
            }
        }

        if (hasCentral) {
            len += 2;
        }

        return len;
    }
};
