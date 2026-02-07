class Solution {
public:
    bool checkString(string s) {
        int bpos = s.find('b');
        for(int i=bpos;i<s.size();i++){
            if(s[i]=='a'){
                return false;
            }
        }
        return true;
    }
};