class Solution {
public:
    int secondHighest(string s) {
        int l = -1;
        int sl = -1;
        for (auto e : s) {
            if (isdigit(e)) {
                if (e - '0' > l) {
                    sl = l;
                    l = e - '0';
                }
                if (e - '0' > sl && l != e - '0') {
                    sl = e - '0';
                }
            }
        }
        return sl == -1 ? -1 : sl;
    }
};