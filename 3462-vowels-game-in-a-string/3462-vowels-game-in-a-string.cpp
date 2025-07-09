class Solution {
public:
    bool doesAliceWin(string s) {
        for (auto e : s) {
            if (e == 'a' || e == 'e' || e == 'i' || e == 'o' || e == 'u') {
                return true;
            }
        }
        return false;
    }
};