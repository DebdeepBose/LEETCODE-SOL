class Solution {
public:
    int numSpecial(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<int> ver(m), hor(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ver[i] += v[i][j];
                hor[j] += v[i][j];
            }
        }

        int spCnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 1 && (ver[i] * hor[j]) <= 1) {
                    spCnt++;
                }
            }
        }
        return spCnt;
    }
};