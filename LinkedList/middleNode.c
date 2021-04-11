/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    
    while(fast->next!=NULL&&fast->next->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast->next!=NULL)
    {
        return slow->next;
    }
    if(fast->next==NULL)
    {
        return slow;
    }
    return NULL;
}