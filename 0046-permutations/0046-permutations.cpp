class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        /* Yeah so i looked at the swap solution, didnt understand shi,
        so imma use a Bool "Used" vector to keep track of the numbers i use*/

        int n = nums.size();

        vector<vector<int>> permutations;

        vector<int> temporaryPermutation;

        // Imma initalize with false, cuz nothin has been used
        vector<bool> trackUse(n, false);

        findAllPermutations(nums, n, permutations, temporaryPermutation,
                            trackUse);

        return permutations;
    }

    void findAllPermutations(vector<int>& nums, int n,
                             vector<vector<int>>& permutations,
                             vector<int>& temporaryPermutation,
                             vector<bool>& trackUse) {
        /*Weird ahh format but anyways the base case is simply a size check if
          tempPerm is == n, we store and return*/

        if (temporaryPermutation.size() == n) {
            permutations.push_back(temporaryPermutation);
            return;
        }

        /*Now we lOOOp, reason? look we have to reuse an element in the SAME
        position so we gotta loop this*/
        for (int i = 0; i < n; i++) {
            /*Now we are taking an elemnet right? so the next time we dont take
             * it in the same position so we gotta use ou bool vector*/
            if (!trackUse[i]) {
                temporaryPermutation.push_back(nums[i]);

                // Gotta mark it as used
                trackUse[i] = true;

                // baktrak
                findAllPermutations(nums, n, permutations, temporaryPermutation,
                                    trackUse);

                // Undo choice, oh btw we gotta undo our bool vector aswell
                temporaryPermutation.pop_back();

                trackUse[i] = false;
            }
        }
    }
};