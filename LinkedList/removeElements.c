/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    if(head==NULL)
    {
        return NULL;
    }

    struct ListNode* pre=NULL;
    struct ListNode* cur=head;

    while(cur)
    {
        if(cur->val==val&&cur==head)
        {
            head=head->next;
            pre=cur;
            cur=head;
        }
        else if(cur->val==val)
        {
            struct ListNode* next = cur->next;
            free(cur);
            cur=next;
            pre->next=cur;
        } 
        else 
        {
            pre=cur;
            cur=cur->next;            
        }      
    }
    return head;
}