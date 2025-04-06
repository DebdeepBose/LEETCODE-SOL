class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        int n = v.size();
        int psum = 0;
        unordered_map<int, int> mp;
        int c = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            psum += v[i];
            int ex = psum - k;
            c += mp[ex];
            mp[psum]++;
        }
        return c;
    }
};