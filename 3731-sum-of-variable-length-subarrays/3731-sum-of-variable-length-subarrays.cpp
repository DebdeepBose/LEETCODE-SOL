class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        partial_sum(nums.begin(),nums.end(),pre.begin());

        int s, ans = 0;

        for(int i=0;i<n;i++){
            s=max(0,i-nums[i]);
            ans+=pre[i];
            if(s-1>=0) ans-=pre[s-1];
        }

        return ans;
    }
};