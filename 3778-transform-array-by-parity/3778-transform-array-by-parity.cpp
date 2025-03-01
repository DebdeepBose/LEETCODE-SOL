class Solution {
public:
    vector<int> transformArray(vector<int>& v) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i] % 2 == 0) {
                v[i] = 0;
            } else {
                v[i] = 1;
            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};