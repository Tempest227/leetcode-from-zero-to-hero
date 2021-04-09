struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL&&l2==NULL)
    {
        return NULL;
    }
    if(l1==NULL)
    {
        return l2;
    }
    if(l2==NULL)
    {
        return l1;
    }
    struct ListNode* cur=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* t = cur;
    memset(cur,0,sizeof(struct ListNode));
    while(l1!=NULL&&l2!=NULL)
    {
        if(l1->val<=l2->val)
        {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }        
    }
    while(l1!=NULL)
    {
        cur->next = l1;
        cur = cur->next;
        l1 = l1->next;
    }
    while(l2!=NULL)
    {
        cur->next = l2;
        cur = cur->next;
        l2 = l2->next;
    }
    return t->next;
}