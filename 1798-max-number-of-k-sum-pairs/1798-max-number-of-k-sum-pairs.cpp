class Solution {
public:
    int maxOperations(vector<int>& v, int k) {
        unordered_map<int, int> mp;
        int c = 0;

        for (int e : v) {
            int req = k - e;
            if (mp[req] > 0) {
                c++;
                mp[req]--;
            } else {
                mp[e]++;
            }
        }
        return c;
    }
};
