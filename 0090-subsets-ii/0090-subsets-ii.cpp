class Solution {
public:
    void findAllSubsets(vector<int>& nums, int index,
                        vector<vector<int>>& allSubsets,
                        vector<int>& tempSubsets) {
        // Pretty similar, we go < 0 cuz we need to include nums[0]
        if (index < 0) {
            allSubsets.push_back(tempSubsets);
            return;
        }

        tempSubsets.push_back(nums[index]);
        findAllSubsets(nums, index - 1, allSubsets, tempSubsets);
        tempSubsets.pop_back();

        // Sameduplicate removal trick
        int prevNum = nums[index];
        while (index > 0 && prevNum == nums[index - 1]) {
            index--;
        }
        findAllSubsets(nums, index - 1, allSubsets, tempSubsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /* This is like super similar to combination sum-2 structure wise
        /like eeriely similar, anyways we sort cuz u know we gotta eliminate
        them duplicates and if we dont wanna use set we gotta pull up with the
        sort + while approach*/
        sort(nums.begin(), nums.end());

        // Basic initialization
        int n = nums.size();

        vector<vector<int>> allSubsets;
        vector<int> tempSubsets;

        findAllSubsets(nums, n - 1, allSubsets, tempSubsets);

        return allSubsets;
    }
};