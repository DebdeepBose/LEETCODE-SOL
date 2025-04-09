class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int totalLength = n + m;

        // Initial gap is ceil of totalLength / 2.
        // We use (double) to ensure we get the ceiling of a decimal (e.g., ceil(5/2) = 3 instead of 2)
        int gap = ceil((double)totalLength / 2);

        while (gap > 0) {
            int left = 0;
            int right = gap;

            // Traverse elements with 'gap' distance between them
            while (right < totalLength) {

                // Case 1: Both pointers are in nums1
                if (left < n && right < n) {
                    if (nums1[left] > nums1[right]) {
                        swap(nums1[left], nums1[right]);
                    }
                }
                // Case 2: Left in nums1, Right in nums2
                else if (left < n && right >= n) {
                    if (nums1[left] > nums2[right - n]) {
                        swap(nums1[left], nums2[right - n]);
                    }
                }
                // Case 3: Both pointers are in nums2
                else if (left >= n) {
                    if (nums2[left - n] > nums2[right - n]) {
                        swap(nums2[left - n], nums2[right - n]);
                    }
                }

                left++;
                right++;
            }

            // If gap becomes 1, the next gap should be 0 (loop ends), so we break before updating.
            if (gap == 1) {
                break;
            }

            // Update the gap to next reduced value
            gap = ceil((double)gap / 2);
        }

        // After fully sorting with the gap method, copy nums2's elements into nums1
        for (int i = 0; i < m; i++) {
            nums1[n + i] = nums2[i];
        }
    }
};
