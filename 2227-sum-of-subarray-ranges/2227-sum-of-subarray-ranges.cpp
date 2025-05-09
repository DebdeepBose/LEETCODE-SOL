class Solution {
public:
    long long subArrayRanges(vector<int>& v) {
        int n = v.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int lar = v[i], sma = v[i];
            for (int j = i; j < n; j++) {
                lar = max(lar, v[j]);
                sma = min(sma, v[j]);
                sum += lar - sma;
            }
        }
        return sum;
    }
};