class Solution {
public:
    int candistri(int x, vector<int>& v) {
        int shops = 0;
        for (auto e : v) {
            shops += (e + x - 1) / x;
        }
        return shops;
    }

    int minimizedMaximum(int n, vector<int>& v) {
        int low = 1;
        int high = *max_element(v.begin(), v.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            int shop = candistri(mid, v);
            if (shop <= n) {
                high = mid; 
            } else {
                low = mid + 1;
            }
        }
        return low;  
    }
};
