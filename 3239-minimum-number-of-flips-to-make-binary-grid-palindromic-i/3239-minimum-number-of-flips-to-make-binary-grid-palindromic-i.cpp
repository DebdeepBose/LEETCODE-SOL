class Solution {
    int cntRowFlips(vector<int>& row) {
        int c = 0;
        int i = 0;
        int j = row.size() - 1;
        while (i < j) {
            if (row[i] != row[j]) {
                c++;
            }
            i++;
            j--;
        }
        return c;
    }

    int cntColFlips(vector<vector<int>>& v, int col) {
        int c = 0;
        int i = 0;
        int j = v.size() - 1;
        while (i < j) {
            if (v[i][col] != v[j][col]) {
                c++;
            }
            i++;
            j--;
        }
        return c;
    }

public:
    int minFlips(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        int rowFlips = 0;
        for (int i = 0; i < m; i++) {
            rowFlips += cntRowFlips(v[i]);
        }

        int colFlips = 0;
        for (int j = 0; j < n; j++) {
            colFlips += cntColFlips(v, j);
        }

        return min(rowFlips, colFlips);
    }
};