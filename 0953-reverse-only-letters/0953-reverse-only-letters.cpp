class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0;
        int n = s.size();
        int j = n - 1;
        while (i < j) {
            if(!isalpha(s[i])) {
                i++;
            }
            else if(!isalpha(s[j])){
                j--;
            } 
            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};