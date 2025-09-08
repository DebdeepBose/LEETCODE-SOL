class Solution {
public:
    int findMin(vector<int>& nums) {
        //Brute force
        return *min_element(nums.begin(),nums.end());
    }
};