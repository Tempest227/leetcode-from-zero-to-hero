/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    
    struct ListNode* tailA = headA;
    struct ListNode* tailB = headB;

    int lenA = 0;
    int lenB = 0;
    //1.判断是否有交点
    while(tailA)
    {
        tailA = tailA->next;
        lenA++;
    }

    while(tailB)
    {
        tailB = tailB->next;
        lenB++;
    }

    if (tailA != tailB)
    {
        return NULL;
    }
    //2.判断交点位置
    struct ListNode* longList = headA;
    struct ListNode* shortList = headB;
    int gap = 0;

    if (lenA < lenB)
    {
        longList = headB;
        shortList = headA;
        gap = lenB - lenA;
    }
    else
    {
        gap = lenA - lenB;
    }

    while(gap--)
    {
        longList = longList->next;
    }

    while(longList != shortList)
    {
        longList = longList->next;
        shortList = shortList->next;
    }

    return longList;
}