class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int n = v.size();
        if (v.back() != 9) {
            v.back()++;
            return v;
        } else {
            for (int i = n - 1; i >= 0; i--) {
                if (v[i] == 9) {
                    v[i] = 0;
                } else if (v[i] < 9) {
                    v[i]++;
                    return v;
                }
            }
        }
        v.insert(v.begin(), 1);
        return v;
    }
};