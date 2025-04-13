class Solution {
public:
    // Recursive helper to generate all subsets (power set)
    void generateSubsets(vector<int>& inputSet, vector<vector<int>>& allSubsets,
                         vector<int>& currentSubset, int totalElements,
                         int recursionDepth) {

        // Base case: if recursion reaches end of input
        if (recursionDepth >= totalElements) {
            allSubsets.push_back(currentSubset);
            return;
        }

        // Case 1: Exclude the current element
        generateSubsets(inputSet, allSubsets, currentSubset, totalElements, recursionDepth + 1);

        // Case 2: Include the current element
        currentSubset.push_back(inputSet[recursionDepth]);
        generateSubsets(inputSet, allSubsets, currentSubset, totalElements, recursionDepth + 1);

        // Backtrack to remove the last element before returning
        currentSubset.pop_back();
    }

    // Main driver function to initiate subset generation
    vector<vector<int>> subsets(vector<int>& inputSet) {
        vector<vector<int>> allSubsets;
        vector<int> currentSubset;
        int totalElements = inputSet.size();

        generateSubsets(inputSet, allSubsets, currentSubset, totalElements, 0);
        return allSubsets;
    }
};
