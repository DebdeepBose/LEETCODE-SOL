class Solution {
public:
    string frequencySort(string s) {

        if (s.empty()) {
            return "";
        }

        priority_queue<pair<int, char>> pq;
        string ans = "";
        unordered_map<char, int> mp;

        for (auto e : s) {
            mp[e]++;
        }

        for (auto e : mp) {
            pq.push({e.second, e.first});
        }

        while (!pq.empty()) {
            int freq = pq.top().first;
            char ch = pq.top().second;
            ans += string(freq, ch);
            pq.pop();
        }
        return ans;
    }
};