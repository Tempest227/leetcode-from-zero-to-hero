/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    if(head==NULL)
    {
        return NULL;
    }

    struct ListNode* t=head;
    int len=0;
    while(t)
    {
        t=t->next;
        len++;
    }
    if(k>len)
    {
        return NULL;
    }

    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(k--)
    {
        if(fast!=NULL)
        {
            fast = fast->next;
        }        
    }
    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}