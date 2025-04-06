class Solution {
public:
    vector<int> genRow(int row) {
        long long res = 1;
        vector<int> rowGen;
        rowGen.push_back(1);
        for (int i = 1; i < row; i++) {
            res = res * (row - i) / i;
            rowGen.push_back(res);
        }
        return rowGen;
    }
    vector<vector<int>> generate(int n) {
        if (n == 0) {
            return {{}};
        }

        vector<vector<int>> ans;

        for (int i = 1; i <= n; i++) {
            ans.push_back(genRow(i));
        }

        return ans;
    }
};