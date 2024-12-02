class Solution {
public:
    int isPrefixOfWord(string s, string r) {
        istringstream stream(s);
        string ans;
        int i = 1;
        while (stream >> ans) {
            if (ans.find(r) == 0) {
                return i;
            }
            i++;
        }

        return -1;
    }
};