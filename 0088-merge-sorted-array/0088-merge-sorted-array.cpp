class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
        int i = m - 1;
        int j = 0;

        while (i >= 0 && j < n) {
            if (v1[i] > v2[j]) {
                swap(v1[i], v2[j]);
                i--;
                j++;
            } else {
                break;
            }
        }

        sort(v1.begin(), v1.begin() + m);
        sort(v2.begin(), v2.end());

        for (int i = 0; i < n; i++) {
            v1[m + i] = v2[i];
        }
    }
};
