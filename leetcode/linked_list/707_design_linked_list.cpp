class MyLinkedList {
private:
    struct Node {
        int value;
        Node* prev;
        Node* next;
        Node(int v) : value(v), prev(nullptr), next(nullptr) {}
    };

    Node* dummyHead; 
    Node* dummyTail; 
    int count;

public:
    MyLinkedList() {
        dummyHead = new Node(0);
        dummyTail = new Node(0);
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
        count = 0;
    }

    ~MyLinkedList() {
        Node* cur = dummyHead;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    Node* getNode(int index) {
        if (index < 0 || index > count) return nullptr;
        Node* cur = dummyHead->next;
        for (int i = 0; i < index; ++i) cur = cur->next;
        return cur;
    }

    int get(int index) {
        if (index < 0 || index >= count) return -1;
        return getNode(index)->value;
    }

    void insertBefore(Node* node, int val) {
        Node* n = new Node(val);
        Node* before = node->prev;

        n->prev      = before;
        n->next      = node;
        before->next = n;
        node->prev   = n;

        ++count;
    }

    void addAtHead(int val) {
        insertBefore(dummyHead->next, val);  
    }

    void addAtTail(int val) {
        insertBefore(dummyTail, val);      
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > count) return;
        insertBefore(getNode(index), val);    
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= count) return;
        Node* cur = getNode(index);

        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;

        delete cur;
        --count;
    }
};
