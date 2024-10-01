class Solution {
public:
    string intToRoman(int n) {
        string m[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                            "XL", "X",  "IX", "V",  "IV", "I"};
        int v[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string r;
        for (int i = 0; i < 13; i++) {
            while (n >= v[i]) {
                r += m[i];
                n -= v[i];
            }
        }
        return r;
    }
};