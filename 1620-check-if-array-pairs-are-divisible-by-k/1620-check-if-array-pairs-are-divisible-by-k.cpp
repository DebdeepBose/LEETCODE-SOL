class Solution {
public:
    bool canArrange(vector<int>& v, int k) {
        vector<int> mp(k, 0);
        for (int e : v) {
            int rem = e % k;
            if (rem < 0) {
                rem += k;
            }
            mp[rem]++;
        } 
        if (mp[0] % 2 != 0) {
            return false;
        }
        for (int i = 1; i <= k / 2; i++) {
            if (mp[i] != mp[k - i]) {
                return false;
            }
        }
        
        return true;
    }
};
