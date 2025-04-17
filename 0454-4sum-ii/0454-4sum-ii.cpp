class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {

        // Stores the sum of all combiantions of 1st and 2nd array
        unordered_map<int, int> LeftDualArraySum;

        // Here we compute and store the sum of first & second array in the map
        for (auto numInNums1 : nums1) {
            for (auto numInNums2 : nums2) {
                int dualSum = numInNums1 + numInNums2;
                LeftDualArraySum[dualSum]++;
            }
        }

        // Initiate tuple count as 0
        int tupleCount = 0;

        // Here we compute the sum of third & fourth array and then
        // subtract it from 0 , if we find that in our map we add the count to
        // our tuple count
        for (auto numInNums3 : nums3) {
            for (auto numInNums4 : nums4) {
                int dualSum2 = numInNums3 + numInNums4;
                if (LeftDualArraySum.find(-dualSum2) !=
                    LeftDualArraySum.end()) {
                    tupleCount += LeftDualArraySum[-dualSum2];
                }
            }
        }

        return tupleCount;
    }
};