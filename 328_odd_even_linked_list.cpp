/*
 Author: ZILI WANG
 Date: 20th Jan 2016
 Remarks: have not finished yet
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
        ListNode * last_odd_node = current_node; // pointing to the last node with odd index number
        unsigned int current_index = 1;
        unsigned int last_odd_index = current_index;

        while (current_node) {
            if (index % 2 == 1) { // odd index
                last_odd_node = current_node;
                last_odd_index = current_index;
            }
            current_node = head->next;
            ++ index;
        }
    }
};
