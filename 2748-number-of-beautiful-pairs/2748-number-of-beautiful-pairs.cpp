class Solution {
public:
    bool isCoprime(int a, int b) { return __gcd(a, b) == 1; }

    int countBeautifulPairs(vector<int>& v) {
        int n = v.size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string s1 = to_string(v[i]);
                string s2 = to_string(v[j]);
                int d1 = s1[0] - '0';
                int d2 = s2.back() - '0';
                if (isCoprime(d1, d2)) {
                    c++;
                }
            }
        }
        return c;
    }
};