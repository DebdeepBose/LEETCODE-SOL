class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        if (n == 0) {
            return true;
        }
        int k = v.size();
        for (int i = 0; i < k; i++) {
            if (v[i] == 0 && (i == 0 || v[i - 1] == 0) && (i == k - 1 || v[i + 1] == 0)) {
                v[i] = 1;
                n--;
                if (n == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};
