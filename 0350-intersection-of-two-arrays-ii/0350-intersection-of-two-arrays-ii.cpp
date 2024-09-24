class Solution {
public:
    vector<int> intersect(vector<int>& u, vector<int>& v) {
        sort(u.begin(), u.end());
        sort(v.begin(), v.end());
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (i < u.size() && j < v.size()) {
            if (u[i] == v[j]) {
                ans.push_back(u[i]);
                i++;
                j++;
            } else if (u[i] < v[j]) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};