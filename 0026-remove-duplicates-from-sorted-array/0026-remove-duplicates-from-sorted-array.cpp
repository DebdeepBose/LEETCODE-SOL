class Solution {
public:
    int removeDuplicates(vector<int>& v) {

        int j = 1;
        int n = v.size();

        for (int i = 1; i < n; i++) {
            if (v[i - 1] != v[i]) {
                v[j] = v[i];
                j++;
            }
        }
        return j;
    }
};