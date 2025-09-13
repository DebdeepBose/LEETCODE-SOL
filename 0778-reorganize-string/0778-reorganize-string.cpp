class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for (auto e : s) {
            mp[e]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto e : mp) {
            pq.push({e.second, e.first});
        }

        string ans = "";

        while (pq.size() > 1) {
            auto [freq1, char1] = pq.top();
            pq.pop();

            auto [freq2, char2] = pq.top();
            pq.pop();

            ans += char1;
            ans += char2;

            freq1--;
            freq2--;

            if (freq1 > 0) {
                pq.push({freq1, char1});
            }
            if (freq2 > 0) {
                pq.push({freq2, char2});
            }
        }

        if (!pq.empty()) {
            auto [freq, chara] = pq.top();
            if (freq > 1) {
                return "";
            }
            ans += chara;
        }
        return ans;
    }
};