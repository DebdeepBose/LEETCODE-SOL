class Solution {
public:

    //Brute force btw
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        vector<int> v3;
        int i = 0, j = 0;
        while (i < v1.size() || j < v2.size()) {
            if (i < v1.size() && (j >= v2.size() || v1[i] < v2[j])) {
                v3.push_back(v1[i]);
                i++;
            } else {
                v3.push_back(v2[j]);
                j++;
            }
        }
        if (v3.size() % 2 == 0) {
            return (double)(v3[v3.size() / 2 - 1] + v3[v3.size() / 2]) / 2.0;
        } else {
            return v3[v3.size() / 2];
        }
    }
};
