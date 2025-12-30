class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& v) {
        int r = v.size();
        int c = v[0].size();
        int k = 0;

        if (r < 3 || c < 3) {
            return 0;
        }

        vector<vector<vector<int>>> to_check = {
            {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
            {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
            {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
            {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
            {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
            {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
            {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
            {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        };

        int start_row = 0, start_col = 0;
        for (start_row = 0; start_row <= r - 3; start_row++) {
            for (start_col = 0; start_col <= c - 3; start_col++) {
                vector<vector<int>> temp(3, vector<int>(3));
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        temp[i][j] = v[i + start_row][j + start_col];
                    }
                }
                for (auto& e : to_check) {
                    if (e == temp) {
                        k++;
                        break;
                    }
                }
            }
        }
        return k;
    }
};