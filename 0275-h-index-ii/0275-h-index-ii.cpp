class Solution {
public:
    int hIndex(vector<int>& v) {
        int n = v.size();

        int low = 0;
        int high = n - 1;
        int hIndex = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int numsUntilEnd = n - mid;
            if (v[mid] >= numsUntilEnd) {
                hIndex = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return hIndex != -1 ? n - hIndex : 0;
    }
};