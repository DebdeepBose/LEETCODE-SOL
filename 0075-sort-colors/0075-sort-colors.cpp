class Solution {
public:
    void sortColors(vector<int>& v) {
        int n = v.size();
        int low = 0, mid = 0, high = n - 1;

        // We use three pointers: 
        // low - marks the boundary for 0s (leftmost region)
        // mid - traverses the array and sorts elements
        // high - marks the boundary for 2s (rightmost region)
        
        while (mid <= high) {
            if (v[mid] == 0) { 
                // If the current element is 0, swap it to the low region
                swap(v[low], v[mid]);
                low++;  // Expand the 0s region
                mid++;  // Move to the next element
            } 
            else if (v[mid] == 1) { 
                // If the current element is 1, it's already in the correct position
                mid++;  // Just move forward
            } 
            else { 
                // If the current element is 2, swap it to the high region
                swap(v[mid], v[high]);
                high--;  // Shrink the 2s region
                // Note: We do NOT increase 'mid' here because the swapped element 
                // might be 0 or 1, so we need to process it again.
            }
        }
    }
};
