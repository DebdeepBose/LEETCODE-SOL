class Solution {
public:
    int removeElement(vector<int>& v, int k) {
        int j = 0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            if (v[i] != k) {
                v[j] = v[i];
                j++;
            }
        }
        return j;
        
    }
};