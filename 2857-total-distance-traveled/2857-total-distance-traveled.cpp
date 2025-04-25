class Solution {
public:
    int distanceTraveled(int m, int a) {
        if (a == 0) {
            return m * 10;
        }
        if (m == 0) {
            return 0;
        }
        int d = (m - 1) / 4;
        return (m + min(d, a)) * 10;
    }
};