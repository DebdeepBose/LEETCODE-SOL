class Solution {
public:
    double gain(int pass,int total){
        double ans=double((((double)pass+1)/(total+1))-((double)pass/total));
        return ans;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        
        priority_queue<pair<double,pair<int,int>>>pq;
        for(auto it:classes){
            pq.push({gain(it[0],it[1]),{it[0],it[1]}});
        }

        while(extraStudents>0){
            auto it=pq.top();
            pq.pop();
            double currmx=it.first;
            int p=it.second.first;
            int t=it.second.second;
            pq.push({gain(p+1,t+1),{p+1,t+1}}); // now pushing new gain in heap by assigning 1 student
            extraStudents--;
        }
        double sum=0.0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            sum+=((double)it.second.first/(double)it.second.second);
        }
        return sum/n;
    }
};