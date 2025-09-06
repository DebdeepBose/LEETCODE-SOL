class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        // If its empty then GG return {-1,-1}
        if (nums.empty()) {
            return {-1, -1};
        }

        // We will get them iterators
        auto lb = lower_bound(nums.begin(), nums.end(), target);
        auto ub = upper_bound(nums.begin(), nums.end(), target);

        /*Ok so the reason is, if lb points beyond the array, it means
        target is bigger than every element in the array, so there aint gonna 
        be a starting point*/
        if (lb == nums.end() || *lb != target) {
            return {-1, -1};
        }

        //Get the actual indices
        int start = lb - nums.begin();
        int end = ub - nums.begin() - 1;

        //Return them
        return {start, end};
    }
};
