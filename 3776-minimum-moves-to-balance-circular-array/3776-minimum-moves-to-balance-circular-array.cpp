class Solution {
public:
    long long minMoves(vector<int>& v) {
        int n = v.size();
        bool ifnoNeg = true;
        long long posSum = 0;
        long long neg = 0;
        int negIdx = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] > 0) {
                posSum += v[i];
            }
            if (v[i] < 0) {
                neg = v[i];
                negIdx = i;
                ifnoNeg = false;
            }
        }

        if (ifnoNeg) {
            return 0;
        }
        if (neg + posSum < 0) {
            return -1;
        }
        if (n == 2) {
            return abs(neg);
        }

        int i = (negIdx - 1 + n) % n;
        int j = (negIdx + 1) % n;

        long long bal = 0;

        while (neg < 0) {
            int distL = min(abs(i - negIdx), n - abs(i - negIdx));
            int distR = min(abs(j - negIdx), n - abs(j - negIdx));

            if (v[i] > 0) {
                long long take = min((long long)v[i], -neg);
                bal += take * distL;
                neg += take;
            }

            if (neg >= 0) {
                break;
            }

            if (v[j] > 0) {
                long long take = min((long long)v[j], -neg);
                bal += take * distR;
                neg += take;
            }

            i = (i - 1 + n) % n;
            j = (j + 1) % n;
        }

        return bal;
    }
};
