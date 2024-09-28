class Solution {
public:
    vector<int> findArray(vector<int>& v) {
        int n = v.size();
        for (int i = n - 1; i >= 1; i--) {
            v[i] ^= v[i - 1];
        }
        return v;
    }
};