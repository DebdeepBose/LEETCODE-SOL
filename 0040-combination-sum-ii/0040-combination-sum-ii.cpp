class Solution {
public:
    void
    findAllUniqueCandidates(vector<int>& candidates,
                            vector<vector<int>>& uniqueCandidateCombinations,
                            vector<int>& temporaryCandidates, int target,
                            int index) {
        /*Yeah now so yeah um we set base case literally the same as CS1, if our
         * target becomes 0 we push temporaryCombos into our ans and we return,
         * also if target < 0 or index < 0 we return*/
        if (target == 0) {
            uniqueCandidateCombinations.push_back(temporaryCandidates);
            return;
        }
        // cuz we traversing from da bak of da array
        if (index < 0 || target < 0) {
            return;
        }

        // WE Take da element
        temporaryCandidates.push_back(candidates[index]);
        findAllUniqueCandidates(candidates, uniqueCandidateCombinations,
                                temporaryCandidates, target - candidates[index],
                                index - 1);

        // Skip
        temporaryCandidates.pop_back();
        /* And we gotta apply our breins to remove duplicates, which is like
        super easy, since we recurse at least once we know that the previous
        candidate is at index, cuz currently we are at index-1 so all we do is
        store previous candidate and run a while loop ,while index > 0 &&
        prevCandidate == candidates[index-1] aka basically if our current guy is
        same as previous guy in that case we just skip it by doing index--*/
        int previousCandidate = candidates[index];
        while (index > 0 && previousCandidate == candidates[index - 1]) {
            index--;
        }

        // Yeah here we skip fr, we dont subtract candidates[index] from target
        findAllUniqueCandidates(candidates, uniqueCandidateCombinations,
                                temporaryCandidates, target, index - 1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        /* Ok, so this is slightly tricky. Well, it's not tricky per se, you
           just have to take care of a few conditions.
         We will talk about it but first notice the question doesnt mention
         anything about sorted answer vectors, yes the description is trash. We
         unfortunately have to return those vectors in sorted order, so instead
         of sorting repeatedly during insertion time into our main answer
         vector, we can sort the input array ahead of time, so that by default
         our main answer vectors are sorted, 900IQ move right there
         */

        sort(candidates.begin(), candidates.end());

        // Basic variable and DS initialization
        vector<vector<int>> uniqueCandidateCombinations;

        vector<int> temporaryCandidates;

        int n = candidates.size();

        findAllUniqueCandidates(candidates, uniqueCandidateCombinations,
                                temporaryCandidates, target, n - 1);

        return uniqueCandidateCombinations;
    }
};