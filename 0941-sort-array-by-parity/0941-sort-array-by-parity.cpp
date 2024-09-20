class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& v) {
        if (v.size() == 1) {
            return v;
        }
        int i = 0;
        int j = v.size() - 1;
        while (i <= j) {
            if (v[j] % 2 == 0 && v[i] % 2 == 1) {
                swap(v[j], v[i]);
                j--;
                i++;
            } else if (v[j] % 2 == 0 && v[i] % 2 == 0) {
                i++;
            } else if (v[j] % 2 == 1 && v[i] % 2 == 0) {
                j--;
            } else {
                j--;
            }
        }
        return v;
    }
};