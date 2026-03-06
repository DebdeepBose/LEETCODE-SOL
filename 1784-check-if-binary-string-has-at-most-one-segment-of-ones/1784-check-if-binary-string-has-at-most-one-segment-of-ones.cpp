class Solution {
public:
    bool checkOnesSegment(string s) {
        int seg = 0;
        for (int i = 0; i < s.size(); i++) {
            while (s[i] == '0') {
                i++;
            }
            if (s[i] == '1' && seg > 0) {
                return false;
            }
            if (s[i] == '1') {
                while (s[i] == '1') {
                    i++;
                }
                seg++;
            }
            if (s[i] == '1' && seg > 0) {
                return false;
            }
        }
        return true;
    }
};