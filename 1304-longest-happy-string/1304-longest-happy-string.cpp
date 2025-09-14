class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) {
            pq.push({a, 'a'});
        }
        if (b > 0) {
            pq.push({b, 'b'});
        }
        if (c > 0) {
            pq.push({c, 'c'});
        }

        string s = "";

        while (!pq.empty()) {
            auto [f1, ch1] = pq.top();
            pq.pop();

            if (s.size() >= 2 && s.back() == ch1 && s[s.size() - 2] == ch1) {
                if (pq.empty()) {
                    break;
                }

                auto [f2, ch2] = pq.top();
                pq.pop();

                s += ch2;
                if (f2-- > 1) {
                    pq.push({f2, ch2});
                }

                pq.push({f1, ch1});
            } else {
                int use = min(2, f1);
                s += string(use, ch1);
                f1 -= use;
                if (f1 > 0) {
                    pq.push({f1, ch1});
                }
            }
        }

        return s;
    }
};
