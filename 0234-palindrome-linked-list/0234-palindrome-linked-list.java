class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode slowPointer = head;
        ListNode fastPointer = head;

        while (fastPointer != null && fastPointer.next != null) {
            fastPointer = fastPointer.next.next;
            slowPointer = slowPointer.next;
        }

        ListNode previousNode = null;

        while (slowPointer != null) {
            ListNode nextNode = slowPointer.next;
            slowPointer.next = previousNode;
            previousNode = slowPointer;
            slowPointer = nextNode;
        }

        ListNode leftPointer = head;
        ListNode rightPointer = previousNode;
        
        while (rightPointer != null) {
            if (leftPointer.val != rightPointer.val) {
                return false;
            }
            leftPointer = leftPointer.next;
            rightPointer = rightPointer.next;
        }
        
        return true;
    }
}
