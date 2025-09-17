class Solution {
public:
    bool buddyStrings(string s, string g) {
        int c = 0;
        int n = s.size();
        int m = g.size();
        if (n != m) {
            return false;
        }
        if (s == g) {
            set<char> temp(s.begin(), s.end());
            return temp.size() < g.size();
        }
        int i = 0;
        int j = n - 1;

        while (i < j && s[i] == g[i]) {
            i++;
        }

        while (j >= 0 && s[j] == g[j]) {
            j--;
        }

        if (i < j) {
            swap(s[i], s[j]);
        }

        return s == g;
    }
};