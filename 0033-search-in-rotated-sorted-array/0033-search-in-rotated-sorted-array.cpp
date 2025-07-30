class Solution {
public:
    int search(vector<int>& v, int k) {
        int n = v.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (v[mid] == k) {
                return mid;
            } else if (v[mid] > v[high]) {
                if (v[low] <= k && k <= v[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (k >= v[mid] && k <= v[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};