class Solution {
public:
    bool isPowerOfTwo(int n) {
        //Base case cuz like after multiple division if its 1, its a power of 2
        if (n == 1) {
            return true;
        }

        //Some edge case
        if (n % 2 == 1 || n == 0) {
            return false;
        }   

        //Recursive call
        return isPowerOfTwo(n / 2);
    }
};