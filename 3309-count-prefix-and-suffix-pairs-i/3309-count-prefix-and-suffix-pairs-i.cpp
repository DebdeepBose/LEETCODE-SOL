class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& v) {
        int n = v.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            string s1 = v[i];
            for (int j = i + 1; j < n; j++) {
                string s2 = v[j];
                if (s2.size() < s1.size()) {
                    continue;
                }
                string pre = s2.substr(0, s1.size());
                string suf = s2.substr(s2.size() - s1.size());
                if (pre == s1 && suf == s1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};