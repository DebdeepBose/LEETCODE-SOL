class Solution {
public:
    // Function to find the number of unique k-diff pairs in the array
    int findPairs(vector<int>& v, int k) {
        unordered_map<int, int> pairFrequency; // Stores frequency of each element
        int size = v.size(); // Size of the input array

        // Count the frequency of each number in the array
        for (int i = 0; i < size; i++) {
            pairFrequency[v[i]]++;
        }

        int countPairs = 0;

        // Iterate over the frequency map to count valid pairs
        for (auto element : pairFrequency) {
            int currentNum = element.first;
            int req = currentNum + k;

            // If k == 0, then the required number is literally the same as the current number.
            // So, we're basically looking for duplicates of the same number.
            // If we find such duplicates (i.e., frequency > 1), we count it as a valid pair (x, x).
            if (k == 0) {
                if (element.second > 1) {
                    countPairs++;
                }
            } 
            // If k > 0, just check if the complementary value exists in the map
            else if (pairFrequency.find(req) != pairFrequency.end()) {
                countPairs++;
            }
        }

        return countPairs;
    }
};
