class Solution {
public:
    string trimTrailingVowels(string s) {
        size_t pos = s.find_last_not_of("aeiou");
        if (pos == string::npos) {
            return "";
        }  
        return s.substr(0, pos + 1);
    }
};