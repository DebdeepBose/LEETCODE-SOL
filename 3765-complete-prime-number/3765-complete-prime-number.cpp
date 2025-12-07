class Solution {
public:
    bool checkIfPrime(int x) {
        if (x < 2) {
            return false;
        }
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    bool completePrime(int num) {
        string s = to_string(num);
        int n = s.size();

        for (int i = 0; i < n; i++) {

            int left = stoi(s.substr(0, i + 1));

            int right = stoi(s.substr(n - 1 - i));

            if (!checkIfPrime(left) || !checkIfPrime(right)) {
                return false;
            }
        }

        return true;
    }
};
