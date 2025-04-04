class Solution {
public:
    void nextPermutation(vector<int>& v) {

        int n = v.size();
        int dip = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (v[i] < v[i + 1]) {
                dip = i;
                break;
            }
        }

        if (dip == -1) {
            reverse(v.begin(), v.end());
            return;
        } else {
            for (int i = n - 1; i >= 0; i--) {
                if (v[i] > v[dip]) {
                    swap(v[i], v[dip]); 
                    break;
                }
            }
        }

        reverse(v.begin() + dip + 1, v.end());
    }
};