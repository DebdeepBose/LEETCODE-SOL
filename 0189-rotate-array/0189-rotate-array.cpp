class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        //Storing the length of the array
        int array_length = nums.size();

        //Computing so it prevents errors incase k exceeds array length
        int resized_k = k % array_length;

        //Using simple reversal algorithms
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() + resized_k, nums.end());
        reverse(nums.begin(), nums.begin() + resized_k);

        //No return since its void
    }
};