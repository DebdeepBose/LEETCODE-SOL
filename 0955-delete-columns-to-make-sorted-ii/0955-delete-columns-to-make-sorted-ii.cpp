class Solution {
public:
    int minDeletionSize(vector<string>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<bool> ch(n - 1, false);
        int c = 0;

        for (int j = 0; j < m; j++) {
            bool flag = false;
            for (int i = 0; i < n - 1; i++) {
                if (!ch[i] && v[i][j] > v[i + 1][j]) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                c++;
                continue;
            }
            for (int i = 0; i < n - 1; i++) {
                if (!ch[i] && v[i][j] < v[i + 1][j]) {
                    ch[i] = true;
                }
            }
        }
        return c;
    }
};
