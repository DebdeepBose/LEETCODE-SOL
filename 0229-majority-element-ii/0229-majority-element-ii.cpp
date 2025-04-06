class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int n = v.size();
        unordered_map<int,int> mp;
        for(auto e : v){
            mp[e]++;
        }
        vector<int> ans;
        for(auto e : mp){
            if(e.second>floor(n/3)){
                ans.push_back(e.first);
            }
        }

        return ans;
    }
};