class Solution {
    public boolean isPalindrome(ListNode head) {

        if(head == null || head.next == null){
            return true;
        }
        // Initialize two pointers, slowPointer and fastPointer, both starting at the head of the list.
        ListNode slowPointer = head;
        ListNode fastPointer = head;

        // Move the fastPointer two steps at a time, and slowPointer one step at a time.
        // The idea is that when fastPointer reaches the end of the list, slowPointer will be at the middle.
        while (fastPointer != null && fastPointer.next != null) {
            fastPointer = fastPointer.next.next;
            slowPointer = slowPointer.next;
        }

        // At this point, slowPointer is at the middle of the list. 
        // We now need to reverse the second half of the list starting from slowPointer.
        ListNode previousNode = null;
        while (slowPointer != null) {
            // Save the next node in a temporary variable to avoid losing the reference.
            ListNode nextNode = slowPointer.next;
            
            // Reverse the link by pointing slowPointer to the previous node.
            slowPointer.next = previousNode;
            
            // Move previousNode and slowPointer one step forward.
            previousNode = slowPointer;
            slowPointer = nextNode;
        }

        // Now, previousNode is pointing to the head of the reversed second half of the list.
        ListNode leftPointer = head;
        ListNode rightPointer = previousNode;

        // Compare the first half of the list with the reversed second half.
        while (rightPointer != null) {
            // If the values at leftPointer and rightPointer do not match, return false.
            if (leftPointer.val != rightPointer.val) {
                return false;
            }

            // Move both pointers one step forward to continue comparing the next nodes.
            leftPointer = leftPointer.next;
            rightPointer = rightPointer.next;
        }

        // If we've compared all corresponding nodes and found no mismatches, the list is a palindrome.
        return true;
    }
}
