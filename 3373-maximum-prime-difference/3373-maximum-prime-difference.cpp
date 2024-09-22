class Solution {
public:
    bool isprime(int x) {
        if (x <= 1) {
            return false;
        } else {
            for (int i = 2; i <= sqrt(x); i++) {
                if (x % i == 0) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    int maximumPrimeDifference(vector<int>& v) {
        int n = v.size();
        int i = 0;
        int j = n - 1;
        int maxlen = 0;
        while (i < j) {
            if (isprime(v[i]) && isprime(v[j])) {
                return j - i;
            } else if (isprime(v[i]) && !isprime(v[j])) {
                j--;
            } else if (!isprime(v[i]) && isprime(v[j])) {
                i++;
            } else if (!isprime(v[i]) && !isprime(v[j])) {
                i++;
                j--;
            }
        }
        return 0;
    }
};