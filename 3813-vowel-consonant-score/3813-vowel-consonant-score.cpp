class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0;
        int c = 0;
        for (auto e : s) {
            if (e == 'a' || e == 'e' || e == 'i' || e == 'o' || e == 'u') {
                v++;
            } else {
                if (isalpha(e)) {
                    c++;
                }
            }
        }
        if (c == 0) {
            return 0;
        }
        return floor(v / c);
    }
};