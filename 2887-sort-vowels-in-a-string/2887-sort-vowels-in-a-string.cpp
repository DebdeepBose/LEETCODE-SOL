class Solution {
public:
    string sortVowels(string s) {
        string vowelStore = "";
        for (char& c : s) {
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
                c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowelStore += c;
                c = '*';
            }
        }
        sort(vowelStore.begin(), vowelStore.end());
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                s[i] = vowelStore[j];
                j++;
            }
        }
        return s;
    }
};