class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        
        set<int> st(v.begin(),v.end());
        v.clear();
        v.assign(st.begin(),st.end());

        return v.size();

    }
};