class Solution {
public:
    int countOperations(int num1, int num2) {

        int c = 0;
        countOps(num1, num2, c);

        return c;
    }
    void countOps(int n1, int n2, int& c) {
        if (!n1 || !n2) {
            return;
        }

        if (n1 >= n2) {
            countOps(n1 - n2, n2, ++c);
        } else {
            countOps(n1, n2 - n1, ++c);
        }
    }
};