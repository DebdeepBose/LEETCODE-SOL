class Solution {
public:
    void gen(vector<int>& v, int k, vector<vector<int>>& ans, vector<int>& tmp, int start) {
        if (k == 0) {
            ans.push_back(tmp);
            return;
        }
        if (k < 0) {
            return;
        }

        for (int i = start; i < v.size(); i++) {
           
            if (i > start && v[i] == v[i-1]) {
                continue;
            }

            tmp.push_back(v[i]);
            gen(v, k - v[i], ans, tmp, i + 1); 
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& v, int k) {
        sort(v.begin(), v.end()); 
        vector<vector<int>> ans;
        vector<int> tmp;
        gen(v, k, ans, tmp, 0);
        return ans;
    }
};
