class Solution {
public:
    int missingNumber(vector<int>& v) {
        int n = v.size();
        vector<int>a(n+1,-1);
        for(int i =0;i<v.size();i++){
            a[v[i]] = v[i];
        }
        for(int i =0;i<a.size();i++){
            if(a[i]==-1)
            return i;
        }
        return 0;
    }
};

