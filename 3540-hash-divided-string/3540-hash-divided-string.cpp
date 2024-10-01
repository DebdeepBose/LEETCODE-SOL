class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.length();
        vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                          'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                          's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        int upto = k;
        int tmp = upto;
        int r = 0;
        int sum = 0;
        string res = "";

        while (r < n) {
            sum += s[r] - 'a';
            upto--;
            if (upto == 0) {
                res += v[sum % 26];
                sum = 0;
                upto = tmp;
            }
            r++;
        }

        return res;
    }
};
