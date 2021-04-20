/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head){
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* sortHead = head;
    struct ListNode* cur = head->next;
    sortHead->next = NULL;

    
    while(cur)
    {
        struct ListNode* next = cur->next;


        struct ListNode* p = NULL, *c = sortHead;
        while(c)
        {
            if (cur->val < c->val)
            {
                break;
            }            
            else
            {
                p = c;
                c = c->next;
            }
        }

        if (p == NULL)//头插
        {
            cur->next = c;
            sortHead = cur;
        }
        else
        {
            p->next = cur;
            cur->next = c;
        }
        
        cur = next;
    }
    return sortHead;
}