class Solution {
public:
    bool checkPrime(int x) {
        if (x == 1) {
            return false;
        }
        if (x == 2 || x == 3) {
            return true;
        }
        if (x % 2 == 0 || x % 3 == 0) {
            return false;
        }
        for (int i = 5; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        int j = 0;
        int maxPrime = 0;
        for (int i = 0; i < n; i++) {
            if (checkPrime(v[i][j])) {
                maxPrime = max(maxPrime, v[i][j]);
            }
            if (v[i][j] != v[i][m - j - 1] && checkPrime(v[i][m - j - 1])) {
                maxPrime = max(maxPrime, v[i][m - j - 1]);
            }
            j++;
        }
        return maxPrime;
    }
};