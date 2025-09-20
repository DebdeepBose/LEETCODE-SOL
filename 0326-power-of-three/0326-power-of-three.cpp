class Solution {
public:
    bool isPowerOfThree(int n) {
        // Base case cuz like after multiple division if its 1, its a power of 2
        if (n == 1) {
            return true;
        }

        // Some edge case
        if (n % 2 == 0) {
            return false;
        }

        //For cases where n is odd but not divisible by 3
        if (n % 3 != 0) {
            return false;
        }

        // Recursive call
        return isPowerOfThree(n / 3);
    }
};