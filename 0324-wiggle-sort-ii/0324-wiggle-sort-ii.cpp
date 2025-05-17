class Solution {
public:
    void wiggleSort(vector<int>& v) {
        int n = v.size();
        vector<int> tmp(n);
        sort(v.begin(), v.end());

        int mid = (n - 1) / 2;
        int end = n - 1;
        int j = 0;

        for (int i = mid; i >= 0; i--) {
            tmp[j] = v[i];
            j += 2;
        }

        j = 1;
        for (int i = n - 1; i > mid; i--) {
            tmp[j] = v[i];
            j += 2;
        }

        v = tmp;
    }
};
