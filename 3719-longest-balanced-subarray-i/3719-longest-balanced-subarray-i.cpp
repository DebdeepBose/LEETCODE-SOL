class Solution {
public:
    int longestBalanced(vector<int>& v) {
        int maxlen = 0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            unordered_set<int> e,o;
            for (int j = i; j < n; j++) {
                if (v[j] % 2 == 0) {
                    e.insert(v[j]);
                } else {
                    o.insert(v[j]);
                }
                if (o.size() == e.size()) {
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }
        return maxlen;
    }
};