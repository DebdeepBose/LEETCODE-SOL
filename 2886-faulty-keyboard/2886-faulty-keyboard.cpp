class Solution {
public:
    string finalString(string s) {
        deque<char> dq;
        string ans = "";
        bool flag = false;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'i') {
                
                if (i + 1 < s.size() && s[i + 1] == 'i') {
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
