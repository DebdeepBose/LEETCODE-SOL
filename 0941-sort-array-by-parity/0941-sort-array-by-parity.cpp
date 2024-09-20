class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& v) {
        vector<int> even;
        vector<int> odd;
        for (auto e : v) {
            if (e % 2 == 0) {
                even.push_back(e);
            } else {
                odd.push_back(e);
            }
        }
        v.clear();
        for(auto e : even)
        {
            v.push_back(e);
        }
         for(auto e : odd)
        {
            v.push_back(e);
        }
        return v;
    }
};