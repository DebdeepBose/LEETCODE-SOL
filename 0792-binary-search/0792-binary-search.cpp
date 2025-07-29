class Solution {
public:
    int binarySearch(vector<int>& v, int x, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (v[mid] == x) {
                return mid;
            } else if (v[mid] > x) {
                high = mid - 1;
            } else if (v[mid] < x) {
                low = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& v, int x) {
        int n = v.size();
        return binarySearch(v, x, 0, n - 1);
    }
};