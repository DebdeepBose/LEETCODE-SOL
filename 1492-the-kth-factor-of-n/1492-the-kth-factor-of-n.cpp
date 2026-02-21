class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors = {1};
        int d = 2;
        for (int i = d; i <= n / 2; i++) {
            if (n % i == 0) {
                factors.push_back(i);
            }
        }
        factors.push_back(n);
        return k <= factors.size() ? factors[k - 1] : -1;
    }
};