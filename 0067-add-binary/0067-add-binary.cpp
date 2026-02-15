class Solution {
public:
    string addBinary(string s1, string s2) {
        string sumString = "";
        
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += (s1[i] - '0');
                i--;
            }

            if (j >= 0) {
                sum += (s2[j] - '0');
                j--;
            }

            sumString += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(sumString.begin(), sumString.end());
        return sumString;
    }
};