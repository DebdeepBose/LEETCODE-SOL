class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {

        int n = s.length();
        int m = t.length();

        if(n % k != 0 || m % k != 0)
            return false;
        
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;

         int len = n / k;

        //Storing substrings of s
        for(int i = 0; i < n; i += len){
            string temp = s.substr(i, len);
            mp1[temp]++;
        }

        //Storing substrings of t
        for(int i = 0; i < m; i += len){
            string temp = t.substr(i, len);
            mp2[temp]++;
        }

        return mp1 == mp2;
    }
};