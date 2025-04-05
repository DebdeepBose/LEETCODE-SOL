class Solution {
public:
    vector<int> generateRow(int rowIndex) {
        vector<int> row;
        long long val = 1;
        row.push_back(1);
        for (int i = 1; i < rowIndex; i++) {
            val = val * (rowIndex - i) / i;
            row.push_back(val);
        }
        return row;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};
