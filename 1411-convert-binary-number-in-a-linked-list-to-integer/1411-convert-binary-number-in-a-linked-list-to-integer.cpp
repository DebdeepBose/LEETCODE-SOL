/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string s = "";
        while (head != nullptr) {
            int x = head->val;
            string t = to_string(x);
            s += t;
            head = head->next;
        }
        int d = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                d += pow(2, s.size() - i - 1);
            }
        }
        return d;
    }
};