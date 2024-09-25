class Solution {
public:
    int minMoves(vector<int>& v) {
        int mini = INT_MAX;
        for (int e : v) {
            mini = min(mini, e);
        }
        int ans = 0;
        for (int e : v) {
            ans += e - mini;
        }
        return ans;
    }
};