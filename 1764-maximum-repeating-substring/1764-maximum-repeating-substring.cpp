class Solution {
public:
    int maxRepeating(string s, string w) {
        int c = 0;
        string tmp = w;
        while (s.find(tmp) != string::npos) {
            c++;
            tmp += w;
        }
        return c;
    }
};