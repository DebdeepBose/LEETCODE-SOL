class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> v;
        int n = s.size();

        for (int i = 0; i + k <= n; i += k) {
            v.push_back(s.substr(i, k));
        }

        if (n % k != 0) {
            string last = s.substr(n - n % k);
            while (last.size() < k) {
                last += fill;  
            }
            v.push_back(last);
        }

        return v;
    }
};
