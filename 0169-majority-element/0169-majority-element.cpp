class Solution {
public:
    int majorityElement(vector<int>& v) {

        int n = v.size();
        int candidate = 0;
        int c = 0;

        for (int i = 0; i < n; i++) {
            if (c == 0) {
                candidate = v[i];
            }

            if (v[i] == candidate) {
                c++;
            } else {
                c--;
            }
        }

        return candidate;
    }
};