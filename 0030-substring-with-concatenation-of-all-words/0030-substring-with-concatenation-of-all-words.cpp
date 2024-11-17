class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& v) {
        unordered_map<string, int> mp;
        for (auto e : v) {
            mp[e]++;
        }
        vector<int> ans;
        int slen = s.length(), m = v[0].length(), n = v.size();
        for (int i = 0; i < m; i++) { 
            unordered_map<string, int> seen;
            int left = i, vlen = 0;
            for (int j = left; j + m <= slen; j += m) { 
                string tmp = s.substr(j, m);  
                if (!(mp.count(tmp))) {
                    seen.clear();
                    vlen = 0;
                    left = j + m;
                } else {
                    seen[tmp]++;
                    vlen++;
                    if (seen[tmp] > mp[tmp]) {
                        while (seen[tmp] > mp[tmp]) {
                            string tmp2 = s.substr(left, m);
                            seen[tmp2]--;
                            vlen--;
                            left += m;
                        }
                    }
                }
                if (vlen == n) {
                    ans.push_back(left);
                    seen[s.substr(left, m)]--;
                    vlen--;
                    left += m;
                }
            }
        }
        return ans;
    }
};
