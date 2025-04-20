class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& v) {
        unordered_map<int,vector<int>> mp;
        vector<vector<int>> ans;
        for(int i=0;i<v.size();i++){
            int size = v[i];
            mp[size].push_back(i);
            if(mp[size].size() == size){
                ans.push_back(mp[size]);
                mp[size].clear();
            }
        }
        return ans;
    }
};