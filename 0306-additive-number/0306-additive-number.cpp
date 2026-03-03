class Solution {
public:
    bool isAdditiveNumber(string s) {
        int n = s.size();

        for (int i = 1; i <= n / 2; i++) {
            for (int j = 1; j <= (n - i) / 2; j++) {
                if (check(s.substr(0, i), s.substr(i, j), s.substr(i + j))) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool check(string s1, string s2, string s) {
        if ((s1.size() > 1 && s1[0] == '0') ||
            (s2.size() > 1 && s2[0] == '0')) {
            return false;
        }

        string sum = add(s1, s2);

        if (s == sum) {
            return true;
        }

        if (s.size() <= sum.size() || s.substr(0, sum.size()) != sum) {
            return false;
        }

        return check(s2, sum, s.substr(sum.size()));
    }

    string add(string a, string b) {
        string res;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            res.push_back(char(sum % 10 + '0'));
            carry = sum / 10;
        }

        if (carry) {
            res.push_back(char(carry + '0'));
        }

        reverse(res.begin(), res.end());
        return res;
    }
};