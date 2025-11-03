class Solution {
public:
    int integerReplacement(int n) { 
        return countOps((long long)n, 0); 
    }

    int countOps(long long n, int op) {
        if (n == 1) {
            return op;
        }

        if (n % 2 == 0) {
            return countOps(n / 2, op + 1);
        } else {
            int addOne = countOps(n + 1, op + 1);
            int subtractOne = countOps(n - 1, op + 1);

            if (addOne < subtractOne) {
                return addOne;
            } else {
                return subtractOne;
            }
        }
    }
};
