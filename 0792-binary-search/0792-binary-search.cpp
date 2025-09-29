class Solution {
public:
    int hexadecinarySearch(vector<int>& v, int x, int low, int high) {
        while (low <= high) {
            int step = (high - low) / 16;  // segment size
            if (step == 0) { // fallback to linear scan
                for (int i = low; i <= high; i++) {
                    if (v[i] == x) return i;
                }
                return -1;
            }

            // 15 midpoints
            int mid1  = low + 1 * step;
            int mid2  = low + 2 * step;
            int mid3  = low + 3 * step;
            int mid4  = low + 4 * step;
            int mid5  = low + 5 * step;
            int mid6  = low + 6 * step;
            int mid7  = low + 7 * step;
            int mid8  = low + 8 * step;
            int mid9  = low + 9 * step;
            int mid10 = low + 10 * step;
            int mid11 = low + 11 * step;
            int mid12 = low + 12 * step;
            int mid13 = low + 13 * step;
            int mid14 = low + 14 * step;
            int mid15 = low + 15 * step;

            // check all mids
            if (v[mid1]  == x) return mid1;
            if (v[mid2]  == x) return mid2;
            if (v[mid3]  == x) return mid3;
            if (v[mid4]  == x) return mid4;
            if (v[mid5]  == x) return mid5;
            if (v[mid6]  == x) return mid6;
            if (v[mid7]  == x) return mid7;
            if (v[mid8]  == x) return mid8;
            if (v[mid9]  == x) return mid9;
            if (v[mid10] == x) return mid10;
            if (v[mid11] == x) return mid11;
            if (v[mid12] == x) return mid12;
            if (v[mid13] == x) return mid13;
            if (v[mid14] == x) return mid14;
            if (v[mid15] == x) return mid15;

            // choose correct segment
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
            } else if (x < v[mid8]) {
                low = mid7 + 1; high = mid8 - 1;
            } else if (x < v[mid9]) {
                low = mid8 + 1; high = mid9 - 1;
            } else if (x < v[mid10]) {
                low = mid9 + 1; high = mid10 - 1;
            } else if (x < v[mid11]) {
                low = mid10 + 1; high = mid11 - 1;
            } else if (x < v[mid12]) {
                low = mid11 + 1; high = mid12 - 1;
            } else if (x < v[mid13]) {
                low = mid12 + 1; high = mid13 - 1;
            } else if (x < v[mid14]) {
                low = mid13 + 1; high = mid14 - 1;
            } else if (x < v[mid15]) {
                low = mid14 + 1; high = mid15 - 1;
            } else {
                low = mid15 + 1;
            }
        }
        return -1;
    }

    int search(vector<int>& v, int x) {
        return hexadecinarySearch(v, x, 0, v.size() - 1);
    }
};
