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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;

        while(curA)
        {
            curA = curA->next;
            lenA++;
        }
        while(curB)
        {
            curB = curB->next;
            lenB++;
        }
        curA = headA;
        curB = headB;
        //假设A为较长的链表
        if (lenA < lenB)
        {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        int gap = lenA - lenB;
        while(gap)
        {
            curA = curA->next;
            gap--;
        }
        
        while(curA)
        {
            if (curA == curB)
            {
                return curA;
            }
            else
            {
                curA = curA->next;
                curB = curB->next;
            }
        }
        return nullptr;
    }
};