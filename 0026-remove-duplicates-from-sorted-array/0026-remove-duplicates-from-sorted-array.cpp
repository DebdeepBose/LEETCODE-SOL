class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int n = v.size();

        int j = 1;
        for (int i = 1; i < n; i++) {
            if (v[i - 1] != v[i]) {
                v[j] = v[i];
                j++;
            }
        }
        return j;
    }
};