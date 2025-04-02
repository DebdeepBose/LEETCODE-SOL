class Solution {
public:
    bool check(vector<int>& v) {
        int n = v.size();
        int c= 0;

        for(int i=0;i<n-1;i++){
            if(v[i]>v[i+1]){
                c++;
            }
        }

        if(v[0]<v.back()){
            c++;
        }

    if(c<=1){
        return true;
    }
    
    return false;
    }
};