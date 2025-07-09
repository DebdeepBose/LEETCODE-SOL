class Solution {
public:
    bool checkPerfectSq(double d){
        double sq = sqrt(d);
        return sq*sq == d;
    }
    int bulbSwitch(int n) {
        while(n>0){
            double d = n * 1.0;
            bool f = checkPerfectSq(d);
            if(f){
                return sqrt(n);
            }
        }
        return 0;
    }
};