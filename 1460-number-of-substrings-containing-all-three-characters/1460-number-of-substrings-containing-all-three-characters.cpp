#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int subcount = 0;
        vector<int> mp(3, -1);

        for (int i = 0; i < n; i++) {
            mp[s[i] - 'a'] = i;
            if (mp[0] != -1 && mp[1] != -1 && mp[2] != -1) {
                subcount += min({mp[0], mp[1], mp[2]}) + 1;
            }
        }
        return subcount;
    }
};
