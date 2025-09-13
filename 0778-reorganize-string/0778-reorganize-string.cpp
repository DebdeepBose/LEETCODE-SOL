class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        if (n == 1) {
            return s;
        }

        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        int maxCount = INT_MIN;
        int minCount = INT_MAX;
        int keys = mp.size();

        for (auto e : mp) {
            maxCount = max(maxCount, e.second);
            minCount = min(minCount, e.second);
        }

        if (maxCount - minCount > 1) {
            if (maxCount > keys) {
                return "";
            }
        }

        priority_queue<pair<int, char>> maxHeap;
        for (auto p : mp) {
            maxHeap.push({p.second, p.first});
        }

        queue<pair<int, char>> waitHeap;

        string result = "";
        while (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();

            result += ch;
            count--;

            waitHeap.push({count, ch});

            if (waitHeap.size() > 1) {
                auto [c2, ch2] = waitHeap.front();
                waitHeap.pop();
                if (c2 > 0) {
                    maxHeap.push({c2, ch2});
                }
            }
        }


        return (result.size() == n) ? result : "";
    }
};
