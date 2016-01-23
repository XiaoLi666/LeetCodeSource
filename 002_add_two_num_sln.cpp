/*
 Author: ZILI WANG
 Date: 11th Dec 2015
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head_ptr = new ListNode(0);
        ListNode * cur_ptr = head_ptr;

        while (l1 || l2) {

            // Calculate the updated value
            int v = 0;
            if (l1) {
                v += l1->val;
            }
            if (l2) {
                v += l2->val;
            }
            v += cur_ptr->val;

            int new_value = v%10;
            int new_carry = v/10;

            cur_ptr->val = new_value;
            if (new_carry > 0) {
                cur_ptr->next = new ListNode(new_carry);
            }

            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }

            if (new_carry == 0 && (l1 || l2)) {
                cur_ptr->next = new ListNode(0);
            }
            cur_ptr = cur_ptr->next;
        }
        return head_ptr;
    }
};
