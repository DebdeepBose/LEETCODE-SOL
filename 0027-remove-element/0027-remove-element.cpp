class Solution {
public:
    int removeElement(vector<int>& v, int k) {
        int n = v.size(), c = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] != k) {
                v[c] = v[i];
                c++;
            }
        }
        return c;
    }
};