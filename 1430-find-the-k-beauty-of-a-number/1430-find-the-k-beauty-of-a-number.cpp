class Solution {
public:
    int divisorSubstrings(int e, int k) {
        string s = to_string(e);
        int l = 0;
        int r = 0;
        int n = s.length();
        int c = 0;
        string sub = "";
        while (r < n) {
            sub += s[r];
            while (sub.size() > k) {
                l++;
                sub = s.substr(l, r - l + 1);
            }
            if (sub.size() == k) {
                int tmp = stoi(sub);
                if (tmp != 0 && e % tmp == 0) {
                    c++;
                }
            }
            r++;
        }

        return c;
    }
};
