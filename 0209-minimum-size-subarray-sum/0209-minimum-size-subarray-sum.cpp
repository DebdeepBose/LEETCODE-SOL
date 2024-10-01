class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,ans=0,maxi=INT_MAX;
        while(r<n)
        {
            ans+=nums[r];
            while(ans>=target)
            {
                ans-=nums[l];
                maxi=min(r-l+1,maxi);
                l++;
            }
            r++;
        }
        return maxi==INT_MAX ? 0:maxi;
        
    }
};