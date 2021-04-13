/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int total = 0;
    int next1 = 0;
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = result;

    while(l1 != NULL && l2 != NULL)
    {
        total = l1->val + l2->val + next1;
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur->next->val = total % 10;
        next1 = total / 10;
        l1 = l1->next;
        l2 = l2->next;
        cur = cur->next;
        cur->next = NULL;//不置空，过不了
    }

    while(l1)
    {
        total = l1->val + next1;
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur->next->val = total % 10;
        next1 = total / 10;
        l1 = l1->next;
        cur = cur->next;
        cur->next = NULL;
    }
    while(l2)
    {
        total = l2->val + next1;
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur->next->val = total % 10;
        next1 = total / 10;
        l2 = l2->next;
        cur = cur->next;
        cur->next = NULL;
    }
    if(next1 != 0)
    {
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur->next->val = next1;
        cur->next->next = NULL;
    }

    return result->next;
}