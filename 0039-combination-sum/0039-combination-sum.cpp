class Solution {
public:
    void findAllCombinations(vector<int>& candidates, int target,
                             vector<vector<int>>& combinations,
                             vector<int>& tempCombos, int index) {
        /* Now listen up: we follow the same routine we subtract one element
        from target as many times as required. If we somehow reach target,
        that would mean target = 0 because we reached by subtracting right?
        Oh also whatever we are subtracting from the target we push into
        tempCombos because we need to push that into our combinations vector. So
        yeah, thats the plan. If target reaches 0 we push tempCombos into
        combinations and return nothing cuz its void.
        */
        if (target == 0) {
            combinations.push_back(tempCombos);
            return;
        }
        /* NOW NOW NOW, what if the target remaining is 4 and we subtracted 5?
           In that case target = -1. So whats the problem?
           The problem is since all the input array elements are positive,
           our target is never going to reach 0 if its already negative,
           not to mention index might also go negative trying to search for a
           valid value. So we keep a check: if index < 0 or target < 0 we
           return.
         */
        if (index < 0 || target < 0) {
            return;
        }
        // Now comes the part of take/skip, its pretty standard

        tempCombos.push_back(candidates[index]);
        findAllCombinations(candidates, target - candidates[index],
                            combinations, tempCombos, index);
        // We did not go index-1 here because we can take the same element
        // multiple times

        tempCombos.pop_back();
        findAllCombinations(candidates, target, combinations, tempCombos,
                            index - 1); // WEEE SKIP

        // Draw the recursive tree if you don’t understand yeah, its a
        // note to myself I swear Im not schizophrenic
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // So, it kinda follows the basic pattern of take/skip so we can easily
        // apply that

        // Let’s take the required data structures and variables

        vector<vector<int>> combinations;
        vector<int> tempCombos;

        int n = candidates.size();

        // Yeah we send n-1 because we start from the back.
        // We could also take another variable i == 0 to keep track of the
        // length but it is what it is
        findAllCombinations(candidates, target, combinations, tempCombos,
                            n - 1);

        return combinations;
    }
};
