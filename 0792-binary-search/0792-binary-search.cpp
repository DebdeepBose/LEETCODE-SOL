class Solution {
public:
    int octonarySearch(vector<int>& v, int x, int low, int high) {
        while (low <= high) {
            int step = (high - low) / 8;  
            int mid1 = low + step;
            int mid2 = low + 2 * step;
            int mid3 = low + 3 * step;
            int mid4 = low + 4 * step;
            int mid5 = low + 5 * step;
            int mid6 = low + 6 * step;
            int mid7 = low + 7 * step;

            if (v[mid1] == x) return mid1;
            if (v[mid2] == x) return mid2;
            if (v[mid3] == x) return mid3;
            if (v[mid4] == x) return mid4;
            if (v[mid5] == x) return mid5;
            if (v[mid6] == x) return mid6;
            if (v[mid7] == x) return mid7;

            if (x < v[mid1]) {
                high = mid1 - 1;
            } else if (x < v[mid2]) {
                low = mid1 + 1; high = mid2 - 1;
            } else if (x < v[mid3]) {
                low = mid2 + 1; high = mid3 - 1;
            } else if (x < v[mid4]) {
                low = mid3 + 1; high = mid4 - 1;
            } else if (x < v[mid5]) {
                low = mid4 + 1; high = mid5 - 1;
            } else if (x < v[mid6]) {
                low = mid5 + 1; high = mid6 - 1;
            } else if (x < v[mid7]) {
                low = mid6 + 1; high = mid7 - 1;
            } else {
                low = mid7 + 1;
            }
        }
        return -1;
    }

    int search(vector<int>& v, int x) {
        return octonarySearch(v, x, 0, v.size() - 1);
    }
};
