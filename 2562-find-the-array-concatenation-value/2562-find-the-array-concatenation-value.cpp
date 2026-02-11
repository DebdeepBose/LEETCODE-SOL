class Solution {
public:
    long long concat(int i, int j, vector<int>& v) {
        long long mul = 1;
        long long temp = v[j];

        while (temp > 0) {
            mul *= 10;
            temp /= 10;
        }

        return v[i] * mul + v[j];
    }
    long long findTheArrayConcVal(vector<int>& v) {
        int n = v.size();
        if (n < 2) {
            return v[0];
        }
        int l = 1;
        int r = n - 2;
        long long prev = concat(0, n - 1, v);
        long long cur = 0;
        while (l <= r) {
            if (l == r) {
                prev += v[l];
                break;
            }
            cur = concat(l++, r--, v);
            prev = cur + prev;
        }
        return prev;
    }
};