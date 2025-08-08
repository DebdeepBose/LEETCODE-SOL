class Solution {
public:
    void findSubsets(vector<int>& v, int i, vector<vector<int>>& ans,
                     vector<int> tmp) {

        //base case
        if(i==v.size()){
            ans.push_back(tmp);
            return;
        }

        // take
        tmp.push_back(v[i]);
        findSubsets(v, i + 1, ans, tmp);

        //skip
        tmp.pop_back();
        findSubsets(v, i + 1, ans, tmp);
    }
    vector<vector<int>> subsets(vector<int>& v) {
        vector<vector<int>> ans;
        vector<int> tmp;
        findSubsets(v, 0, ans, tmp);
        return ans;
    }
};