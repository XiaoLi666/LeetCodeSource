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
    ListNode* oddEvenList(ListNode* head) {
        ListNode * current_node = head;
        ListNode * last_odd_index_node = current_node;
        ListNode * last_even_index_node = nullptr;
        unsigned int current_index = 1; // this is necessary to indicate the odd/even index

        while (current_node) {
            if (current_index % 2 == 1 && last_even_index_node) { // odd index, need to move forward
                last_even_index_node->next = current_node->next;
                current_node->next = last_odd_index_node->next;
                last_odd_index_node->next = current_node;
                last_odd_index_node = current_node;
                current_node = last_even_index_node;
            }
            else { // even index, keep still
                last_even_index_node = current_node;
            }
            current_node = current_node->next;
            ++current_index;
        }
        return head;
    }
};
