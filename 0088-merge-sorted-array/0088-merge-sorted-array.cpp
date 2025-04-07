class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int totalLength = n + m;
        int gap = ceil((double)totalLength / 2);

        while (gap > 0) {
            int left = 0;
            int right = gap;

            while (right < totalLength) {
                // Case 1: Both pointers in nums1
                if (left < n && right < n) {
                    if (nums1[left] > nums1[right]) {
                        swap(nums1[left], nums1[right]);
                    }
                }
                // Case 2: Left in nums1, right in nums2
                else if (left < n && right >= n) {
                    if (nums1[left] > nums2[right - n]) {
                        swap(nums1[left], nums2[right - n]);
                    }
                }
                // Case 3: Both pointers in nums2
                else if (left >= n) {
                    if (nums2[left - n] > nums2[right - n]) {
                        swap(nums2[left - n], nums2[right - n]);
                    }
                }

                left++;
                right++;
            }

            // Reduce the gap for the next iteration
            if (gap == 1) {
                break;
            }
            gap = ceil((double)gap / 2);
        }

        // Copy the merged and sorted nums2 into nums1's remaining slots
        for (int i = 0; i < m; i++) {
            nums1[n + i] = nums2[i];
        }
    }
};
