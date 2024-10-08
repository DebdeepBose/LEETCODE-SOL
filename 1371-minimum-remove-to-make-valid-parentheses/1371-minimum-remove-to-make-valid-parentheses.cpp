class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        int c = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                c++;
            } else if (s[i] == ')') {
                if (c > 0) {
                    c--;
                } else {
                    s[i] = '@';
                }
            }
        }

        c = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') {
                c++;
            } else if (s[i] == '(') {
                if (c > 0) {
                    c--;
                } else {
                    s[i] = '@';
                }
            }
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '@') {
                ans += s[i];
            }
        }
        
        return ans;
    }
};
