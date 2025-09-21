class Solution {
public:
    void generateAllSubsets(vector<int>& nums, int n,
                            vector<vector<int>>& subsets,
                            vector<int>& tempSubset, int lengthTracker) {

        /*Aight so, lets think about our base case, basically whenever
         * lengthTracker reaches n we could just push tempSubset into our ans
         * and return nothing cuz its void*/
        if (lengthTracker == n) {
            subsets.push_back(tempSubset);
            return;
        }

        // People have different templates, this is the one i follow
        // we gonna do take/skip

        // Take, i mean push_back current one and lengthTracker moves ahead
        tempSubset.push_back(nums[lengthTracker]);
        generateAllSubsets(nums, n, subsets, tempSubset, lengthTracker + 1);

        // Not take or skip whatever, and same lentghTracker + 1
        tempSubset.pop_back();
        generateAllSubsets(nums, n, subsets, tempSubset, lengthTracker + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        /* Dont overthink recursion, following recursion is hard anyways
        maybe try to follow recrusive tree*/

        int n = nums.size();

        // Yeah we need a temporary subset
        vector<vector<int>> subsets;
        vector<int> tempSubset;

        // It will help track length/depth
        int lengthTracker = 0;

        generateAllSubsets(nums, n, subsets, tempSubset, lengthTracker);

        /*Here LC asks us to return in anyorder, in case it asked us to return
         in sorted order we would just apply sort on subsets*/
        return subsets;
    }
};