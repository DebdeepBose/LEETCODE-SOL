class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& v) {
        int n = v.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            ans.push_back(v[(i + (v[i] % n) + n) % n]);
        }
        return ans;
    }
};
