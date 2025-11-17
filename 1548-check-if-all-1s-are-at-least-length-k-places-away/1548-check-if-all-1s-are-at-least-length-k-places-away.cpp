class Solution {
public:
    bool kLengthApart(vector<int>& v, int k) {
        int n = v.size();
        int i = 0;

        while (i < n && v[i] != 1) {
            i++;
        }

        if (i == n) {
            return true;
        }

        int j = i + 1;

        while (j < n) {

            while (j < n && v[j] != 1) {
                j++;
            }

            if (j == n) {
                return true;
            }

            if (j - i - 1 < k) {
                return false;
            }

            i = j;
            j = i + 1;
        }

        return true;
    }
};
