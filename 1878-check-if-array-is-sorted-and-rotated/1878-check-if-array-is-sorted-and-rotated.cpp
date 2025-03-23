class Solution {
public:
    bool check(vector<int>& v) {
        int c = 0;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] < v[i-1]) {
                c++;
            }
        }

        if(c==0){
            return true;
        }


        if (v.back() <= v[0] && c == 1) {
            return true;
        } else {
            return false;
        }
    }
};