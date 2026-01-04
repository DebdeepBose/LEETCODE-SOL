class Solution {
public:
    string largestEven(string s) {
        int n = s.size();
        int id = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] % 2 == 0) {
                id = i;
                break;
            }
        }
        if (id == -1) {
            return "";
        }

        return s.substr(0, id + 1);
    }
};