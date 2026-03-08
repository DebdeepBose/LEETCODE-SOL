class Solution {
public:
    int minOperations(string s) {
        string r = s;
        sort(r.begin(), r.end());
        if (r == s) {
            return 0;
        }
        if (s[0] == r[0] || s.back() == r.back()) {
            return 1;
        }
        if (s.size() == 2) {
            return -1;
        }
        char mini = *min_element(s.begin() + 1, s.end() - 1);
        char maxi = *max_element(s.begin() + 1, s.end() - 1);

        if (s.back() < mini && s[0] > maxi) {
            return 3;
        }

        return 2;
    }
};