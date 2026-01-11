class Solution {
public:
    vector<vector<int>> subsets(vector<int>& v) {
        vector<vector<int>> ans;
        vector<int> tmp;
        gen(ans, tmp, v, v.size());
        return ans;
    }
    void gen(vector<vector<int>>& ans, vector<int>& tmp, vector<int>& v,
             int n) {
        if(n==0){
            ans.push_back(tmp);
            return;
        }

        tmp.push_back(v[n - 1]);
        gen(ans, tmp, v, n - 1);
        tmp.pop_back();
        gen(ans, tmp, v, n - 1);
    }
};