class Solution {
public:
    bool checkDivisibility(int n) {
        int m = n;
        int sum = 0;
        int pro = 1;
        while (m != 0) {
            int d = m % 10;
            sum += d;
            pro *= d;
            m /= 10;
        }
        return n % (sum + pro) == 0;
    }
};