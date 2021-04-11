/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        return head;
    }

    struct ListNode* cur = head;
    struct ListNode* pre = NULL;
    struct ListNode* node = cur;

    while(cur)
    {
        node = cur;
        cur = cur->next;
        node->next = pre;
        pre = node;
    }

    return pre;
}