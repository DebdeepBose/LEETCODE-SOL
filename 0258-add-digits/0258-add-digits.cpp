class Solution {
public:
    int addDigits(int n) {
        while (true) {
            int sum = 0;
            while (n != 0) {
                int rem = n % 10;
                sum += rem;
                n /= 10;
            }
            string t = to_string(sum);
            if (t.length() == 1) {
                return sum;
            } else {
                n = sum;
            }
        }
        return -1;
    }
};