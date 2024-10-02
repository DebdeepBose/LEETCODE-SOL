class Solution {
public:
    int findContentChildren(vector<int>& u, vector<int>& v) {
        sort(u.begin(), u.end());
        sort(v.begin(), v.end());
        int i = 0;
        int j = 0;
        int c = 0;
        
        while (i < u.size() && j < v.size()) {
            if (u[i] <= v[j]) {
                c++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        
        return c;
    }
};
