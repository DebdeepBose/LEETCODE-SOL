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
    ListNode* addTwoNumbers(ListNode* ln1, ListNode* ln2) {
        string s1 = "", s2 = "";
        for (ListNode* cur = ln1; cur; cur = cur->next) {
            s1.push_back(cur->val + '0');
        }

        for (ListNode* cur = ln2; cur; cur = cur->next) {
            s2.push_back(cur->val + '0');
        }
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int carry = 0;
        string s3 = "";
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += s1[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += s2[j] - '0';
                j--;
            }
            s3.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        reverse(s3.begin(), s3.end());
        if (s3.size() > max(s1.size(), s2.size())) {
            ListNode* dummy = new ListNode(s3[0] - '0');
            if (s1.size() > s2.size()) {
                dummy->next = ln1;
                ListNode* cur = ln1;
                int k = 1;

                while (cur) {
                    cur->val = s3[k] - '0';
                    cur = cur->next;
                    k++;
                }

            } else {
                dummy->next = ln2;
                ListNode* cur = ln2;
                int k = 1;

                while (cur) {
                    cur->val = s3[k] - '0';
                    cur = cur->next;
                    k++;
                }
            }

            return dummy;
        }
        ListNode* head;

        if (s1.size() > s2.size()) {
            head = ln1;
        } else {
            head = ln2;
        }
        ListNode* cur = head;
        int k = 0;
        while (cur) {
            cur->val = s3[k] - '0';
            cur = cur->next;
            k++;
        }

        return head;
    }
};
