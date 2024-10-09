class Solution {
public:
    vector<int> findClosestElements(vector<int>& v, int k, int x) {
        int n = v.size();
        int l = 0;
        int r = n - 1;

        while (r - l + 1 > k) {
            if (abs(v[l] - x) > abs(v[r] - x)) {
                l++;
            } else {
                r--;
            }
        }

        return vector<int>(v.begin() + l, v.begin() + r + 1);
    }
};
