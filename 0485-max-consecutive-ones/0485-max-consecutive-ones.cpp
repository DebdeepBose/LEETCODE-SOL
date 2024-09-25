class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int c = 0;
        int maxlen = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 1) {
                c++;
            } else if (v[i] == 0) {
                maxlen = max(maxlen, c);
                c = 0;
            }
        }
        return max(maxlen,c);
    }
};