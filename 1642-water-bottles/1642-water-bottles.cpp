class Solution {
public:
    int numWaterBottles(int w, int n) {
        return w + (w - 1) / (n - 1);
    }
};