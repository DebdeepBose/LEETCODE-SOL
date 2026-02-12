class Solution {
public:
    int strStr(string s, string r) {

        auto search = s.find(r);

        if (search != string::npos) {
            return search;
        }
        return -1;
    }
};