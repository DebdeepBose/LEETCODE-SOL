/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) {
            return head;
        }

        //Since we are already on the head so lenght is 1
        int listLength = 1;
        ListNode tempNode = head;

        //Pointer to find tail
        ListNode tail = head;

        //Find the last node or tail in order to connect it to head
        //Also find the length of the list
        while (tail.next != null) {
            listLength++;
            tail = tail.next;
        }

        //In case k > listLength
        k = k % listLength;

        //Make it circular
        tail.next = head;

        //Calculate steps to move head
        int stepsToMove = listLength - k;

        //Move to the last node of rotated list 
        ListNode prevHead = head;
        for (int i = 1; i < stepsToMove; i++) {
            prevHead = prevHead.next;
        }

        //Make the next node the new head
        ListNode newHead = prevHead.next;

        //Convert back to a singly Linked list
        prevHead.next = null;

        //Return new head
        return newHead;

    }
}