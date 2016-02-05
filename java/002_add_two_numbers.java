/*
 * Author: Zili Wang
 * Date: 5th Feb 2016
 */

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null && l2 == null) {
            return null;
        }
        else if (l1 == null) {
            return l2;
        }
        else if (l2 == null) {
            return l1;
        }
        
        // Otherwise, both l1 and l2 are valid
        int carry = 0;
        int result = 0;
        ListNode headNode = null;
        ListNode currNode = headNode;
        while (l1 != null && l2 != null) {
            result = l1.val + l2.val + carry;
            carry = result/10;
            result = result%10;
            
            // create a new node here:
            ListNode newNode = new ListNode(result);
            
            if (headNode == null) {
                headNode = newNode;
                currNode = headNode;
            }
            else {
                currNode.next = newNode;
                currNode = newNode;
            }
            
            l1 = l1.next;
            l2 = l2.next;
        }
        
        // both or one of the list is null
        ListNode validList = null;
        
        if (l1 != null) {
            validList = l1;
        }
        else if (l2 != null) {
            validList = l2;
        }
        
        while (validList != null) {
            result = validList.val + carry;
            carry = result/10;
            result = result%10;
            
            ListNode newNode = new ListNode(result);
            currNode.next = newNode;
            currNode = newNode;
            
            validList = validList.next;
        }
        
        if (carry == 1) {
            ListNode newNode = new ListNode(1);
            currNode.next = newNode;
            currNode = newNode;
        }
        
        return headNode;
    }
}
