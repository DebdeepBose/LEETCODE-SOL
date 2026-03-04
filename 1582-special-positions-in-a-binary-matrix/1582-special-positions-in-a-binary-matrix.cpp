class Solution {
public:
    int numSpecial(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<int> ver(m), hor(n);
        int id = 0;
        for (auto& row : v) {
            int sum = accumulate(row.begin(), row.end(), 0);
            ver[id++] = sum;
        }
        id = 0;
        int j = 0;
        while (j < n) {
            int sum = 0;
            int i = 0;
            while (i < m) {
                sum += v[i++][j];
            }
            hor[id++] = sum;
            j++;
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