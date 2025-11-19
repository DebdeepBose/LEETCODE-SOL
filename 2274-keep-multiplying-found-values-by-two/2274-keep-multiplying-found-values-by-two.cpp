class Solution {
public:
    int findFinalValue(vector<int>& v, int x) {
        sort(v.begin(),v.end());
        int n = v.size();
        for (int i = 0; i < n; i++) {
            if (v[i] == x) {
                x *= 2;
            }
        }
        return x;
    }
};