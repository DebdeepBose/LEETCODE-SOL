class Solution {
public:
    vector<int> findClosestElements(vector<int>& v, int k, int x) {
        list<int> ans(v.begin(), v.end());
        
        while (ans.size() > k) {
            if (abs(ans.front() - x) > abs(ans.back() - x)) {
                ans.pop_front();
            } else {
                ans.pop_back();
            }
        }
        
        return vector<int>(ans.begin(), ans.end());
    }
};
