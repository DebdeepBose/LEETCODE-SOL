class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& v, int x, int y, int k) {
        int i = x;
        int j = x + k - 1;

        while(i < j) {
            for(int z = y; z < y + k; z++) {
                swap(v[i][z], v[j][z]);
            }
            i++;
            j--;
        }
        return v;
    }
};