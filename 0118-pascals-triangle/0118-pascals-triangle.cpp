class Solution {
public:
    // Function to generate a specific row in Pascal's Triangle
    vector<int> generateRow(int rowIndex) {
        vector<int> row;

        // First value of each row is always 1
        long long triangleCellValue = 1;
        row.push_back(1);

        // Calculate remaining values using nCr = nC(r-1) * (n-r)/r
        for (int i = 1; i < rowIndex; i++) {
            triangleCellValue = triangleCellValue * (rowIndex - i) / i;
            row.push_back(triangleCellValue);
        }

        return row;
    }

    // Function to generate Pascal's Triangle up to numRows
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> resultant_pascalTriangle;

        // Generate each row from 1 to numRows using generateRow function
        for (int i = 1; i <= numRows; i++) {
            resultant_pascalTriangle.push_back(generateRow(i));
        }

        return resultant_pascalTriangle;
    }
};
