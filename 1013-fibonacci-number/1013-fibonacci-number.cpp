class Solution {
public:
    int fib(int n) {
        //Setting the base case
        if (n <= 1) {
            return n;
        }

        //Formula known to every human being on this planet
        return fib(n - 1) + fib(n - 2);
    }
};