class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int tmp = n;
            int prod = 1;
            while (tmp > 0) {
                int rem = tmp % 10;
                if (rem == 0) {
                    prod = 0;
                    break;
                }
                prod *= rem;
                tmp /= 10;
            }
            if (prod % t == 0) {
                return n;
            }
            n++;
        }
    }
};
