class Solution {
public:
    int minOperations(string s) {
        int e = 0;
        int o = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] % 2 != i % 2) {
                e++;
            }
            if (s[i] % 2 == i % 2) {
                o++;
            }
        }
        return min(e, o);
    }
};