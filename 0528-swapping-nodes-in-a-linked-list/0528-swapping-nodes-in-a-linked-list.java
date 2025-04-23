class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }

        int c = k;
        ListNode value = head;
        while (k > 1 && value.next != null) {
            value = value.next;
            k--;
        }

        ListNode prev = null;
        ListNode temp = head;
        while (temp != null) {
            ListNode nxt = temp.next;
            temp.next = prev;
            prev = temp;
            temp = nxt;
        }

        k = c;
        ListNode backValue = prev;
        while (k > 1 && backValue.next != null) {
            backValue = backValue.next;
            k--;
        }

        int a = value.val;
        int b = backValue.val;
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        value.val = a;
        backValue.val = b;

        ListNode newPrev = null;
        ListNode curr = prev;
        while (curr != null) {
            ListNode nxt = curr.next;
            curr.next = newPrev;
            newPrev = curr;
            curr = nxt;
        }

        return newPrev;
    }
}
