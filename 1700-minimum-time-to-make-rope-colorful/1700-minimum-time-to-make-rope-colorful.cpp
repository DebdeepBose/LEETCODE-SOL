class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int totalTime = accumulate(neededTime.begin(), neededTime.end(), 0);
        int totalMaxTime = 0;

        for (int i = 0; i < n;) {
            int j = i;
            int maxt = 0;

            while (j < n && colors[j] == colors[i]) {
                maxt = max(maxt, neededTime[j]);
                j++;
            }

            totalMaxTime += maxt;

            i = j;
        }

        return totalTime - totalMaxTime;
    }
};
