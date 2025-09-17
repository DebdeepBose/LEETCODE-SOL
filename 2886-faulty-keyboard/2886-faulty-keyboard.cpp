class Solution {
public:
    // Lazy-Reversal Pattern
    string finalString(string s) {
        int n = s.size();
        deque<char> dq;
        string ans = "";
        bool flag = false;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'i') {
                if (i + 1 < n && s[i + 1] == 'i') {
                    i++;
                    continue;
                }
                flag = !flag;
                continue;
            }

            if (!flag)
                dq.push_back(s[i]);
            else
                dq.push_front(s[i]);
        }

        if (flag) {
            while (!dq.empty()) {
                ans += dq.back();
                dq.pop_back();
            }
        } else {
            while (!dq.empty()) {
                ans += dq.front();
                dq.pop_front();
            }
        }

        return ans;
    }
};
