class Solution {
public:
    vector<int> getConcatenation(vector<int>& v) {
        int n = v.size();
        for (int i = 0; i < n; i++) {
            v.push_back(v[i]);
        }
        return v;
    }
};