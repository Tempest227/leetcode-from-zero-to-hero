/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* first = dummyHead;
    struct ListNode* second = head;
    struct ListNode* third = head->next;
    dummyHead->next = head;

    while(third)
    {
        struct ListNode* next = third->next;
        second->next = next;
        third->next = second;
        first->next = third;

        first = first->next->next;
        if (first != NULL)
        {
            second = first->next;
        }
        else
        {
            break;
        }
        if (second != NULL)
        {
            third = second->next;
        }
        else
        {
            break;
        } 
    }
    return dummyHead->next;
} 