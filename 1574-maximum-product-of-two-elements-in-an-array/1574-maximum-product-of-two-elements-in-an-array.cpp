class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /* Wow another heap question that could be done by sorting or like idk
           find max and 2nd max lol*/

        int firstMaximum = INT_MIN;
        int secondMaximum = INT_MIN;

        int n = nums.size();

        // Bind Mlowing Logic Ahead, i shud go to ICPC XD
        for (int i = 0; i < n; i++) {
            if (nums[i] >= firstMaximum) {
                secondMaximum = firstMaximum;
                firstMaximum = nums[i];
            } else if (nums[i] > secondMaximum) {
                secondMaximum = nums[i];
            }
        }

        firstMaximum--;
        secondMaximum--;

        return firstMaximum * secondMaximum;
    }
};