class Solution {
public:
    double myPow(double x, int n) {
        // Base case: any number to the power 0 is 1
        if (n == 0) {
            return 1;
        }

        // If the exponent is negative, take reciprocal and convert n to positive
        if (n < 0) {
            // Use long to safely handle INT_MIN (since abs(INT_MIN) overflows int)
            long long exp = abs((long long)n); 
            x = 1 / x;

            // Recursively compute the power with positive exponent
            if (exp % 2 == 0) {
                return myPow(x * x, exp / 2);
            } else {
                return x * myPow(x * x, exp / 2);
            }
        }

        // If exponent is positive and even: use divide-and-conquer (x^n = (x^2)^(n/2))
        if (n % 2 == 0) {
            return myPow(x * x, n / 2);
        } 
        // If exponent is positive and odd: split one x, and reduce problem
        else {
            return x * myPow(x * x, n / 2);
        }
    }
};
