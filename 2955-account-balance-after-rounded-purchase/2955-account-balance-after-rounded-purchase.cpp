class Solution {
public:
    int accountBalanceAfterPurchase(int a) {
        int ld = a % 10;
        if (ld >= 5) {
            return 100 - (a - ld + 10);
        } else if (ld > 0 && ld < 5) {
            return 100 - (a - ld);
        } else {
            return 100 - a;
        }
    }
};