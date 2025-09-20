class Solution {
public:
    bool isPowerOfFour(int n) {
        // Base case cuz like after multiple division if its 1, its a power of 4
        if (n == 1) {
            return true;
        }
        // Some edge case
        if (n % 2 == 1 || n % 3 == 0 || n == 0) {
            return false;
        }
        //Recursive Call
        return isPowerOfFour(n / 4);
    }
};