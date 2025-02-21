class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
      long long ans = 0, totalDays = pizzas.size()/4, oddDays = (totalDays + 1)/2;
    sort(pizzas.begin(), pizzas.end(), greater<int>());
    for(int i = 0, day = 1; day <= totalDays; ++i, ++day){
        if(day > oddDays) ++i;        //skip the largest, if we are pickking for the even days
        ans += (long long)pizzas[i];
    }
    return ans;  
    }
};