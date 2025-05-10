class Solution {
public:
    long long minSum(vector<int>& v1, vector<int>& v2) {
        long long s1 = accumulate(v1.begin(), v1.end(), 0LL);
        long long s2 = accumulate(v2.begin(), v2.end(), 0LL);
        long long z1 = count(v1.begin(), v1.end(), 0);
        long long z2 = count(v2.begin(), v2.end(), 0);

        if (z1 == 0 && z2 == 0) {
            if (s1 == s2) {
                return s1;
            } else {
                return -1;
            }
        } else if (z1 == 0 && z2 != 0) {
            if (s2 + z2 <= s1) {
                return s1;
            } else {
                return -1;
            }
        } else if (z2 == 0 && z1 != 0) {
            if (s1 + z1 <= s2) {
                return s2;
            } else {
                return -1;
            }
        }
        return max(s1 + z1, s2 + z2);
    }
};