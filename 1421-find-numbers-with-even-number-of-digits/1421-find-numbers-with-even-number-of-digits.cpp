class Solution {
public:
    int countDigits(int x) {
        if (x == 0) {
            return 1;
        }
        int digitCount = (int)log10(x) + 1;
        return digitCount;
    }
    int findNumbers(vector<int>& v) {
        int n = v.size();
        int evenDigit = 0;
        for (int i = 0; i < n; i++) {
            int totalDigits = countDigits(v[i]);
            if ((totalDigits & 1) == 0) {
                evenDigit++;
            }
        }
        return evenDigit;
    }
};