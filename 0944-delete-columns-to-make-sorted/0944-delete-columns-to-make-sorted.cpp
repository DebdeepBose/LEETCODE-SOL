class Solution {
public:
    int minDeletionSize(vector<string>& v) {
        int n = v.size();
        int j = 0;
        int c = 0;
        int t = v[0].size();
        while (t--) {
            string s = "";
            for (int i = 0; i < n; i++) {
                s += v[i][j];
            }
            for (int i = 0; i < s.size() - 1; i++) {
                if (s[i] > s[i + 1]) {
                    c++;
                    break;
                }
            }
            j++;
        }
        return c;
    }
};