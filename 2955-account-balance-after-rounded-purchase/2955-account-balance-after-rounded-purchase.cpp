class Solution {
public:
    int accountBalanceAfterPurchase(int a) {
        int ld = a % 10;
        return (ld >= 5) ? 100 - (a - ld + 10) : (ld > 0 && ld < 5) ? 100 - (a - ld) : 100 - a;

    }
};