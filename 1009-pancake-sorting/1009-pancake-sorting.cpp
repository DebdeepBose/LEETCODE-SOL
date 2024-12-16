class Solution {
public:
    vector<int> pancakeSort(vector<int>& v) {
        vector<int> res;
        int n = v.size();

        for (int x = n; x > 1; x--) {
            int i = 0;
            while (v[i] != x) {
                i++;
            }

            if (i + 1 != x) {
                reverse(v.begin(), v.begin() + i + 1);
                res.push_back(i + 1);
                reverse(v.begin(), v.begin() + x);
                res.push_back(x);
            }
        }
        return res;
    }
};