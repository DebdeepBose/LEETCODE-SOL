class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int n = v.size();
        int i = 0;
        for (auto e : v) {
            if (i == 0 || i == 1 || v[i - 2] != e) {
                v[i] = e;
                i++;
            }
        }
        return i;
    }
};