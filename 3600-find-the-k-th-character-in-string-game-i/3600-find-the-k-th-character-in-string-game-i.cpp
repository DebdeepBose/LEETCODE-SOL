class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while (s.size() < k) {
            string tmp = "";
            for (char c : s) {
                tmp += c + 1;
            }
            s += tmp;
        }

        return s[k - 1];
    }
};