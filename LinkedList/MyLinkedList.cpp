class MyLinkedList {
public:
    struct LinkedNode
    {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val),next(nullptr)
        {}
    };
    /** Initialize your data structure here. */
    MyLinkedList() {
        _size = 0;
        dummyHead = new LinkedNode(0);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= _size)
        {
            return -1;
        }
        LinkedNode* cur = dummyHead;
        while(cur->next != nullptr && index >= 0)
        {
            cur = cur->next;
            index--;
        }
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkedNode* node = new LinkedNode(val);
        LinkedNode* tmp = dummyHead->next;
        dummyHead->next = node;
        node->next = tmp;
        _size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkedNode* cur = dummyHead;
        LinkedNode* node = new LinkedNode(val);
        while(cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = node;
        node->next = nullptr;
        _size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0)
        {
            addAtHead(val);
        }
        else if (index == _size)
        {
            addAtTail(val);
        }
        else
        {
            LinkedNode* cur = dummyHead->next;
            LinkedNode* pre = dummyHead;
            while(cur->next != nullptr && index > 0)
            {
                pre = cur;
                cur = cur->next;            
                index--;
            }
            LinkedNode* node = new LinkedNode(val);
            node->next = cur;
            pre->next = node;
            _size++;
        }
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= _size)
        {
            return;
        }
        LinkedNode* cur = dummyHead->next;
        LinkedNode* pre = dummyHead;
        while(cur->next != nullptr && index > 0)
        {
            pre = cur;
            cur = cur->next;            
            index--;
        }
        pre->next = cur->next;
        delete cur;
        _size--;
    }
    int _size;
    LinkedNode* dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */