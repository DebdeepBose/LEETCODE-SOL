class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        //Storing Size Of The Array
        int size = nums.size();

        //If previous element is not equal then its unique & so assign
        //it to 'j'
        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] != nums[i]) {
                nums[j] = nums[i];
                j++;
            }
        }

        //Return elements upto 'j'
        return j;
    }
};