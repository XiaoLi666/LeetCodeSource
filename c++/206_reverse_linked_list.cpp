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
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode * current_node = head->next;
        ListNode * previous_node = head;
        ListNode * tmp_node = nullptr;
        while (current_node != nullptr) {
            tmp_node = current_node->next;
            current_node->next = previous_node;
            previous_node = current_node;
            current_node = tmp_node;
        }
        head->next = nullptr; // this is important, otherwise, cannot fetch the corrent sequence
        return previous_node;
    }
};
