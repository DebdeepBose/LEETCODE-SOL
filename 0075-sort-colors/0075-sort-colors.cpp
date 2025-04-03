class Solution {
public:
    void sortColors(vector<int>& v) {
        int c0=0,c1=0,c2=0,n=v.size();
        vector<int> sorted;
        for(int i=0;i<n;i++)
        {
            if(v[i]==0)
            {
                c0++;
            }
            else if(v[i]==1)
            {
                c1++;
            }
            else if(v[i]==2)
            {
                c2++;
            }
        }
        
        while(c0--)
        {
            sorted.push_back(0);
        }
        while(c1--)
        {
            sorted.push_back(1);
        }
        while(c2--)
        {
            sorted.push_back(2);
        }

        v.assign(sorted.begin(),sorted.end());
    }
};