class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));

        for (int i = 0; i < m; i++) {
            int b = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (v[i][j] == '#') {
                    ans[b][m - 1 - i] = '#';
                    b--;
                } else if (v[i][j] == '*') {
                    ans[j][m - 1 - i] = '*';
                    b = j - 1;
                }
            }
        }
        return ans;
    }
};
