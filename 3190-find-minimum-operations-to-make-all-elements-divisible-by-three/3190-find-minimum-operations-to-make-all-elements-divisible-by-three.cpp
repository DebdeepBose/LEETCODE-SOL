class Solution {
public:
    int minimumOperations(vector<int>& v) {
        int n = v.size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] % 3 == 0) {
                c++;
            }
        }
        return n - c;
    }
};