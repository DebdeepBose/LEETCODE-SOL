class Solution {
public:
    string reverseWords(string s) {
    
        int firstWordVC = 0;
        int i = 0;
        int n = s.size();

 
        for (i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                firstWordVC++;
            }
            if (isspace(s[i])) {
                i++; 
                break;
            }
        }

        int wordVC = 0;
        int k = i; 

        for (int j = i; j < n; j++) {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
                wordVC++;
            }
            if (isspace(s[j]) || j == n - 1) {
                if (wordVC == firstWordVC) {
                    if (j == n - 1) {
                        reverse(s.begin() + k, s.begin() + j + 1);
                    } else {
                        reverse(s.begin() + k, s.begin() + j);
                    }
                }
                wordVC = 0;
                k = j + 1; 
            }
        }

        return s;
    }
};
