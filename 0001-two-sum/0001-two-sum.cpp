class Solution {
public:
    vector<int> CheckForValidPair(vector<int>& v,unordered_map<int, int>& numIndex, int target) {

        // Run a for loop to search for the valid pair
        for (int i = 0; i < v.size(); i++) {

            // Intialize a variable to store the required value
            int complement = target - v[i];

            // Check if map contains the complement value , if it does then return
            if (numIndex.find(complement) != numIndex.end() && numIndex[complement] != i) {
                return {numIndex[complement], i};
            }

            // If the map doesnt have the complement then populate the map with the index
            numIndex[v[i]] = i;
        }

        // If no such pairs are found return empty
        return {};
    }

    vector<int> twoSum(vector<int>& v, int target) {
        // Map to store the Indexes
        unordered_map<int, int> numIndex;

        // Function Call To Check for valid pair that add up to the target
        vector<int> result = CheckForValidPair(v, numIndex, target);

        return result; // Return the result
    }
};
