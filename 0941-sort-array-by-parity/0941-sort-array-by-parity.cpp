class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& v) {
        if (v.size() == 1) {
            return v;
        }
        for (int i = 0, j = 0; j < v.size(); j++)
            if (v[j] % 2 == 0) {
                swap(v[i], v[j]);
                i++;
            }
        return v;
    }
};