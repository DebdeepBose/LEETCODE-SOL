class Solution {
public:
    int totalMoney(int n) {
        int sc = 0;
        int moni = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 7 == 0) {
                moni += 7 + sc;
                sc++;
                continue;
            }
            moni += (sc + (i % 7));
        }
        return moni;
    }
};