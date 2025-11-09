class Solution {
public:
    int minimumDistance(vector<int>& v) {

        int minDist = INT_MAX;
        int n = v.size();

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (v[i] == v[j] && v[j] == v[k]) {
                        int dist = abs(i - j) + abs(j - k) + abs(k - i);
                        minDist = min(minDist, dist);
                    }
                }
            }
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};