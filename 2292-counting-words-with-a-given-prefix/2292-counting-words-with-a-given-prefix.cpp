class Solution {
public:
    int prefixCount(vector<string>& v, string s) {
        int n = s.size();
        int c = 0;
        for (auto e : v) {
            if (e.substr(0, n) == s)
                c++;
        }
        return c;
    }
};