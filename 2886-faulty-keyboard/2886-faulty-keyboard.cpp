class Solution {
public:
    string finalString(string s) {

        //Remember this is a pattern : Its called Lazy-Reversal

        deque<char> dq;
        string ans = "";
        bool flag = false;
        for (auto e : s) {
            if (e == 'i') {
                flag = !flag;
            }

            if (!flag) {
                dq.push_back(e);
            } else {
                dq.push_front(e);
            }
        }

        if (flag) {
            while (!dq.empty()) {
                if (dq.back() != 'i') {
                    ans += dq.back();
                }
                dq.pop_back();
            }
        } else {
            while (!dq.empty()) {
                if (dq.front() != 'i') {
                    ans += dq.front();
                }
                dq.pop_front();
            }
        }

        return ans;
    }
};