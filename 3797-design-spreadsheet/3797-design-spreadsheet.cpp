class Spreadsheet {
private:
    vector<vector<int>> grid;

    pair<int , int> parseCell(string& cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        return {row , col};
    }

    int evalToken(string& token) {
        if (isalpha(token[0])) {
            auto [row , col] = parseCell(token);
            if (row >= 0 && row < grid.size() && col >= 0 && col < 26) return grid[row][col];
            return 0;
        }
        else return stoi(token);
    }

public:
    Spreadsheet(int rows) {
        grid.assign(rows , vector<int>(26 , 0));
    }
    
    void setCell(string cell, int value) {
        auto [row , col] = parseCell(cell);
        if (row >= 0 && row < grid.size() && col >= 0 && col < 26) grid[row][col] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell , 0);
    }
    
    int getValue(string formula) {
        size_t plus = formula.find('+' , 1);
        string token1 = formula.substr(1 , plus - 1);
        string token2 = formula.substr(plus + 1);

        return evalToken(token1) + evalToken(token2);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */