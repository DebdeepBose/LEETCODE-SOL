class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>> ans;
        set<vector<int>> stv;
        unordered_set<int> st;
        int n = v.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int req = 0 - (v[i] + v[j]);
                if (st.find(req) != st.end()) {
                    vector<int> temp = {v[i], v[j], req};
                    sort(temp.begin(), temp.end());
                    stv.insert(temp);
                }
            }
            st.insert(v[i]);
        }

        ans.assign(stv.begin(), stv.end());
        return ans;
    }
};
