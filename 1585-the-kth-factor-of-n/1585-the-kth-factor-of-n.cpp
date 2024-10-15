class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> div;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                div.push_back(i);
            }
        }
        if (k <= div.size()) {
            return div[k - 1];
        } else {
            return -1;
        }
    }
};