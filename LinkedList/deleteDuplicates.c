/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL)
    {
        return NULL;
    }
    if(head->next == NULL)
    {
        return head;
    }
    struct ListNode* pre = head;
    struct ListNode* cur = head->next;

    while(cur)
    {
        if (pre->val != cur->val)
        {
            pre = cur;
            cur = cur->next;
        }
        else
        {                        
            cur = cur->next;
            free(pre->next);
            pre->next = cur;      
        }
    }

    return head;
}