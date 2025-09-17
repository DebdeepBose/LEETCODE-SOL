class Solution {
public:
    bool is_prime(int num) {
        if (num < 2 || num % 2 == 0) {
            return num == 2;
        }
        for (int i = 3; i * 1LL * i <= num; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    int primePalindrome(int N) {
        if (8 <= N && N <= 11) {
            return 11;
        }
        for (int x = 1; x < 100000; x++) {
            string s = to_string(x);
            string r(s.rbegin(), s.rend());
            int y = stoi(s + r.substr(1));
            if (y >= N && is_prime(y)) {
                return y;
            }
        }
        return -1;
    }
};
