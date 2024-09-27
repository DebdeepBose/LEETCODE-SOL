class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> v(3, -1);
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            v[s[i] - 'a'] = i;
            ans += min({v[0], v[1], v[2]}) + 1;
        }
        return ans;
    }
};