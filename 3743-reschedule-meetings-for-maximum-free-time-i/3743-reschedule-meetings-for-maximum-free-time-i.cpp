class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        vector<int> freeTime;
        int end = 0;
        for (int i = 0; i < startTime.size(); i++) {
            int gap = startTime[i] - end;
            end = endTime[i];
            freeTime.push_back(gap);
        }
        freeTime.push_back(eventTime - endTime.back());

        int i = 0;
        int j = 0;
        int maxFree = 0;
        int free = 0;
        int c = 0;
        while (j < freeTime.size()) {
            if (c == k + 1) {
                free -= freeTime[i];
                i++;
                c--;
            }
            c++;
            free += freeTime[j];
            j++;
            maxFree = max(maxFree, free);
        }

        return maxFree;
    }
};