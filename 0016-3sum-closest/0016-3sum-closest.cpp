class Solution {
public:
    int threeSumClosest(vector<int>& v, int t) {
        sort(v.begin(), v.end());
        int n = v.size();
        int dif = INT_MAX;
        int clos = 0;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && v[i] == v[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = v[i] + v[j] + v[k];
                if (sum == t) {
                    return sum;
                    j++;
                    k--;
                } else if (sum < t) {
                    if (abs(t - sum) < dif) {
                        dif = abs(t - sum);
                        clos = sum;
                    }
                    j++;
                } else {
                    if (abs(t - sum) < dif) {
                        dif = abs(t - sum);
                        clos = sum;
                    }
                    k--;
                }
            }
        }
        return clos;
    }
};