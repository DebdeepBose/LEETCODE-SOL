class Solution {
public:
    int numSpecialEquivGroups(vector<string>& v) {
        int n = v.size();
        unordered_set<string> st;
        for(int i = 0;i<n;i++)
        {
            string even = "",odd = "";
            for(int j = 0;j<v[i].size();j++)
            {
                if(j%2){ 
                    odd+=v[i][j];
                    }
                else {even+=v[i][j];}
            }
            sort(even.begin(),even.end());
            sort(odd.begin(),odd.end());
            st.insert(even+odd);
        }
        return st.size();
        
    }
};