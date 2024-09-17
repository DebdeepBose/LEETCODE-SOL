class Solution {
public:
    vector<int> twoSum(vector<int>& v, int k) {
        int n = v.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (v[i] + v[j] == k) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};