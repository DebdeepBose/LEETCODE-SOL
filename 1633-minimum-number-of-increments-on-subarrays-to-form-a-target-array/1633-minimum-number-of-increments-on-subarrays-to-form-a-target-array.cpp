class Solution {
public:
    int minNumberOperations(vector<int>& v) {

        int ans = v[0];
        int n = v.size();

        for (int i = 1; i < n; i++) {
            ans += max(v[i] - v[i - 1], 0);
        }

        return ans;
    }
};
