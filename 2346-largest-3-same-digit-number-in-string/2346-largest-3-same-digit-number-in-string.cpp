class Solution {
public:
    string largestGoodInteger(string s) {
        string ans = "";
        char maxi = '0';
        bool flag = false;
        for (int i = 0; i < s.size() - 2; i++) {
            if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
                if (s[i] >= maxi) {
                    maxi = s[i];
                    flag = true;
                }
            }
        }
        if (flag) {
            ans = string(3, maxi);
        }
        return ans;
    }
};