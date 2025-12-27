class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> freeRoom;
        for (int i = 0; i < n; i++) freeRoom.push(i);

        priority_queue<pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>> used;

        vector<long long> cnt(n, 0);

        for (auto &m : meetings) {
            long long s = m[0], dur = m[1] - m[0];

            while (!used.empty() && used.top().first <= s) {
                freeRoom.push(used.top().second);
                used.pop();
            }

            int room;
            long long endT;

            if (!freeRoom.empty()) {
                room = freeRoom.top(); freeRoom.pop();
                endT = s + dur;
            } else {
                auto top = used.top(); used.pop();
                room = top.second;
                endT = top.first + dur;
            }

            cnt[room]++;
            used.push({endT, room});
        }

        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};