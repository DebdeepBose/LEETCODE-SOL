class Solution {
public:
    // Function to calculate the total jumps
    int CalculateJumps(vector<int>& v, int n, int jumps, int lastjumpindex,
                       int coverage) {

        for (int i = 0; i < n - 1; i++) { 
            
            coverage = max(coverage, i + v[i]);

            // If we've reached the end of the last jump index
            if (i == lastjumpindex) {
                jumps++;                  // Increment the jump count
                lastjumpindex = coverage; // Update last jump index

                // If we can reach or exceed the last index
                if (coverage >= n - 1) {
                    return jumps;
                }
            }
        }

        // If we exit the loop without being able to reach the last index
        return (coverage >= n - 1) ? jumps
                                   : -1; // -1 indicates failure to reach
    }

    int jump(vector<int>& v) {
        int n = v.size(); // Get the size of the array

        // No jumps if the size is just 1
        if (n <= 1) {
            return 0;
        }

        int jumps = 0;       // Keeps track of the number of jumps
        int lastjumpidx = 0; // Last jump index
        int coverage = 0;    // Coverage of the jumps

        // Call the function to calculate the total jumps
        return CalculateJumps(v, n, jumps, lastjumpidx, coverage);
    }
};
