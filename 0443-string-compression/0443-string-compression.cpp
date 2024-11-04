class Solution {
public:
    int compress(vector<char>& v) {
        int n = v.size();
        if (n == 1) {
            return 1;
        }
        vector<char> tmp;
        int c = 1;
        for (int i = 0; i < n; i++) {
            if (i + 1 == n || v[i] != v[i + 1]) {
                tmp.push_back(v[i]);
                if (c > 1 && c <= 9) {
                    tmp.push_back(c + '0');
                } else if (c > 9) {
                    int x = c;
                    vector<char> tmp2;
                    while (x > 0) {
                        int rem = x % 10;
                        tmp2.push_back(rem + '0');
                        x /= 10;
                    }
                    reverse(tmp2.begin(), tmp2.end());
                    for (auto e : tmp2) {
                        tmp.push_back(e);
                    }
                }
                c = 1;
            } else {
                c++;
            }
        }

        v.assign(tmp.begin(), tmp.end());
        return v.size();
    }
};
