class Solution {
public:
    int maxOperations(string s) {
        int c = 0;
        int inHand = 0;
        int n = s.size();
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '1') {
                inHand++;
                if (s[i + 1] == '0') {
                    c += inHand;
                }
            }
        }
        return c;
    }
};