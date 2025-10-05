class Solution {
public:
    int alternatingSum(vector<int>& v) {
        int os = 0;
        int es = 0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                es += v[i];
            } else {
                os += v[i];
            }
        }
        return es - os;
    }
};