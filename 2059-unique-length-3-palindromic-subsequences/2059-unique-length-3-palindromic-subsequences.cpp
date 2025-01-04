class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> mini(26, INT_MAX);
        vector<int> maxi(26, INT_MIN);
        for(int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            mini[c] = min(mini[c], i);
            maxi[c] = max(maxi[c], i);
        }
        int idx = 0;
        for (int c = 0; c < 26; c++) {
            if (mini[c] == INT_MAX || maxi[c] == INT_MIN) {
                continue;
            }
            unordered_set<char> st;
            for (int j = mini[c] + 1; j < maxi[c]; j++) {
                st.insert(s[j]);
            }
            idx += st.size();
        }
        return idx;
    }
};
