class Solution {
public:
    int waysToSplitArray(vector<int>& v) {
        long long int rs = accumulate(v.begin(), v.end(), 0LL);
        long long int ls = 0;
        long long int n = v.size();
        long long int c = 0;
        for (long long int i = 0; i < n - 1; i++) {
            rs -= v[i];
            ls += v[i];
            if (ls >= rs) {
                c++;
            }
        }
        return c;
    }
};