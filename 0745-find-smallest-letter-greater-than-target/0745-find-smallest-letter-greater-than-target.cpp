class Solution {
public:
    char nextGreatestLetter(vector<char>& v, char c) {
        int n = v.size();
        int i = upper_bound(v.begin(), v.end(), c) - v.begin();
        if (i < n) {
            return v[i];
        }
        return v[0];
    }
};