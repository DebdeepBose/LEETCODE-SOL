class Solution {
public:
    int compress(vector<char>& v) {
        int i = 0;
        int j = 1;
        int n = v.size();
        int c = 1;

        while (j <= n) {
            if (j == n || v[j] != v[j - 1]) {
                v[i] = v[j - 1];
                i++;
                if (c >= 2) {
                    for (char ch : to_string(c)) {
                        v[i++] = ch;
                    }
                }
                c = 0;
            }
            c++;
            j++;
        }
        return i;
    }
};