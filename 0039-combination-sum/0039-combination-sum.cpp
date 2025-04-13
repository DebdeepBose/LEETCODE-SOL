class Solution {
public:
    //Helper Function To Generate All Combinations
    void generateAllCombinations(vector<int>& candidates, int size,
                                 vector<vector<int>>& combinations,
                                 vector<int>& tempStore, int target,
                                 int currentIndex) {

        //Base Case
        if (currentIndex == size) {

            if (target == 0) {
                combinations.push_back(tempStore);
            }

            return;
        }

        //if target is greater only then we take the same element 
        if (candidates[currentIndex] <= target) {
            tempStore.push_back(candidates[currentIndex]);
            generateAllCombinations(candidates, size, combinations, tempStore, target - candidates[currentIndex], currentIndex);
            tempStore.pop_back();
        }

        //Else we move on to the next index
        generateAllCombinations(candidates, size, combinations, tempStore, target, currentIndex + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        // Initialize to store all combinations
        vector<vector<int>> combinations;

        // A temporary array to store valid combinations
        vector<int> tempStore;

        // Size of the list
        int size = candidates.size();

        // Function call to generate all combinations
        generateAllCombinations(candidates, size, combinations, tempStore,
                                target, 0);

        return combinations;
    }
};