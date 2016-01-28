/*
 * Author: Zili Wang
 * Date: 22nd Jan 2016
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * current_node = head;
        ListNode * anchor_node = nullptr;
        while (current_node) {
            anchor_node = current_node;
            while (anchor_node->next) { // still has the next node
                if (anchor_node->val == anchor_node->next->val) {
                    anchor_node = anchor_node->next;
                }
                else {
                    break;
                }
            }
            current_node->next = anchor_node->next;
            current_node = current_node->next;
        }
        return head;
    }
};
