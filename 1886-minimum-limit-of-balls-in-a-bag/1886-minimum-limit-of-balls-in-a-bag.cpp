class Solution {
public:
    int minimumSize(vector<int>& v, int maxi) {
        int low = 1;
        int high = *max_element(v.begin(), v.end());
        int ans = high;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int o = 0;
            for (auto e : v) {
                o += (e - 1) / mid;
                if (o > maxi)
                    break;
            }
            if (o <= maxi) {
                ans = mid;
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
