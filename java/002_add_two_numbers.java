/*
 * Author: Zili Wang
 * Date: 28th Jan 2016
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
        ListNode newListHead = new ListNode(0);
        ListNode curListHead = newListHead;
        int carry = 0;
        
        while (l1 != null && l2 != null) {
            int result = l1.val + l2.val + carry;
            carry = result / 10;
            result %= 10;
            ListNode newNode = new ListNode(result);
            curListHead.next = newNode;
            curListHead = newNode;
            
            l1 = l1.next;
            l2 = l2.next;
        }
        
        while (l1 != null) {
            int result = l1.val + carry;
            carry = result / 10;
            result %= 10;
            ListNode newNode = new ListNode(result);
            curListHead.next = newNode;
            curListHead = newNode;
            
            l1 = l1.next;
        }
        
        while (l2 != null) {
            int result = l2.val + carry;
            carry = result / 10;
            result %= 10;
            ListNode newNode = new ListNode(result);
            curListHead.next = newNode;
            curListHead = newNode;
            
            l2 = l2.next;
        }
        
        if (carry == 1) {
            ListNode newNode = new ListNode(1);
            curListHead.next = newNode;
            curListHead = newNode;
        }
        
        newListHead = newListHead.next;
        return newListHead;
    }
}
