/*
 * Author: Zili Wang
 * Date: 25th Jan 2016
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && l2) return l2;
        else if (l1 && !l2) return l1;
        else if (!l1 && !l2) return nullptr;
        
        ListNode * curNodeL1 = l1;
        ListNode * curNodeL2 = l2;
        ListNode * mergeList = new ListNode(0);
        ListNode * curMergeNode = mergeList;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curMergeNode->next = l1;
                l1 = l1->next;
            }
            else if (l2->val < l1->val)  {
                curMergeNode->next = l2;
                l2 = l2->next;
            }
            curMergeNode = curMergeNode->next;
        }
        
        if (l1) curMergeNode->next = l1;
        if (l2) curMergeNode->next = l2;
        mergeList = mergeList->next;
        
        return mergeList;
    }
};

// Another solution, but time consuming
/*ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && l2) {
            return l2;
        }
        else if (l1 && !l2) {
            return l1;
        }
        else if (!l1 && !l2) {
            return nullptr;
        }
        
        ListNode * currentNode1 = l1;
        ListNode * currentNode2 = l2;
        
        vector<ListNode *> nodes;
        while (currentNode1) {
            nodes.push_back(currentNode1);
            currentNode1 = currentNode1->next;
        }
        while (currentNode2) {
            nodes.push_back(currentNode2);
            currentNode2 = currentNode2->next;
        }
        
        sort(nodes.begin(),nodes.end(),compare);
        
        currentNode1 = nodes[0];
        currentNode2 = currentNode1;
        for (unsigned int i = 1; i < nodes.size(); ++i) {
            currentNode1->next = nodes[i];
            currentNode1 = currentNode1->next;
        }
        
        return currentNode2;
    }
    
    static bool compare(ListNode * l, ListNode * r) {
        return l->val > r->val;
    }*/
