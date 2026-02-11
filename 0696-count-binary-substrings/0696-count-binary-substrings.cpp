class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int c = 0;

        vector<int> groups;

        while (j < n) {
            if (s[j] != s[j + 1] || j + 1 == n) {
                groups.push_back(j - i + 1);
                i = j + 1;
            }
            j++;
        }

            for (int i = 0; i < groups.size() - 1; i++) {
            c += min(groups[i], groups[i + 1]);
        }

        return c;
    }
};