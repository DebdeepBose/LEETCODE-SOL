class Solution {
public:
    int maxAdjacentDistance(vector<int>& v) {
        int n = v.size();
        int maxdif = INT_MIN;
        for (int i = 0; i < n; i++) {
            int dif = abs(v[i] - v[(i + 1) % n]);
            maxdif = max(maxdif, dif);
        }

        return maxdif;
    }
};