class Solution {
public:
    void SieveOfEras(vector<bool> &v, int n) {
        v[0] = v[1] = false;
        for (int i = 2; i * i < n; i++) {
            if (v[i]) {
                for (int j = i * i; j < n; j += i) {
                    v[j] = false;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& v) {
        int n = v.size();
        vector<bool> isPrime(1005, true);
        SieveOfEras(isPrime, 1005);
        vector<int> vp;
        for (int i = 2; i < 1005; i++) {
            if (isPrime[i]) {
                vp.push_back(i);
            }
        }
        int prev = v[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] < prev) {
                prev = v[i];
                continue;
            }
            bool found = false;
            for (int j = 0; j < vp.size() && vp[j] < v[i]; j++) {
                if (v[i] - vp[j] < prev) {
                    prev = v[i] - vp[j];
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }
};
