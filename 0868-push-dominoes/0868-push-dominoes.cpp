class Solution {
public:
    string pushDominoes(string s) {
        s = 'L' + s + 'R';
        string res = "";
        int n = s.size();
        for (int i = 0, j = 1; j < n; j++) {
            if (s[j] == '.') {
                continue;
            }
            int middle = j - i - 1;
            if (i > 0)
                res += s[i];
            if (s[i] == s[j])
                res += string(middle, s[i]);
            else if (s[i] == 'L' && s[j] == 'R')
                res += string(middle, '.');
            else
                res += string(middle / 2, 'R') + string(middle % 2, '.') +
                       string(middle / 2, 'L');
            i = j;
        }
        return res;
    }
};