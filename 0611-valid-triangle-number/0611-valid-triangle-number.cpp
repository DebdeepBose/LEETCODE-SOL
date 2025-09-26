class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        int n = nums.size();

        if (n < 3) {
            return 0;
        }

        int tripletCount = 0;

        sort(nums.begin(), nums.end());

        countTriplets(nums, n, tripletCount);

        return tripletCount;
    }

    void countTriplets(vector<int>& nums, int& n, int& tripletCount) {

        int k = n - 1;

        while (k > 1) {
            int i = 0;
            int j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    tripletCount += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
            k--;
        }
    }
};