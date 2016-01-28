/*
 * Author: Zili Wang
 * Date: 26th Jan 2016
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
    ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return nullptr;
        
        unsigned int lengthA = 0;
        unsigned int lengthB = 0;
        ListNode * curNodeA = headA;
        ListNode * preNodeA = nullptr;
        ListNode * curNodeB = headB;
        ListNode * preNodeB = nullptr;
        
        while (curNodeA) {
            ++lengthA;
            preNodeA = curNodeA;
            curNodeA = curNodeA->next;
        }
        
        while (curNodeB) {
            ++lengthB;
            preNodeB = curNodeB;
            curNodeB = curNodeB->next;
        }
        
        if (preNodeA->val != preNodeB->val) {
            return nullptr;
        }
        
        curNodeA = headA;
        curNodeB = headB;
        int comLength = 0;
        int del = 0;
        
        if (lengthA > lengthB) {
            comLength = lengthB;
            del = lengthA - lengthB;
            while (del > 0) {
                curNodeA = curNodeA->next;
                --del;
            }
        }
        else if (lengthB > lengthA) {
            comLength = lengthA;
            del = lengthB - lengthA;
            while (del > 0) {
                curNodeB = curNodeB->next;
                --del;
            }
        }
        else { // lengthA == lengthB
            comLength = lengthA;
        }
        
        while (comLength > 0) {
            if (curNodeA->val == curNodeB->val) {
                return curNodeA; // found! Can return curNodeB also
            }
            curNodeA = curNodeA->next;
            curNodeB = curNodeB->next;
            --comLength;
        }
        
        return nullptr;
    }
};
