class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int n = v.size();
        unordered_map<int,int> mp;
        for(auto e : v){
            mp[e]++;
        }
        unordered_set<int> st;
        for(auto e : mp){
            if(e.second>floor(n/3)){
                st.insert(e.first);
            }
        }

        vector<int> ans;
        ans.assign(st.begin(),st.end());

        return ans;
    }
};