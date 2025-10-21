class Solution {
public:
    string smallestString(string s) {

        int n = s.size();
        int i = 0;

        while (i < n && s[i] == 'a') {
            i++;
        }

        if (i == n) {
            s[i - 1] = 'z';
        }

        while (i < n && s[i] != 'a') {
            s[i]--;
            i++;
        }
        return s;
    }
};
