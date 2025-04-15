class Solution {
public:
    // Recursive function to generate all subsets
    void generateSubsets(vector<vector<int>>& allSubsets, vector<int>& currentSubset,
                         int totalElements, int currentIndex, vector<int>& input) {
        
        // Base case: if we've considered all elements
        if (currentIndex == totalElements) {
            allSubsets.push_back(currentSubset);  // Store the current subset
            return;
        }

        // Include the current element in the subset
        currentSubset.push_back(input[currentIndex]);
        generateSubsets(allSubsets, currentSubset, totalElements, currentIndex + 1, input);

        // Backtrack and exclude the current element
        currentSubset.pop_back();
        generateSubsets(allSubsets, currentSubset, totalElements, currentIndex + 1, input);
    }

    // Driver function to initiate recursive subset generation
    vector<vector<int>> subsets(vector<int>& input) {
        int totalElements = input.size();
        vector<vector<int>> allSubsets;
        vector<int> currentSubset;
        generateSubsets(allSubsets, currentSubset, totalElements, 0, input);
        return allSubsets;
    }
};
