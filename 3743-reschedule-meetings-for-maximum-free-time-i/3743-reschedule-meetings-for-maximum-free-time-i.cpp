class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeTime;

        int prevEnd = 0;
        for (int i = 0; i < n; i++) {
            freeTime.push_back(startTime[i] - prevEnd);
            prevEnd = endTime[i];
        }
    
        freeTime.push_back(eventTime - endTime.back());

        int maxFree = 0, currentFree = 0, c = 0;
        int i = 0, j = 0;
        while (j < freeTime.size()) {
            currentFree += freeTime[j];
            c++;

            if (c > k + 1) {
                currentFree -= freeTime[i];
                i++;
                c--;
            }

            maxFree = max(maxFree, currentFree);
            j++;
        }

        return maxFree;
    }
};
