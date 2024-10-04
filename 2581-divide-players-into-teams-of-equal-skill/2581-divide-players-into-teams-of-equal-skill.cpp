class Solution {
public:
    long long dividePlayers(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        int i = 0;
        int j = n - 1;
        int prevsum = 0;
        vector<int> s;
        vector<long long> p;
        while (i < j) {
            int sum = v[i] + v[j];
            long long prod = v[i] * v[j];
            s.push_back(sum);
            p.push_back(prod);
            i++;
            j--;
        }
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] != s[i + 1]) {
                return -1;
            }
        }
        long long psum = 0;
        for (auto e : p) {
            psum += e;
        }
        return psum;
    }
};