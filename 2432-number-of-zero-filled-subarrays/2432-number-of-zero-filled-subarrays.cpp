class Solution {
public:
    long long zeroFilledSubarray(vector<int>& v) {
        long long c = 0;
        int str = 0;
        for (auto e : v) {
            if (e == 0) {
                str++;
                c += str;
            } else {
                str = 0;
            }
        }
        return c;
    }
};