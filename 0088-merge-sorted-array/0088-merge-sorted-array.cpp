class Solution {
public:
    void merge(vector<int>& v1, int n, vector<int>& v2, int m) {
        int len = n + m;
        int gap = ceil((double)len / 2);

        while (gap > 0) {
            int left = 0;
            int right = gap;

            while (right < len) {
                // Case 1: both pointers in v1
                if (left < n && right < n) {
                    if (v1[left] > v1[right]) {
                        swap(v1[left], v1[right]);
                    }
                }
                // Case 2: left in v1, right in v2
                else if (left < n && right >= n) {
                    if (v1[left] > v2[right - n]) {
                        swap(v1[left], v2[right - n]);
                    }
                }
                // Case 3: both pointers in v2
                else if (left >= n) {
                    if (v2[left - n] > v2[right - n]) {
                        swap(v2[left - n], v2[right - n]);
                    }
                }

                left++;
                right++;
            }

            if (gap == 1) {
                break;
            }

            gap = ceil((double)gap / 2);
        }

        for (int i = 0; i < m; i++) {
            v1[n + i] = v2[i];
        }
    }
};
